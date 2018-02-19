#include <Arduino.h>
#include "hcsr04.h"

HCSR04::HCSR04(uint8_t trigger, uint8_t echo, float vel){
  this->trigger = trigger;
  this->echo = echo;
  this->vel = vel;

  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(trigger, LOW);
}

float HCSR04::loop(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  int time = pulseIn(echo, HIGH) / 2;
  return time * vel; // cm
}
