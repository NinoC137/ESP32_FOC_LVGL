#include <lvgl.h>
#include <TFT_eSPI.h>
#include <gui_guider.h>
#include "TAMC_GT911.h"
#include <events_init.h>

// 模块功能部分
#include "GetADC.h"
#include "Distance.h"
#include "UIHandler.h"
#include "Speech.h"
#include "WiFi_BLE.h"

// 掉电保存配网数据
#include "EEPROM.h"
void UserSetup();
void UISetup();

void BooterWIFIConnect();
void WIFIWrite2EEPROM();

void ModuleEnable();

static lv_disp_draw_buf_t draw_buf;     // 定义显示器变量完
static lv_color_t buf[TFT_WIDTH * 100]; // 定义刷新缓存

#define TOUCH_SDA 14
#define TOUCH_SCL 21
#define TOUCH_INT 9
#define TOUCH_RST 20
#define TOUCH_WIDTH 320
#define TOUCH_HEIGHT 240

#define DEBUG 1
#if DEBUG
#define DISTANCE_DEBUG 1
#define TEMPERARE_DEBUG 1
#define SPEECH_DEBUG 1
#define WIFI_DEBUG 1
#else
#define DISTANCE_DEBUG 1
#define TEMPERARE_DEBUG 1
#define SPEECH_DEBUG 1
#define WIFI_DEBUG 1
#endif

char ssid[30] = "ssid";         // 网络名称
char password[30] = "password"; // 网络密码 在scr_screen里面进行了修改,上电显示保存的账号密码

// 滑条变量 & 变值标志位
int slider_value; //风速
int tempsliderValue;  //温度
bool switchState;    //开关机状态
// 热电偶温度真实值
uint16_t Temp1, Temp2;
// 测距值(单位mm)
int distance;
int distanceFlag; // 距离过近报警
// 语音播报开始标志
int speechFlag;
int gTemplePower;

// wifi confirm标志位,注意要在event文件中extern进去
int wifiConfirmFlag;
int wifiConnectFlag; // 连接wifi成功标志位
int pageChangeFlag;

int HotPinCounter;

TAMC_GT911 tp = TAMC_GT911(TOUCH_SDA, TOUCH_SCL, TOUCH_INT, TOUCH_RST, TOUCH_WIDTH, TOUCH_HEIGHT); // 定义触摸
lv_ui guider_ui;                                                                                   // 定义guiguider
TFT_eSPI tft = TFT_eSPI();                                                                         // 定义显示屏

void setup()
{
  WiFi.mode(WIFI_STA);

  UserSetup(); // 各个模块的初始化

  setup_ui(&guider_ui);
  events_init(&guider_ui);

  lv_arc_set_value(guider_ui.btn_1_arc_1, 50);
  lv_arc_set_value(guider_ui.btn_1_temperate, 50);

  //灯带初始化 
  ledcSetup(1, 100, 10);
  ledcAttachPin(LED1_PIN, 1);
  ledcSetup(2, 100, 10);
  ledcAttachPin(LED2_PIN, 2);
  ledcSetup(3, 100, 10);
  ledcAttachPin(LED3_PIN, 3);

// 语音模块
#if SPEECH_DEBUG
  speech();
#endif
}

void TemperateWarning()
{
	if(Temp1 >= lv_arc_get_value(guider_ui.btn_1_temperate) * 1.2 + 50 + 10 )
	{
		lv_obj_clear_state(guider_ui.btn_1_sw_1, LV_STATE_CHECKED);
	}
}

void loop()
{
  // UI及PWM部分控制
  sliderHandler();
  // 各个模块的使能控制
  ModuleEnable();
  //Enable Temperate Warning
  TemperateWarning();
  // LVGL定时器
  lv_timer_handler();
  //WiFi及蓝牙的控制
  BLEHandler();
  WiFiHandler();
  ProjectDataUpdate();

  //热电偶加热控制
  HotPinCounter ++;

  if (wifiConnectFlag == 1 && pageChangeFlag == 1)
  {
    pageChangeFlag = 0;
    if (WiFi.status() == WL_CONNECTED)
    {
      lv_label_set_text(guider_ui.screen_1_ipAddress, WiFi.localIP().toString().c_str());
      lv_led_set_brightness(guider_ui.screen_1_WIFIState, 255);
    }
    else
    {
      lv_label_set_text(guider_ui.screen_1_ipAddress, "0.0.0.0");
      lv_led_set_brightness(guider_ui.screen_1_WIFIState, 0);
    }
  }

  delay(3);
}

void UserSetup()
{
  // PWM控制电机速度 --  PWM输出引脚GPIO27
  ledcSetup(0, 863, 10);
  ledcAttachPin(PWM_PIN, 0);

  // PWM控制LED
  ledcSetup(1, 100, 10);
  ledcAttachPin(LED1_PIN, 1);
  ledcSetup(2, 100, 10);
  ledcAttachPin(LED2_PIN, 2);
  ledcSetup(3, 100, 10);
  ledcAttachPin(LED3_PIN, 3);
  // 晶闸管控制发热丝  高电平关闭,低电平开启
  // pinMode(HOT_PIN, OUTPUT);
  // digitalWrite(HOT_PIN, 1);

  ledcSetup(4, 100, 10);
  ledcAttachPin(HOT_PIN, 4);
  ledcWrite(4, 1023);

  // 语音模块
  Serial1.begin(9600);
  Serial1.setPins(SPEECH_RX, SPEECH_TX); // rx:12 tx:13
  // 测距
  Serial.begin(115200); // 串口测距, 不使用
  // Serial.setPins(3, 1);
  pinMode(Distance_PIN, INPUT); // 数字量读取测距

  // 掉电数据保存 初始化空间
  EEPROM.begin(1024);

#if WIFI_DEBUG
  // 上电时自动读取EEPROM中的wifi帐号密码, 若存在,则进行wifi连接
  BooterWIFIConnect();
#endif

  ADCinit();

  WiFi_BLE_setUp();

  UISetup();
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();                                        // 使能写功能
  tft.setAddrWindow(area->x1, area->y1, w, h);             // 设置填充区域
  tft.pushColors((uint16_t *)&color_p->full, w * h, true); // 写入颜色缓存和缓存大小
  tft.endWrite();                                          // 关闭写功能

  lv_disp_flush_ready(disp); // 调用区域填充颜色函数
}

// lvgl的触摸读取
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;
  tp.read();
  bool touched = tp.isTouched; // tft.getTouch( &touchX, &touchY, 600 );

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    // touchtimes++;
    data->state = LV_INDEV_STATE_PR;
    /*Set the coordinates*/
    data->point.x = tp.points[0].x;
    data->point.y = tp.points[0].y;
  }
}

void UISetup()
{
  pinMode(TOUCH_RST, OUTPUT);
  digitalWrite(TOUCH_RST, 0);
  pinMode(TOUCH_INT, OUTPUT);
  digitalWrite(TOUCH_INT, 0);
  delay(1);
  digitalWrite(TOUCH_RST, 1);
  delay(8);
  pinMode(TOUCH_INT, INPUT);

  tft.init();         // 初始化
  tft.setRotation(1); // 屏幕旋转方向（横向）
  // tft.setRotation(0); // 屏幕旋转方向(纵向）

  tp.begin();        // 触摸初始化
  tp.setRotation(2); // 方向，GT911的坐标原点是跟显示屏的相反的（对角），所以这里要反相过去
  // tp.setRotation(0); // GT911方向竖屏匹配.未测试, 不确定坐标对不对
  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 100);

  // 定义屏幕
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = TFT_HEIGHT;
  disp_drv.ver_res = TFT_WIDTH;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  // 定义触摸
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
}

void BooterWIFIConnect()
{
  static char SSID[30];
  static char PWD[30];

  static int wificonnectCtr;

  for (int i = 0; i < 20; ++i)
  {
    SSID[i] = EEPROM.read(i);     // 循环读取20个字符并存入数组
    PWD[i] = EEPROM.read(i + 20); // EEPROM的前20个字节存为SSID, 25~45是Password
  }

  ProjectData.device_ID = std::string(EEPROM.readString(100).c_str());  //从100字节出读出设备ID字符串
  WiFi_Data.serverip = std::string(EEPROM.readString(150).c_str()); //从150字节处读出服务器ip地址
  WiFi_Data.serverport = EEPROM.readInt(191);

  std::string SSIDres;
  std::string PWDres;

  for (int i = 0; SSID[i] != '\0'; i++)
  {
    if (SSID[i] != ' ')
    {
      SSIDres += SSID[i];
    }
  }

  for (int i = 0; PWD[i] != '\0'; i++)
  {
    if (PWD[i] != ' ')
    {
      PWDres += PWD[i];
    }
  }

  // 成功读取出wifi信息后, 存入ssid, 开始连接wifi
  if (SSID[1] != '0' && PWD[1] != '0')
  {
    strcpy(ssid, SSIDres.c_str());
    strcpy(password, PWDres.c_str());

    WiFi_Data.WiFi_store[0].SSID = ssid;
    WiFi_Data.WiFi_store[0].PassWord = password;

    WiFi.begin(ssid, password);

    wifiConnectFlag = 1;
  }
}

void WIFIWrite2EEPROM()
{
  static char SSID[30] = {0};
  static char PWD[30] = {0};

  static int wificonnectCtr;

  // 确认键点下后,读取输入框信息,存入Flash,并且自动连接一次
  if (wifiConfirmFlag == 1)
  {
    wifiConfirmFlag = 0;

    strcpy(SSID, lv_textarea_get_text(guider_ui.screen_1_WIFIID));
    strcpy(PWD, lv_textarea_get_text(guider_ui.screen_1_WIFIPWD));

    std::string SSIDres;
    std::string PWDres;

    for (int i = 0; SSID[i] != '\0'; i++)
    {
      if (SSID[i] != ' ')
      {
        SSIDres += SSID[i];
      }
    }

    for (int i = 0; PWD[i] != '\0'; i++)
    {
      if (PWD[i] != ' ')
      {
        PWDres += PWD[i];
      }
    }

    strcpy(ssid, SSIDres.c_str());
    strcpy(password, PWDres.c_str());

    WiFi_Data.WiFi_store[0].SSID = ssid;
    WiFi_Data.WiFi_store[0].PassWord = password;

    WiFi.begin(ssid, password);

    if (WiFi.isConnected() != WL_CONNECTED || wificonnectCtr > 10) // 等待网络连接成功
    {
      delay(500);
      wificonnectCtr++;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
      lv_label_set_text(guider_ui.screen_1_ipAddress, WiFi.localIP().toString().c_str());
      lv_led_set_brightness(guider_ui.screen_1_WIFIState, 255);
    }
    else
    {
      lv_label_set_text(guider_ui.screen_1_ipAddress, "0.0.0.0");
      lv_led_set_brightness(guider_ui.screen_1_WIFIState, 0);
    }

    for (int i = 0; i < 20; ++i)
    {
      EEPROM.write(i, SSID[i]);
      EEPROM.write(i + 20, PWD[i]);
    }
    EEPROM.commit(); // 需要提交才能正真地把数据写入EEPROM
  }
}

void ModuleEnable()
{
// 热电偶测温模块
#if TEMPERARE_DEBUG
  GetTemp(&Temp1, &Temp2);
#endif
// 测距模块
#if DISTANCE_DEBUG
  distanceFlag = digitalRead(Distance_PIN);
#endif
// 语音播报
#if SPEECH_DEBUG
  static int speechCounter, state;
  if (speechFlag == 1)
  {
    if (speechCounter < 500)
    {
      speechCounter++;
    }
    else
    {
      speechCounter = 0;
      state = (state + 1) % 5;
      switch (state)
      {
      case 1:
        start1();
        speechCounter += 300;
        break;
      case 2:
        PowerSpeech(gTemplePower);
        speechCounter += 280;
        break;
      case 3:
        start2();
        speechCounter += 300;
        break;
      case 4:
        if (Temp1 != 13)
          TemperateSpeech(Temp1);
        break;

      default:
        break;
      }
    }
  }
#endif
#if WIFI_DEBUG
  // 当用户确认wifi数据之后, 将账号密码存入EEPROM之中保存
  WIFIWrite2EEPROM();
#endif
}
