#include "GetADC.h"

Sliding_Mean_Filter moving_filter_1;
Sliding_Mean_Filter moving_filter_2;

uint16_t actuallyTemperate;

void ADCinit()
{
  // 热电偶采集脚
  pinMode(1, ANALOG);
  // pinMode(2, ANALOG);
}

void GetTemp(uint16_t *temp1, uint16_t *temp2)
{
  // 170: 1k 120: 2k 25: 100k
  //  25: 156
  //  120: 2730
  //  y = 27x - 510 (单位:摄氏度)
  //  上限温度: 160度
  static uint16_t TempADC1, TempADC2;
  // 热电偶ADC检测
  TempADC1 = analogRead(1);
  // TempADC2 = analogRead(2);

  actuallyTemperate = (TempADC1 + 540) / 27;

  //开启滤波
  // uint16_t afterFilterADC1_first = (uint16_t)FirstOrderLagFilter_Slope_1((float)TempADC1);
  // uint16_t afterFilterADC2_first = (uint16_t)FirstOrderLagFilter_Slope_2((float)TempADC2);

  uint16_t afterFilterADC1_second = (uint16_t)movingAverageFilter(&moving_filter_1, (float)TempADC1);
  // uint16_t afterFilterADC2_second = (uint16_t)movingAverageFilter(&moving_filter_2, (float)afterFilterADC2_first);

  //传出真实值
  *temp1 = (afterFilterADC1_second + 540) / 27;
  // *temp2 = (afterFilterADC2_second + 540) / 27;
}

static float movingAverageFilter(Sliding_Mean_Filter *filter, float value) {
    filter->sum -= filter->Filter_Buffer[filter->index];
    filter->sum += value;
    filter->Filter_Buffer[filter->index] = value;
    filter->average = filter->sum / MVF_BUFFER;
    if (++filter->index == MVF_BUFFER)
        filter->index = 0;
    return filter->average;
}

static float FirstOrderLagFilter_Slope_1(float value) {
    static float last_value_1;
    value = FIRST_LAG_P * value + (1.0f - FIRST_LAG_P) * last_value_1; //一阶滞后滤波
    last_value_1 = value;
    return value;
}

static float FirstOrderLagFilter_Slope_2(float value) {
    static float last_value_2;
    value = FIRST_LAG_P * value + (1.0f - FIRST_LAG_P) * last_value_2; //一阶滞后滤波
    last_value_2 = value;
    return value;
}

