#include "WiFi_BLE.h"

WiFiClient client; // ESP32设置为客户端, TCP连接服务器
const IPAddress serverIP(192, 168, 1, 1);
uint16_t serverPort = 8888;

String readTCP;

BLEUUID ServiceUUID("ab1ad444-6724-11e9-a923-1681be663d3e");                                                                                        // 服务的UUID
BLECharacteristic RX_Characteristics("ab1ad980-6724-11e9-a923-1681be663d3e", BLECharacteristic::PROPERTY_WRITE); // 接收字符串的特征值
BLEDescriptor RX_Descriptor(BLEUUID((uint16_t)0x2901));                                                                                             // 接收字符串描述符
BLECharacteristic TX_Characteristics("ab1adb06-6724-11e9-a923-1681be663d3e", BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY); // 发送字符串的特征值
BLEDescriptor TX_Descriptor(BLEUUID((uint16_t)0x2902));                                                                                             // 发送字符串描述符

std::string value;
char *BLE_json_stringRoot;
int DataUpgrateFlag;    //蓝牙唤起数据更新标志位

// WiFi信息存储对象, 存储3个WiFi信息
WiFiData WiFi_Data;
// HTTP访问域名对象
HTTPClient http;
// 心跳包对象,存储心跳包在线时间与发送计数
HeartBeatPacket HeartBeat;
// 事件日志包, 存储各类信息
ProjectDataPacket ProjectData;

//-----------网络时间获取-----------//
const char *ntpServer = "pool.ntp.org"; // 网络时间服务器
// 时区设置函数，东八区（UTC/GMT+8:00）写成8*3600
int my_timezone = 8;
long gmtOffset_sec = my_timezone * 3600;
const int daylightOffset_sec = 0; // 夏令时填写3600，否则填0
struct tm timeinfo;


void MyServerCallbacks::onConnect(BLEServer *pServer) // 开始连接函数
{
    ProjectData.blestatus = true;
}
void MyServerCallbacks::onDisconnect(BLEServer *pServer) // 断开连接函数
{
    ProjectData.blestatus = false;
    pServer->getAdvertising()->start();
}

void MyCallbacks::onWrite(BLECharacteristic *pCharacteristic) // 写方法
{
    value = pCharacteristic->getValue(); // 接收值
    if (value.empty())
    {
    }
}

void WiFi_BLE_setUp()
{
    WiFi_Data.WiFi_store[0].ipv4 = WiFi.localIP();
    WiFi_Data.WiFi_store[0].MacAddress = WiFi.macAddress().c_str();
    WiFi_Data.WiFi_store[0].devID = WiFi_Data.WiFi_store[0].MacAddress;

    size_t pos = WiFi_Data.WiFi_store[0].devID.find(":");
    while (pos != std::string::npos)
    {
        WiFi_Data.WiFi_store[0].devID.erase(pos, 1);
        pos = WiFi_Data.WiFi_store[0].devID.find(":");
    }

    if (WiFi_Data.WiFi_store[0].ipv4 != 0)
    {
        ProjectData.wifistatus = true;
    }
    else
    {
        ProjectData.wifistatus = false;
    }

    Serial.print("IPv4 address:");
    Serial.println(WiFi_Data.WiFi_store[0].ipv4);
    Serial.print("Mac:");
    Serial.printf("%s\r\n",WiFi_Data.WiFi_store[0].MacAddress.c_str());
    Serial.print("devID:");
    Serial.printf("%s\r\n",WiFi_Data.WiFi_store[0].devID.c_str());

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    BLEDevice::init(bleServer); // 初始化BLE客户端设备
    BLEServer *pServer = BLEDevice::createServer();             // BLEServer指针，创建Server
    BLEDevice::setMTU(256);
    BLEService *pService = pServer->createService(ServiceUUID); // BLEService指针，创建Service

    pServer->setCallbacks(new MyServerCallbacks()); // 设置连接和断开调用类

    pService->addCharacteristic(&RX_Characteristics);
    RX_Descriptor.setValue("RX String");
    RX_Characteristics.addDescriptor(new BLE2902());

    pService->addCharacteristic(&TX_Characteristics);
    TX_Descriptor.setValue("TX String");
    TX_Characteristics.addDescriptor(new BLE2902());

    RX_Characteristics.setCallbacks(new MyCallbacks()); // 设置回调函数
    TX_Characteristics.setCallbacks(new MyCallbacks()); // 设置回调函数

    RX_Characteristics.setValue("RX init"); // 发送信息
    TX_Characteristics.setValue("TX init"); // 发送信息

    pService->start();
    pServer->getAdvertising()->start();
}

void BLEHandler()
{
    // 蓝牙信息处理部分  --  注意手机发送端的MTU应设置为256(反正不要是默认的23字节,json包发不过去也读不回来)
    if (value.length() > 0)
    {
        BLE_json_stringRoot = (char *)value.data();
        // Serial.printf("json string: %s\r\n value: %s\r\n", json_string, value.c_str());
        cJSON *root = cJSON_Parse(BLE_json_stringRoot);
        if (root == NULL)
        {
            Serial.printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        }
        cJSON *cmd = cJSON_GetObjectItem(root, "cmd");
        Serial.printf("cmd: %d\r\n", cmd->valueint);

        switch (cmd->valueint)
        {
        case 1:
            cmd1();
            break;
        case 2:
            cmd2(root);
            break;
        case 3:
            cmd3(root);
            break;
        case 4:
            cmd4(root);
            break;
        case 5:
            cmd5(root);
            break;
        case 6:
            cmd6(root);
            break;
        case 7:
            cmd7(root);
            break;
        case 8:
            cmd8(root);
            break;
        case 9:
            cmd9(root);
            break;
        case 10:
            cmd10(root);
            break;
        case 12:
            cmd12(root);
            break;
        case 13:
            cmd13(root);
            break;
        case 14:
            cmd14(root);
            break;
        case 15:
            cmd15(root);
            break;
        case 16:
            cmd16(root);
            break;
        case 17:
            cmd17(root);
            break;
        case 19:
            cmd19(root);
            break;
        default:
            Serial.printf("error cmd!\r\n");
            TX_Characteristics.setValue("received cmd: ERROR!");
            TX_Characteristics.notify();
            break;
        }

        cJSON_Delete(root);
        value.clear();
    }
}

void WiFiHandler()
{
    // WIFI连接服务器部分
    int httpCode = http.GET();
    if (httpCode > 0) // HTTP请求无异常
    {
        if (httpCode == HTTP_CODE_OK)
        {
            String payload = http.getString(); // 读取get到的json串

            Serial.println(payload);
        }
    }
}

void ProjectDataUpdate()
{
    HeartBeatUpdate();
    updateLocalTime();
    static int cnt_dataupdate;

    if(ProjectData.runTime >= ProjectData.worktime){
        ProjectData.switchStatus = 0;
    }

    if (ProjectData.switchStatus == 1)
    {
        cnt_dataupdate++;
        if (cnt_dataupdate >= 200)  //执行一轮代码大概耗时5ms 200次计数即时间+1秒
        {
            ProjectData.runTime += 1;
            cnt_dataupdate = 0;
        }
    }
}

void HeartBeatUpdate()
{
    static int cnt_heartbeat;
    char heartbeat_str[20];
    if (HeartBeat.keepAliveTime != 0)
    {
        cnt_heartbeat++;
        if (cnt_heartbeat >= HeartBeat.keepAliveTime / 5)
        {
            HeartBeat.keepLiveCnt++;
            sprintf(heartbeat_str, "HeartBeat, cnt: %d", HeartBeat.keepLiveCnt);
            TX_Characteristics.setValue(heartbeat_str);
            TX_Characteristics.notify();

            cnt_heartbeat = 0;
        }
    }
}

void updateLocalTime()
{
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    if (!getLocalTime(&timeinfo))
    {
        ProjectData.time = std::string("Failed to obtain time");
        return;
    }
    else
    {
        char time_str[64];
        sprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
                timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
        ProjectData.time = std::string(time_str);
    }
}