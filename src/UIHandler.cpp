#include "UIHandler.h"
#include "string"
#include "GetADC.h"

void sliderHandler()
{
    static int dutyValue;
    static int TemperateDutyValue;

    lv_mem_buf_free_all();
    if (DataUpgrateFlag == 1)   //如果发生了数据更新, 则先为各个控件赋值
    {
        DataUpgrateFlag = 0;
        lv_arc_set_value(guider_ui.btn_1_arc_1, (ProjectData.speed/11.0f));  //设定风速滑条 参数2为将百转单位归一化到0~100
        lv_arc_set_value(guider_ui.btn_1_temperate, (ProjectData.temp - 50)/1.2f);
        lv_obj_add_state(guider_ui.btn_1_sw_1, ProjectData.switchStatus);
    }
    else    //如果没有发生数据更新,则直接读取各控件的值
    {
        // switch    on: 1   off: 0
        switchState = lv_obj_has_state(guider_ui.btn_1_sw_1, LV_STATE_CHECKED);
        // 溫度滑條
        tempsliderValue = lv_arc_get_value(guider_ui.btn_1_temperate);
        // 风速滑条(弧条)
        slider_value = lv_arc_get_value(guider_ui.btn_1_arc_1);
    }

    // 控制限制, 防止发热丝干烧
    if (slider_value <= tempsliderValue)
    {
        lv_arc_set_value(guider_ui.btn_1_temperate, slider_value);
        tempsliderValue = slider_value;
    }

    // 单位换算, 将UI控制值等价为占空比值
    TemperateDutyValue = tempsliderValue * (256 / 25);
    dutyValue = slider_value * (256 / 25);

    // 表格2内容填充
    static char TemperateBuf[4];
    if (Temp1 != 13)
    {
        snprintf(TemperateBuf, 4, "%d", Temp1);
    }
    else
    {
        snprintf(TemperateBuf, 4, "---");
    }
    // snprintf(TemperateBuf, 4, "%d", eepromValue);
    lv_label_set_text(guider_ui.btn_1_label_7, TemperateBuf);

    if (distanceFlag != 1)
    {
        lv_obj_clear_state(guider_ui.btn_1_sw_1, LV_STATE_CHECKED);
        switchState == false;
    }

    // 输出风速(配合开关状态)
    if (switchState == true)
    {
        // 表格1内容填充
        std::string power_syn = "W";
        std::string table_power_str = std::to_string(slider_value * 15 / 10 + Temp1 * 6) + power_syn;
        const char *charRes = table_power_str.data();
        lv_label_set_text(guider_ui.btn_1_label_8, charRes);

        SpeedControl(dutyValue);
        TemperateControl(tempsliderValue, tempsliderValue); // 输出指定占空比的PWM
        speechFlag = 1;
        gTemplePower = dutyValue * 15 / 10;
    }
    else
    { // 表格1内容填充
        std::string power_syn = "W";
        std::string table_power_str = std::to_string(0) + power_syn;
        const char *charRes = table_power_str.data();
        lv_label_set_text(guider_ui.btn_1_label_8, charRes);

        ledcWrite(4, 1023); // close HOT pin

        if (Temp1 >= 40)
        {
            delay(4000); // if temperate too high, delay 4s to let wind cooling it.
        }

        ledcWrite(0, 0); // 不输出PWM, 关机
                         //        digitalWrite(HOT_PIN, 1); // 关闭电热丝
        speechFlag = 0;
    }

    LEDControl(dutyValue, slider_value);
}

static void LEDControl(int dutyValue, int slider_value)
{
    //    if (slider_value <= 33)
    //    {
    //        ledcWrite(3, (0) * (256 / 25) * 2);
    //        ledcWrite(2, (0) * (256 / 25) * 2);
    //        // ledcWrite(1, (100) * (256 / 25));
    //        ledcWrite(1, ((slider_value)) * (256 / 25) * 3);
    //    }
    //    if (slider_value <= 66 && slider_value > 33)
    //    {
    //        ledcWrite(3, (0) * (256 / 25) * 2);
    //        ledcWrite(1, (0) * (256 / 25) * 2);
    //        ledcWrite(2, (slider_value - 33) * (256 / 25) * 3);
    //        // ledcWrite(2, (100) * (256 / 25));
    //    }
    //    if (slider_value <= 100 && slider_value > 66)
    //    {
    //        ledcWrite(1, (0) * (256 / 25) * 2);
    //        ledcWrite(2, (0) * (256 / 25) * 2);
    //        ledcWrite(3, (slider_value - 66) * (256 / 25) * 3);
    //        // ledcWrite(3, (100) * (256 / 25));
    //    }

    // Power control LED mode
    ledcWrite(3, ((slider_value * 15 / 10 + Temp1 * 6) / 11.7) * (256 / 25)); // LED3 set as Power LED
}

static void SpeedControl(int dutyValue)
{
    int output;
    if (dutyValue >= 95)
    {
        output = 95;
    }
    else
    {
        output = dutyValue;
    }

    if (dutyValue <= 1)
    {
        output = 1;
    }
    else
    {
        output = dutyValue;
    }

    ledcWrite(0, output); // 输出指定占空比的PWM
}

static void TemperateControl(int UITemperateValue1, int UITemperateValue2)
{
    int ActualTemperate1, ActualTemperate2;
    ActualTemperate1 = actuallyTemperate;
    ActualTemperate2 = actuallyTemperate;

    if (ActualTemperate1 < (UITemperateValue1 * 1.2 + 50) && ActualTemperate2 < (UITemperateValue2 * 1.2 + 50) && Temp1 < 170) // 控制范围设定为50度~170度
    {
        if (HotPinCounter >= HOTTIMER)
        {
            HotPinCounter = 0;
            ledcWrite(4, (100 - HOT_POWER) * (256 / 25));
        }
    }
    else
    {
        ledcWrite(4, 1023);
    }
}
