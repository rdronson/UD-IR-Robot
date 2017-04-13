#include <Servo.h>
#include <TimerOne.h>


#define IR_F 2 //front 0
#define IR_FR 3 //Front Right looking from center of array towards the front labeled F on the array itself 1
#define IR_FL 4 //Front Left looking from center of array towards the front  7
#define IR_B  5//back 4
#define IR_BR 6 //back right with fwd looking toward front LED 5 3
#define IR_BL 7 //back left with fwd looking toward front LED 6 5
#define IR_R 8 //7 2
#define IR_L 12 //8 6
#define IR_TOP 13 //Top IR LED 9 8
#define REAR 9
#define FRONT 10
#define SC 11
#define TIMER 250000

Servo frontsteering;
Servo speedcontrol;
Servo rearsteering;


int count0 = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;
int count6 = 0;
int count7 = 0;
int count8 = 0;

unsigned short currentState0 = 1;
unsigned short currentState1 = 1;
unsigned short currentState2 = 1;
unsigned short currentState3 = 1;
unsigned short currentState4 = 1;
unsigned short currentState5 = 1;
unsigned short currentState6 = 1;
unsigned short currentState7 = 1;
unsigned short currentState8 = 1;

unsigned short i = 0;
int sensorArray[9] = {count0, count1, count2, count3, count4, count5, count6, count7, count8};
unsigned short sensorCount = 0;
int x = 0;

void setup()
{
  //rearsteering.attach(9);    //Rear Steering Servo
  //frontsteering.attach(10);  //Front Steering Servo
  //speedcontrol.attach(11);   //Electronic Speed Control Fwd/Back
  pinMode(FRONT, OUTPUT);
  pinMode(REAR, OUTPUT);
  pinMode(SC, OUTPUT);
  pinMode(IR_F,INPUT);
  pinMode(IR_FR, INPUT);
  pinMode(IR_FL,INPUT);
  pinMode(IR_B, INPUT);
  pinMode(IR_BR,INPUT);
  pinMode(IR_BL, INPUT);
  pinMode(IR_R,INPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_TOP,INPUT);
  Serial.begin(9600);

  
  
  

  // initialize timer1
  noInterrupts();
  Timer1.initialize(TIMER); // 1 million microseconds is 1 second
  Timer1.attachInterrupt(isr);
  interrupts();
  
}

void isr()        // interrupt service routine 
{

  sensorCount = 0;
  Serial.println("012345678");  
  Serial.print(sensorArray[0]);
  Serial.print(sensorArray[1]);
  Serial.print(sensorArray[2]);
  Serial.print(sensorArray[3]);
  Serial.print(sensorArray[4]);
  Serial.print(sensorArray[5]);
  Serial.print(sensorArray[6]);
  Serial.print(sensorArray[7]);
  Serial.println(sensorArray[8]);
  
  for(x; x<8; x++)
    { 
      if(sensorArray[x] > 0)
      { 
        
        sensorCount = (sensorCount + 1) % 10;
        sensorArray[x] = 0;
        
        
      }
      else{
        //Serial.println("Hello World");
        
      }
     }  
     x = 0;
     sensorArray[8] = 0;
     Serial.print ("sensorCount = ");
     Serial.println (sensorCount);
     Serial.println("Hello World");
     
}


void loop()
{
    
    /*if(digitalRead(IR_F) == HIGH and currentState0 == 0)//Front state is state 0 every variable should have a 0 at the end
    {
      
      count0 = count0 + 1;
      currentState0 = 1;  
      sensorArray[0] = count0;
    } 
    */
    if(digitalRead(IR_F) == LOW)
    {
     
      count0 = count0 + 1;
      currentState0 = 0;
      sensorArray[0] = count0;
      
    } 
    /*
    if(digitalRead(IR_FR) == HIGH and currentState1 == 0)//Front Right state is state 1 every variable should have a 1 at the end
    {
      
      count1 = count1 + 1;
      currentState1 = 1;
      sensorArray[1] = count1;
    }  
    */
    if(digitalRead(IR_FR) == LOW)
    {
      count1 = count1 + 1;
      currentState1 = 0;
      sensorArray[1] = count1;
    }
    /*
    if(digitalRead(IR_R) == HIGH and currentState2 == 0) //Right state is state 2 every variable should have a 2 at the end
    {
      
      count2 = count2 + 1;
      currentState2 = 1;
      sensorArray[2] = count2;
    }  
    */
    if(digitalRead(IR_R) == LOW)
    {
      
      count2 = count2 + 1;
      currentState2 = 0;
      sensorArray[2] = count2;
    }
  /*
    if(digitalRead(IR_BR) == HIGH and currentState3 == 0) //Back Right state is state 3 every variable should have a 3 at the end
    {
      
      count3 = count3 + 1;
      currentState3 = 1;
      sensorArray[3] = count3;
    }  
    */
    if(digitalRead(IR_BR) == LOW)
    {
      
      count3 = count3 + 1;
      currentState3 = 0;
      sensorArray[3] = count3;
    }
    /*
    if(digitalRead(IR_B) == HIGH and currentState4 == 0) //Back state is state 4 every variable should have a 4 at the end
    {
      
      count4 = count4 + 1;
      currentState4 = 1;
      sensorArray[4] = count4;
    }  
    */
    if(digitalRead(IR_B) == LOW)
    {
      
      count4 = count4 + 1;
      currentState4 = 0;
      sensorArray[4] = count4;
    }
    /*
    if(digitalRead(IR_BL) == HIGH and currentState5 == 0) //Back Left state is state 5 every variable should have a 5 at the end
    {
      
      count5 = count5 + 1;
      currentState5 = 1;
      sensorArray[5] = count5;
    }  
    */
    if(digitalRead(IR_BL) == LOW)
    {
      
      count5 = count5 + 1;
      currentState5 = 0;
      sensorArray[5] = count5;
    }
    /*
    if(digitalRead(IR_L) == HIGH and currentState6 == 0) //Left state is state 6 every variable should have a 6 at the end
    {
      
      count6 = count6 + 1;
      currentState6 = 1;
      sensorArray[6] = count6;
    }  
    */
    if(digitalRead(IR_L) == LOW)
    {
      
      count6 = count6 + 1;
      currentState6 = 0;
      sensorArray[6] = count6;
    }

    
    /*
    if(digitalRead(IR_FL) == HIGH and currentState7 == 0) //Front Left state is state 7 every variable should have a 7 at the end
    {
      
      count7 = count7 + 1;
      currentState7 = 1;
      sensorArray[7] = count7;
    }  
    */
    if(digitalRead(IR_FL) == LOW)
    {
      
      count7 = count7 + 1;
      currentState7 = 0;
      sensorArray[7] = count7;
    }
    /*
    if(digitalRead(IR_TOP) == HIGH and currentState8 == 0) //Top state is state 8 every variable should have a 8 at the end
    {
      
      count8 = count8 + 1;
      currentState8 = 1;
      sensorArray[8] = count8;
    }  
    */
    if(digitalRead(IR_TOP) == LOW and currentState8 == 1)
    {
      
      count8 = count8 + 1;
      currentState8 = 0;
      sensorArray[8] = count8;
    }

    i++;
    count0 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    count6 = 0;
    count7 = 0;
    count8 = 0;
    
    
    
    if(sensorCount > 6 or sensorCount == 0){
      //Do nothing or halt
      Serial.println("I'm waiting");
      digitalWrite(SC, LOW);
      digitalWrite(FRONT, LOW);
    }
    else if(sensorCount == 6){
      doAction(findCenter(sensorCount));
    }
    else if(sensorCount == 5){
      //Call function doAction to find center of IR sensors that are detecting      
      doAction(findCenter(sensorCount));     
    }

    else if(sensorCount == 3 or sensorCount == 4){
      //Call function doAction to find center of IR sensors that are detecting
      doAction(findCenter(sensorCount));
    }

    else if(sensorCount == 2){
      if(sensorArray[0] == 1){//Guess Front
        doAction(0);
      }
      else if (sensorArray[4] == 1){
        doAction(4);
      }
      else{
        doAction(0);
      }
    } 
    
    /**
    for(x; x<10; x++)
    { 
            
      //Serial.print("Sensor ");
      Serial.println(x);
      delay(100);        
      //Serial.print(sensorArray[x]);
      Serial.print('\n');
      
      if(sensorArray[x] > 0)
      { 
        sensorCount = (sensorCount + 1) % 10;
                
        

        Serial.print("Sensor Count = ");
        Serial.print(sensorCount);
        Serial.println (" sensors");
      }
     }

     //sensorCount = 0;
     x = 0;
  **/
    
    
    /**
    if(i == 40000)
    { 
      
      Serial.print("IR_F = ");
      Serial.print(sensorArray[0]);
      Serial.println (" times");
      
  
      Serial.print("IR_FR = ");
      Serial.print(sensorArray[1]);
      Serial.println (" times");

      Serial.print("IR_FL = ");
      Serial.print(count3);
      Serial.println (" times");
      
  
      Serial.print("IR_B = ");
      Serial.print(count4);
      Serial.println (" times");

      Serial.print("IR_BR = ");
      Serial.print(count5);
      Serial.println (" times");
      
  
      Serial.print("IR_BL = ");
      Serial.print(count6);
      Serial.println (" times");

      Serial.print("IR_R = ");
      Serial.print(count7);
      Serial.println (" times");
      
  
      Serial.print("IR_L = ");
      Serial.print(count8);
      Serial.println (" times");

      Serial.print("IR_TOP = ");
      Serial.print(count9);
      Serial.println (" times");
      
      sensorArray[0] = 0;
      sensorArray[1] = 0;
      sensorArray[2] = 0;
      sensorArray[3] = 0;
      sensorArray[4] = 0;
      sensorArray[5] = 0;
      sensorArray[6] = 0;
      sensorArray[7] = 0;
      sensorArray[8] = 0;
      count1 = 0;
      count2 = 0;
      count3 = 0;
      count4 = 0;
      count5 = 0;
      count6 = 0;
      count7 = 0;
      count8 = 0;
      count9 = 0;
      i = 0;
      //x = 0;
    }
  **/  
}

int findCenter(unsigned short detect){
  if(detect == 6){
    if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1 )and (sensorArray[3] == 0) and (sensorArray[4] == 0 )and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){
      return 0; //FRONT, Drive Forward     
    }

    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 0 )and (sensorArray[5] == 0)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){
      return 1; //FRONT RIGHT, Turn around then Drive forward
    }

    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 1)){
      return 2; //RIGHT; Turn 90 degrees to the right then Drive forward
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){
      return 3; //REAR RIGHT; Turn 135 degrees to the right then Drive forward
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 1)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 0)){
      return 4; //REAR; Turn 180 degrees to the right or left then Drive forward
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){
      return 5; //REAR LEFT; Turn 135 degrees to the left then Drive forward
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){
      return 6; //LEFT; Turn 90 degrees to the left then Drive forward
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){
      return 7; //FRONT LEFT; Turn 45 degrees to the left then Drive forward
    }
  }
  else if(detect == 5){
    if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 0) and (sensorArray[4] == 0) and (sensorArray[5] == 0)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ 
      // F, FR, R, FL, L
      return 0; //FRONT, Drive Forward
      
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 1) and (sensorArray[4] == 0) and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 1)){ 
      // F, FR, R, BR, FL
      return 1; //FRONT RIGHT, Turn wheels 45 degrees to right and straighten wheels
      
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 0) and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ 
      // F, FR, R, BR, B
      return 2; //RIGHT, Turn wheels 90 degrees to right and straighten wheels
      
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 1)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ 
      // FR, R, BR, B, BL
      return 3; //REAR RIGHT, Turn wheels 135 degrees to right and straighten wheels
      
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 1 )and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 0)){ 
      // R, BR,B, BL, L
      return 4;//REAR, Turn 180 degrees around and straighten wheels
      
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ 
      // BR, B, BL, L, FL
      return 5; //REAR LEFT, Turn wheels 135 degrees to left and straighten wheels
      
    }
    else if((sensorArray[0] == 1)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ 
      // F, B, BL, L, FL
      return 6; //LEFT, Turn wheels 90 degrees to left and straighten wheels
      
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ 
      // F, FR, BL, L, FL
      return 7; //FRONT LEFT, Turn Left 45 degrees and straighten wheels
    }  
    
    
  }
  else if(detect == 4){
    if((sensorArray[0] == 1)and (sensorArray[1] == 1)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ // FR, F, FL
      return 0; //FRONT, Drive Straight ahead
      
    }
    else if((sensorArray[0] == 1)and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 1)){ // R, FR, F
      return 1; //FRONT RIGHT, Turn wheels 45 degrees to the right and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ // FR, R, BR
      return 2; //RIGHT, Turn wheels 90 degrees to the right and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 1)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ // R, BR, B
      return 3; //REAR RIGHT, Turn wheels 135 degrees to the right and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 0)){ // BR, B, BL
      return 4; //REAR, Turn around 180 degrees to right or left and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ // B, BL, L
      return 5; //REAR LEFT, Turn around 135 degrees to left and then straighten wheels
    
    }
    else if((sensorArray[0] == 1)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ // BL, L, FL
      return 6; //LEFT, Turn around 90 degrees to left and then straighten wheels
    
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ // L, FL, F
      return 7; //FRONT LEFT, Turn around 45 degrees to left and then straighten wheels
    
    }
  
}
  else if(detect == 3){
    if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 1)){ // FR, F, FL 0 1 7
      return 0; //FRONT, Drive Straight ahead
      
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ // R, FR, F  0 1 2
      return 1; //FRONT RIGHT, Turn wheels 45 degrees to the right and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 1)and (sensorArray[2] == 1)and (sensorArray[3] == 1) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ // FR, R, BR 1 2 3
      return 2; //RIGHT, Turn wheels 90 degrees to the right and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 1)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 0)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ // R, BR, B 2 3 4
      return 3; //REAR RIGHT, Turn wheels 135 degrees to the right and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 1) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 0) and (sensorArray[7] == 0)){ // BR, B, BL 3 4 5
      return 4; //REAR, Turn around 180 degrees to right or left and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 1)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 0)){ // B, BL, L 4 5 6
      return 5; //REAR LEFT, Turn around 135 degrees to left and then straighten wheels
    
    }
    else if((sensorArray[0] == 0)and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 1)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ // BL, L, FL 5 6 7
      return 6; //LEFT, Turn around 90 degrees to left and then straighten wheels
    
    }
    else if((sensorArray[0] == 1 )and (sensorArray[1] == 0)and (sensorArray[2] == 0)and (sensorArray[3] == 0) and (sensorArray[4] == 0)and (sensorArray[5] == 0)and (sensorArray[6] == 1) and (sensorArray[7] == 1)){ // L, FL, F 6 7 0
      return 7; //FRONT LEFT, Turn around 45 degrees to left and then straighten wheels
    
    }
  
}
}

void doAction(int sensor){  
  if(sensor == 0){
    //drive forward
    //speedcontrol.writeMicroseconds(1700);   // fwd
    //delay(3000); 
    //frontsteering.writeMicroseconds(1600);  // Center
//  rearsteering.writeMicroseconds(1600);   // Center 
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);
    
    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(FRONT, LOW);
    
    Serial.println("Driving Forward");
  }
  else if(sensor == 1){
    //steer wheels to right 45 degrees and starighten wheels then drive forward  
 
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1250);    
    digitalWrite(FRONT, LOW);

    delay(4000);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(FRONT, LOW);
    
    Serial.println("Steering Right 45 degrees");
  }
  else if(sensor == 2){
    //steer wheels to right 90 degrees and starighten wheels then drive forward
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(900);    
    digitalWrite(FRONT, LOW);

    delay(4000);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(FRONT, LOW);
    
    Serial.println("Steering Right 90 degrees");
  }
  else if(sensor == 3){
    //steer wheels to right 135 degrees and starighten wheels then drive forward
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);

    digitalWrite(REAR, HIGH);
    delayMicroseconds(1950);    
    digitalWrite(REAR, LOW);

    delay(4000);

    digitalWrite(REAR, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(REAR, LOW);
    Serial.println("Steering Right 135 degrees");
  }
  else if(sensor == 4){
    //steer wheels to right or left 180 degrees and starighten wheels then drive forward
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);
    
    digitalWrite(REAR, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(REAR, LOW);
    Serial.println("Driving Right or Left 180 degrees or turn around");
  }
  else if(sensor == 5){
    //steer wheels to left 135 degrees and starighten wheels then drive 
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);

    digitalWrite(REAR, HIGH);
    delayMicroseconds(1250);    
    digitalWrite(REAR, LOW);

    delay(4000);

    digitalWrite(REAR, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(REAR, LOW);
    Serial.println("Steering Left 135 degrees");
    
  }
  else if(sensor == 6){
    //steer wheels to left 90 degrees and starighten wheels then drive forward
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(2300);    
    digitalWrite(FRONT, LOW);

    delay(4000);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(FRONT, LOW);
    Serial.println("Steering Left 90 degrees");
  }
  else if(sensor == 7){
    //steer wheels to left 45 degrees and starighten wheels then drive forward
    digitalWrite(SC, HIGH);
    delayMicroseconds(1700);
    digitalWrite(SC, LOW);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1950);    
    digitalWrite(FRONT, LOW);

    delay(4000);

    digitalWrite(FRONT, HIGH);
    delayMicroseconds(1600);    
    digitalWrite(FRONT, LOW);
    Serial.println("Steering Left 45 degrees");
  }
}
 


