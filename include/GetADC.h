#ifndef __GETADC_H
#define __GETADC_H

#include "Arduino.h"

#define MVF_BUFFER 4
#define FIRST_LAG_P 0.8

typedef struct
{
    float Filter_Buffer[MVF_BUFFER];
    int index;
    float sum;
    float average;
}Sliding_Mean_Filter;

void ADCinit();
void GetTemp(uint16_t* temp1, uint16_t* temp2);

//滤波算法
static float movingAverageFilter(Sliding_Mean_Filter *filter, float value);
static float FirstOrderLagFilter_Slope_1(float value);
static float FirstOrderLagFilter_Slope_2(float value);

#endif