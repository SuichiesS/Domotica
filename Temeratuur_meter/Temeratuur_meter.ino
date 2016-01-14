#include <DHT.h>
#define dht_apin A0 // Analog Pin sensor is connected to
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
 
dht DHT;
 
void setup(){
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Luchtvochtigheid en Temperatuur Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  mySwitch.enableTransmit(4);
  
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    
    Serial.print("Huidige Luchtvochtigheid = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperatuur = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    if(DHT.temperature >= 30.00)
    {
      mySwitch.send(10145388, 24);
    }
    if(DHT.temperature < 25.00)
    {
      mySwitch.send(10145389, 24);
    }
   
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 
