#include <Arduino.h>
#include "difinitions.h"




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