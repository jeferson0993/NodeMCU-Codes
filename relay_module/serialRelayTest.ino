/*
serialRelayTest.ino
esp01 telay module 1 channel
*/


byte relON[] = {0xA0, 0x01, 0x01, 0xA2};  //Hex command to send to serial for open relay
byte relOFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay

void setup(void){
  Serial.begin(9600);

  //make sure the relay is off before moving forward
  Serial.write(relOFF, sizeof(relOFF));
  delay(10);
  Serial.write(relOFF, sizeof(relOFF));
}


void loop(void){

  //turn the relay on for 3 seconds
  Serial.write(relON, sizeof(relON));
  delay(3000);

  //turn the relay off for 3 seconds
  Serial.write(relOFF, sizeof(relOFF));
  delay(3000);
}
