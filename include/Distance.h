#ifndef __DISTANCE_H
#define __DISTANCE_h

#include "Wire.h"
#include "Arduino.h"

void read_usart();

static uint8_t hexCharToUint8(char c1, char c2);

uint32_t Reformat_TOF(const char *format);

extern char distanceBuffer[];
extern int i,j;

#endif