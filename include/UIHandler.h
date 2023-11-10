#ifndef __UIHANDLER_H
#define __UIHANDLER_H

#include "Arduino.h"
#include <lvgl.h>
#include <gui_guider.h>
#include <events_init.h>
#include "common.h"


void sliderHandler();

void scanNetworks();

static void LEDControl(int dutyValue, int slider_value);

static void SpeedControl(int dutyValue);

static void TemperateControl(int UITemperateValue1, int UITemperateValue2);

#endif