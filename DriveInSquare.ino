#include <Servo.h>
Servo frontsteering;
Servo rearsteering;
Servo speedcontrol;

void setup() {
 rearsteering.attach(9);    //Rear Steering Servo
 frontsteering.attach(10);  //Front Steering Servo
 speedcontrol.attach(11);   //Electronic Speed Control Fwd/Back
}
void loop() { 

  speedcontrol.writeMicroseconds(1700);   // fwd
  delay(3000);                            // wait for 3 second   
  frontsteering.writeMicroseconds(900);   // turn right 
  rearsteering.writeMicroseconds(2000);   // turn right 
  delay(4000);                            // wait for 3 second  
  frontsteering.writeMicroseconds(1600);  // Center
//  rearsteering.writeMicroseconds(1600);   // Center 
  delay(3000);
  frontsteering.writeMicroseconds(900);   // turn right 
//  rearsteering.writeMicroseconds(2000);   // turn right 
  delay(4000);                            // wait for 3 second  
  frontsteering.writeMicroseconds(1600);  // Center
//  rearsteering.writeMicroseconds(1600);   // Center 
  delay(3000); 
  frontsteering.writeMicroseconds(900);   // turn right 
//  rearsteering.writeMicroseconds(2000);   // turn right 
  delay(4000);                            // wait for 3 second  
  frontsteering.writeMicroseconds(1600);  // Center
//  rearsteering.writeMicroseconds(1600);   // Center 
  speedcontrol.writeMicroseconds(1450);   // stop
  delay(30000); 
  



}
