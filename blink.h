/*
  Blink.h - Library for capstone design program
  Created by WonYo Hwang, March 11, 2017.
*/
#ifndef Blink_h
#define Blink_h

#include "Arduino.h"

class Blink
{
  public:
    Blink(int pin);
    void on(int num);
    void off(int num);
  private:
    int _pin
}

#endif
