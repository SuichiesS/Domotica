#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int Bsensor;
int sensor = 0;



void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(4);
}

void loop() {
Bsensor = analogRead(sensor);

Serial.println(Bsensor);

if (analogRead(sensor) >=600 ) 
{
  mySwitch.send(10145387, 24);
 Serial.println("Motion detected");
delay(1000);

 
}

if (analogRead(sensor) <=600)
{mySwitch.send(10145386, 24);}
delay(1000);
}
