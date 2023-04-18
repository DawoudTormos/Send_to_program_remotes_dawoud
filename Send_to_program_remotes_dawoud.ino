/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
RCSwitch mySwitchR = RCSwitch();
int timerCode = 3048;
bool state = 0;

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(23);
 // mySwitchR.enableReceive(23); 

 // pinMode(5 , INPUT);
//  pinMode(23 , OUTPUT);
  // Optional set protocol (default is 1, will work for most outlets)
   mySwitch.setProtocol(1);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}


void loop() {/*
  if(digitalRead(5) ){
    while(digitalRead(5));
    if(state){state = 0;}else{state = 1;}
  }
  if(state){
      Serial.print("timer is on. Sending:");
      Serial.println(timerCode);
  mySwitch.send(timerCode, 12);
  digitalWrite(12,HIGH);
  delay(100); 
  digitalWrite(12,LOW);
  delay(600); 
  return 1 ;
  }*/

  /* See Example: TypeA_WithDIPSwitches 
  mySwitch.switchOn("11111", "00010");
  delay(1000);
  mySwitch.switchOff("11111", "00010");
  delay(1000);*/

  /* Same switch as above, but using decimal code */


   while (Serial.available() > 0){ 
   // s = millis();
String str = Serial.readStringUntil('\n');
/*
if(str == "x"){
    Serial.println("Waiting for the value of the timer variable");
     while(Serial.available() == 0) {
    }
  String str2 = Serial.readStringUntil('\n');
     str2 = Serial.readStringUntil('\n');
    int keyVal2 = str.toInt();
    timerCode = keyVal2;
    Serial.print("setting the value of the timer variable to");
     Serial.println(keyVal2);

  
}*/
long  int keyVal = str.toInt();

  
  int ii = 0;
 /* while(ii<7){
    ii++;
    delay(1000); 
    Serial.println(ii);
    
  }*/
  Serial.println("Sending...");
   Serial.println(keyVal);
  mySwitch.send(keyVal, 24);
  delay(100);  

 /* Serial.println("Sending twice");
  mySwitch.send(keyVal, 24);
  delay(100); 

   Serial.println("Sending thrice");
  mySwitch.send(keyVal, 24);
  delay(100); 

   Serial.println("Sending fourth");
  mySwitch.send(keyVal, 24);
  delay(100); */


/*unsigned long int e = millis();

Serial.println(e - s);*/

 }

   if (mySwitchR.available()) {
    
    Serial.print("Received ");
    Serial.print( mySwitchR.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitchR.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitchR.getReceivedProtocol() );

    mySwitchR.resetAvailable();
  }
  

  /* Same switch as above, but using binary code 
  mySwitch.send("000000000001010100010001");
  delay(1000);  
  mySwitch.send("000000000001010100010100");
  delay(1000);

  /* Same switch as above, but tri-state code 
  mySwitch.sendTriState("00000FFF0F0F");
  delay(1000);  
  mySwitch.sendTriState("00000FFF0FF0");
  delay(1000);

  delay(20000);*/
}
