void setup() {
  Serial.begin(9600); // Set the baud rate
  pinMode(13, OUTPUT); // Set the onboard LED to output
  //Serial.println("Ready");
}
void loop() {
  char toggle = ' ';
  if(Serial.available()){ // Only send data back if data has been sent
    char toggle = Serial.read(); // Read the incoming data
    if(toggle == '1'){
      digitalWrite(13, HIGH);   // Turn the LED on (HIGH is the voltage level)     
      int val1 = analogRead(0);
      int val2 = 100;
      int val3 = 200;
      int val4 = 300;
      String v1= (String)val1;
      String v2= (String)val2;
      String v3= (String)val3;
      String v4= (String)val4;
      
      Serial.println(v1+"\t\t"+v2+"\t\t"+v3+"\t\t"+v4); 
      /*delay(100);
      Serial.print(val2);
      delay(100);
      Serial.print(val3);
      delay(100);
      Serial.print(val4);*/
      delay(100);
    }
  }    
  delay(100); // delay for 1/10 of a second
}

