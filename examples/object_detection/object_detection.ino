#include <hcsr04.h>

#define Trigger 6
#define Echo    7

#define vel 343e-4 // sound speed (cm/us)
#define factor 1.0
#define sensibility 150

HCSR04 hc(Trigger, Echo, vel * factor);

void setup(){
  Serial.begin(9600);
}

void loop(){
  float distance = hc.loop();
  Serial.print("distance: ");
  Serial.println(distance);
  if(distance < sensibility){
    Serial.println("Object detected!");
  } else {
    Serial.println("There's no object.");
  }

  delay(2000);
}
