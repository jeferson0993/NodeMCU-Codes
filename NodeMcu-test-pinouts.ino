/*
  NodeMCU - relay board test program
  Sequentially turns each relay on and off for 2 seconds, loops forever
*/
  
 
// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
 
  digitalWrite(16, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}
 
// the loop function runs over and over again forever
void loop() {
 
  digitalWrite(16, LOW);   // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(16, HIGH);  // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
  
  digitalWrite(5, LOW);    // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(5, HIGH);   // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
 
  digitalWrite(4, LOW);    // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(4, HIGH);   // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
 
  digitalWrite(0, LOW);    // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(0, HIGH);   // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
 
  digitalWrite(2, LOW);    // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
  
  digitalWrite(2, HIGH);   // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
 
  digitalWrite(14, LOW);   // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(14, HIGH);  // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
 
  digitalWrite(12, LOW);   // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(12, HIGH);  // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(13, LOW);   // LOW lights optoisolator LED to ground - turns on relay
  delay(2000);             // wait for a 2 seconds
 
  digitalWrite(13, HIGH);  // HIGH kills optoisolator LED - turns OFF relay
  delay(2000);             // wait for a 2 seconds
}
