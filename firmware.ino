#include <AFMotor.h> //motor library
#include <Arduino.h> //standard arduino library

#define L_S A1 // left sensor into analog 1 input
#define R_S A0 // right sensor inot analog 0 input

AF_DCMotor m1(1);  //define motor 3 as LEFT MOTOR 

AF_DCMotor m2(2);  //define motor 4 as RIGHT MOTOR 

void setup() { 

  //Set initial speed of the motor & stop 

  m2.setSpeed(200); 

  m2.run(RELEASE); 

  m1.setSpeed(200); 

  m1.run(RELEASE); 

  pinMode(R_S, INPUT); 

  pinMode(L_S, INPUT); 

 
 

  delay(1000); 

} 

 
void loop() { 


  
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) { 

    forward(); 

  }  //both sensors detect white so go forward

   if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) { 

    turnRight(); 

  }  //if right sensor detects black turn right

  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) { 

    turnLeft(); 

  }  //if left sensor detects black turn right

  
  /*
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) { 

    Stop(); 

    // just in case

  }  
  */


} 

 
 
 

void forward() {   

  m1.run(BACKWARD); //i connected the motors upside down and cba to fix it

  m2.run(BACKWARD); 

} 

void turnRight() {  

  m1.run(FORWARD); 

  m2.run(BACKWARD); 

} 

void turnLeft() {  

  m1.run(BACKWARD); 

  m2.run(FORWARD); 

} 

void Stop() {   

  m1.run(RELEASE); 

  m2.run(RELEASE); 

} 

