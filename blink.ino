#include <Blink.h>

Blink blink(D4);

void setup(){
  Serial.begin();
  Serial.println("\nBlink Version 1.0 Your_First_Name Your_Last_Name");
}


void loop(){
  blink.on(500);
  blink.off(300);
}
