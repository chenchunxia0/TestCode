#include"IO.h"
#include"Arduino.h"

/*
    引脚测试初始化
    参数：测试引脚对应的数组，测试引脚数量
*/
IOTEST :: IOTEST(int pinNumberList[], int pinCount, int count, int delayTime)
{
    ioTestList = &pinNumberList[0];   // 测试引脚数组赋值
    ioCount = pinCount;  
    ioTotal = count;          // 测试引脚数量赋值
    ioDaley = delayTime;

    // 测试引脚配置为输入模式
    for(int i = 0;i < ioCount; i++)     
    {
        pinMode(pinNumberList[i], INPUT); 
    }
}


/*
    参数：测试引脚数组里面待测引脚的序号
    io高电平测试，循环检测50次，等于50次返回1.否则返回0
*/
IOTEST :: IoHighTest(int index)
{
    int highcount = 0;
    for (int i = 0; i < ioTotal; i++)
    {
        if (digitalRead(ioTestList[index]) == HIGH)
        {
            highcount++;
            delay(ioDaley);
        }
    }
    if (highcount == ioTotal)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*
    参数：测试引脚数组里面待测引脚的序号
    io低电平测试，循环检测50次，等于50次返回1.否则返回0
*/
IOTEST :: IoLowTest(int index)
{
    int number;
    int lowcount = 0;
    for (int i = 0; i < ioTotal; i++)
    {
        if (digitalRead(ioTestList[index]) == LOW)
        {
            lowcount++;
            delay(ioDaley);
        }
    }
    if (lowcount == ioTotal)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*
    参数：测试高电平对应的引脚序号
    测试方案：先检测对应的引脚是否为高电平，然后检测其他引脚是不是为低电平。如果满足条件就返回1.如果不满足就返回0
*/
IOTEST :: IoHighLowTest(int index)
{
    int pinTestCount = 0;
    if (IoHighTest(index))
    {
        for (int j = 0;j < ioCount;j++)
        {
            if (j != index)
            {
                if (IoLowTest(j))
                {
                    pinTestCount++;
                }
            }
            else
            {
                continue;
            }
        }
        if (pinTestCount == (ioCount - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
} 

/*
    开关引引脚测试初始化
    参数：测试对应引脚
*/
// BUTTONPIN :: BUTTONPIN(int pin)
// {
//     buttonPin = pin;
//     pinMode(buttonPin, OUTPUT);
//     digitalWrite(buttonPin, HIGH);
// }

// BUTTONPIN :: ButtonON()
// {
//     while (digitalRead(buttonPin) == LOW)
//     {
//         delay(1);
//     }
// }

// BUTTONPIN :: ButtonOFF()
// {
//     while (digitalRead(buttonPin) == HIGH)
//     {
//         delay(1);
//     }
    
// }




