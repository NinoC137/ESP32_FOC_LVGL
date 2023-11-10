#include "Distance.h"

extern int distance;

char distanceBuffer[20];
char temp;

//串口读取index位
int i,j = 0;

void read_usart()
{
    i = Serial.available(); // 返回目前串口接收区内的已经接受的数据量
    if (i != 0)
    {
        j = 0;
        Serial.println(Serial.available());
        while (i--)
        {
            j++;
            temp = Serial.read(); // 读取一个数据并且将它从缓存区删除
            distanceBuffer[j] = temp;          // 把读取到的字符存储下来
        }
    }

}

static uint8_t hexCharToUint8(char c1, char c2)
{
    uint8_t value = 0;

    if (c1 >= '0' && c1 <= '9')
        value = (c1 - '0') << 4;
    else if (c1 >= 'A' && c1 <= 'F')
        value = (c1 - 'A' + 10) << 4;

    if (c2 >= '0' && c2 <= '9')
        value |= (c2 - '0');
    else if (c2 >= 'A' && c2 <= 'F')
        value |= (c2 - 'A' + 10);

    return value;
}

uint32_t Reformat_TOF(const char *format)
{
    uint8_t dataArray[7] = {0};

    int dataIndex = 0;
    char buffer[3];
    for (int i = 0; i < strlen(format); i += 3)
    {
        strncpy(buffer, format + i, 2);
        buffer[2] = '\0'; // 添加字符串结尾
        dataArray[dataIndex++] = hexCharToUint8(buffer[0], buffer[1]);
    }

    uint32_t combinedData = 0;
    // 将第一个数组的值放入高8位
    combinedData = ((uint32_t)dataArray[3]) << 24;
    // 将第二个数组的值放入次高8位
    combinedData |= ((uint32_t)dataArray[4]) << 16;
    // 将第三个数组的值放入次低8位
    combinedData |= ((uint32_t)dataArray[5]) << 8;
    // 将第四个数组的值放入低8位
    combinedData |= dataArray[6];

    memset(distanceBuffer, 0, 20);

    return combinedData / (1 << 16);
}