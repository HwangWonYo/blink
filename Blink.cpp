#include "Arduino.h"
#include "Blink.h"

Blink::Blink(int pin)
{
  _pin = pin;
  pinMode(LED_BUILTIN, OUTPUT);

}

void Blink::on(int num)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(num);  
}

void Blink::off(int num)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(num);
}
