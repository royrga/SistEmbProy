#include <DHT.h>


#include "MQ135.h"
#include "MQ7.h"
//#include <dht.h>

const int ANALOGPIN=1;
MQ135 gasSensor = MQ135(ANALOGPIN);
MQ7 mq7(A0,5.0);

DHT dht(2,DHT11);

//#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);      // sets the serial port to 9600
}
void loop(){
  
  char toggle = ' ';
  
  if(Serial.available()){
    
     toggle = Serial.read();
    
    if(toggle == '1'){
      
      float ppm = gasSensor.getPPM();
     // int chk = DHT.read11(DHT11_PIN);
      
      float val1 = dht.readTemperature(); //Humedad
      float val2 = dht.readHumidity();    //Temperatura
      float val3 = ppm*10000;       //Calidad del aire
      float val4 = mq7.getPPM()/3;  //CO
      
      String v1 = (String)val1;
      String v2 = (String)val2;
      String v3 = (String)val3;
      String v4 = (String)val4;
      
      Serial.println(v1+"\t\t"+v2+"\t\t"+v3+"\t\t"+v4);   
      
      delay(5000);      
    }
  
  }
  
}
