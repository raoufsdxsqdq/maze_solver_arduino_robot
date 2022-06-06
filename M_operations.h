#include <Arduino.h>
#include "difinitions.h"
#include<Arduino.h>
#include "difinitions.h"

long duration_front;
int distance_front ; 
long duration_right;
int distance_right;

long duration_left;
int distance_left;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
void US_operation(int Trigo_pin_com){
  
  digitalWrite(Trigo_pin_com, LOW); /////////////// function for sending signal for ultra sonic //////////

  delayMicroseconds(2);

  digitalWrite(Trigo_pin_com, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigo_pin_com, LOW);}


 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
void US_front(){                      //////////////// function for the front ultrasonic  //////////////
  US_operation(Trigo_pin_front);

  duration_front = pulseIn(ultra_sonic_front, HIGH);
  distance_front = duration_front * 0.034 / 2;
  
  Serial.print("Distance_front:  ");
  Serial.println(distance_front);}
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void US_right(){      /////////////////////////func for the right ultra sonic  //////////////////
  US_operation(Trigo_pin_right);
  duration_right = pulseIn(ultra_sonic_right, HIGH);
  distance_right = duration_right * 0.034 / 2;
  
  Serial.print("Distance_right:  ");
  Serial.println (distance_right);}
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
void US_left(){                    ////////////////////// func for the left  ultra sonic /////////////////////
  US_operation(Trigo_pin_left);
  duration_left = pulseIn(ultra_sonic_left, HIGH);
  distance_left = duration_left * 0.034 / 2;
 
  Serial.print("Distance_left: ");
  Serial.println(distance_left);}
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////

  




////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void move_forward(int speed_right = 255, int speed_left = 255){ //////////////////////////// the car will move forward /////////////////////////////

digitalWrite(motor_left_1,HIGH);
digitalWrite(motor_left_2,LOW);
digitalWrite(motor_right_2,LOW);
digitalWrite(motor_right_1,HIGH);
digitalWrite(motor_right_speed,speed_right);
digitalWrite(motor_left_speed,speed_left);


}

void move_backward(int speed_right = 255, int speed_left = 255){ //////////////////////////// the car will move forward /////////////////////////////

digitalWrite(motor_left_1,LOW);
digitalWrite(motor_left_2,HIGH);
digitalWrite(motor_right_2,HIGH);
digitalWrite(motor_right_1,LOW);
digitalWrite(motor_right_speed,speed_right);
digitalWrite(motor_left_speed,speed_left);


}

void turn_left(int speed_right = 255, int speed_left = 255){

digitalWrite(motor_left_1,LOW);
digitalWrite(motor_left_2,LOW);
digitalWrite(motor_right_2,HIGH);
digitalWrite(motor_right_1,LOW);
digitalWrite(motor_right_speed,speed_right); //////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> speed of turnning
digitalWrite(motor_left_speed,speed_left); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>> speed variable 


}

void turn_right(int speed_right = 255, int speed_left = 255){

digitalWrite(motor_left_1,HIGH);
digitalWrite(motor_left_2,LOW);
digitalWrite(motor_right_2,LOW);
digitalWrite(motor_right_1,LOW);
digitalWrite(motor_right_speed,speed_right); //////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> speed of turnning
digitalWrite(motor_left_speed,speed_left); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>> speed variable 


}

///////////////////////////////////////////////////////////////////////////////////////////////////:

///  go back to the right path


void  diviate_left (int speed_right = 255, int speed_left = 255){

digitalWrite(motor_left_1,HIGH);  
digitalWrite(motor_left_2,LOW);
digitalWrite(motor_right_2,LOW);
digitalWrite(motor_right_1,HIGH);
digitalWrite(motor_right_speed,speed_right); /// <<< right speed must be greater than the left speed 
digitalWrite(motor_left_speed,speed_left);


}


///  go back to the right path


void  diviate_right (int speed_right = 255, int speed_left =255){

digitalWrite(motor_left_1,HIGH);
digitalWrite(motor_left_2,LOW);
digitalWrite(motor_right_2,LOW);
digitalWrite(motor_right_1,HIGH);
digitalWrite(motor_right_speed,speed_right); //// <<< left speed must be greater than the right speed
digitalWrite(motor_left_speed,speed_left);


}


void stop(){
digitalWrite(motor_left_1,LOW);
digitalWrite(motor_left_2,LOW);
digitalWrite(motor_right_2,LOW);  //  stop motors
digitalWrite(motor_right_1,LOW);

}
