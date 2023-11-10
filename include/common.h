#ifndef __COMMON_H
#define __COMMON_H

#include "WiFi_BLE.h"

#define PWM_PIN 4
#define HOT_PIN 5

#define LED1_PIN 8
#define LED2_PIN 15
#define LED3_PIN 16

#define Distance_PIN 19

#define SPEECH_RX 18
#define SPEECH_TX 17

#define STOPINPUT_PIN 9
#define KEY_PIN 4

#define HOTTIMER 100 / 5  //100Ms 加热一次 如需修改加热间隔，则修改此处的“100”至任意数值
#define HOT_POWER 5    //调节范围：1～100 100对应满功率加热

extern int distance;
extern int tempsliderValue; //温度滑条值(0~100)
extern int slider_value;    //风速滑条值(0~100)
extern bool switchState;    //开关机状态
extern uint16_t Temp1, Temp2;   //滤波后的温度TEMP1
extern uint16_t actuallyTemperate;  //实时响应的温度
extern int speechFlag;
extern int gTemplePower;
extern int distanceFlag; // 距离过近报警
extern int HotPinCounter;



extern unsigned char eepromValue;

#endif
