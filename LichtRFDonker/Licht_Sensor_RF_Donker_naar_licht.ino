
    #include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
    
    
    int photocellPin = 0;  
    int photocellReading;     
           
          
    void setup(void) {
     
      Serial.begin(9600);
      mySwitch.enableTransmit(4);   
    }
     
    void loop(void) {
      photocellReading = analogRead(photocellPin);  
      Serial.print("Light reading = ");
      Serial.println(photocellReading);
          
            
      if (photocellReading <=900)
      {  mySwitch.send(10145391, 24);
         }

      if (photocellReading >=900)
      { mySwitch.send(10145390, 24);
        }
    
      delay(100);

   
}


