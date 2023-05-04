#ifndef _IO_H__
#define _IO_H__

// 导入Arduino核心文件
#include "Arduino.h"
#include <Wire.h>

/*
  io口引脚测试
*/
class IOTEST
{
  public:
  IOTEST(int pinNumberList[], int pinCount, int count, int delayTime);
  int IoHighLowTest(int index);
  int IoHighTest(int index);
  int IoLowTest(int index);


  private:
  int ioCount;
  int *ioTestList;
  int ioTotal;
  int ioDaley;


};

/*
  开关引脚测试
*/
// class BUTTONPIN
// {
//   public:
//   BUTTONPIN(int pin);
//   int ButtonON();
//   int ButtonOFF();
  
//   private:
//   int buttonPin;
// };





#endif
