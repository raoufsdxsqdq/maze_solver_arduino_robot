#ifndef M_OPERATION_H
#define M_OPERATION_H
#include <Arduino.h>
#include "difinitions.h"
#include "U_Sonic.h"

int speed = 0;
#define kp 2 
#define h 100

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void move_forward(int speed_right = 255, int speed_left = 255)
{ //////////////////////////// the car will move forward /////////////////////////////

    digitalWrite(motor_left_1, HIGH);
    digitalWrite(motor_left_2, LOW);
    digitalWrite(motor_right_2, LOW);
    digitalWrite(motor_right_1, HIGH);
    analogWrite(motor_right_speed, speed_right);
    analogWrite(motor_left_speed, speed_left);
}

void move_backward(int speed_right = 255, int speed_left = 255)
{ //////////////////////////// the car will move forward /////////////////////////////

    digitalWrite(motor_left_1, LOW);
    digitalWrite(motor_left_2, HIGH);
    digitalWrite(motor_right_2, HIGH);
    digitalWrite(motor_right_1, LOW);
    analogWrite(motor_right_speed, speed_right);
    analogWrite(motor_left_speed, speed_left);
}

void stopp()
{
    digitalWrite(motor_left_1, LOW);
    digitalWrite(motor_left_2, LOW);
    analogWrite(motor_right_2, LOW); //  stop motors
    analogWrite(motor_right_1, LOW);
    // delay(200);
}

void diviate(int speed_right = 255, int speed_left = 255)
{
    speed = kp * ((distance_left - distance_right) / 2);

    digitalWrite(motor_left_1, HIGH);
    digitalWrite(motor_left_2, LOW);
    digitalWrite(motor_right_2, LOW);
    digitalWrite(motor_right_1, HIGH);
    analogWrite(motor_right_speed, speed_right - speed); /// <<< right speed must be greater than the left speed
    analogWrite(motor_left_speed, speed_left + speed);
}



void turn_right()
{

    steps = 0;
    while (1)
    {   
        stopp();
        digitalWrite(motor_left_1, HIGH);
        digitalWrite(motor_left_2, LOW);
        analogWrite(motor_left_speed, h);

        if (digitalRead(sensor2))
        {

            Serial.println("hello");

            steps = steps + 1;
            Serial.println(steps);
            while (digitalRead(sensor2));
        }

        if (steps >=16)
        {

            digitalWrite(motor_right_1, LOW);
            digitalWrite(motor_right_2, LOW);
            digitalWrite(motor_left_1, LOW);
            digitalWrite(motor_left_2, LOW);
            analogWrite(motor_right_speed, 0);
            break;
        }
    }

    steps = 0;
    while (1)
    {
       move_forward(80, 80);
      
        
        if (digitalRead(sensor2))
        {

            Serial.println("hello");

            steps = steps + 1;
            Serial.println(steps);
            while (digitalRead(sensor2));
        }
        if (steps >= 10)
        {

            
            
            digitalWrite(motor_right_1, LOW);
            digitalWrite(motor_right_2, LOW);
            digitalWrite(motor_left_1, LOW);
            digitalWrite(motor_left_2, LOW);
            analogWrite(motor_right_speed, 0);
            move_forward(80,80);

            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////:


void turn_left()
{
    steps = 0;
    while (1)
    {   
        stopp();
        digitalWrite(motor_right_1, HIGH);
        digitalWrite(motor_right_2, LOW);
        analogWrite(motor_right_speed, h);

        if (digitalRead(sensor))
        {

            Serial.println("hello");

            steps = steps + 1;
            Serial.println(steps);
            while (digitalRead(sensor));
        }

        if (steps >=13)
        {

            digitalWrite(motor_right_1, LOW);
            digitalWrite(motor_right_2, LOW);
            digitalWrite(motor_left_1, LOW);
            digitalWrite(motor_left_2, LOW);
            analogWrite(motor_right_speed, 0);
            break;
        }
    }

    steps = 0;
    while (1)
    {
       move_forward(80, 80);
      
        
        if (digitalRead(sensor))
        {

            Serial.println("hello");

            steps = steps + 1;
            Serial.println(steps);
            while (digitalRead(sensor));
        }
        if (steps >= 10)
        {

            
            
            digitalWrite(motor_right_1, LOW);
            digitalWrite(motor_right_2, LOW);
            digitalWrite(motor_left_1, LOW);
            digitalWrite(motor_left_2, LOW);
            analogWrite(motor_right_speed, 0);
            move_forward(80,80);

            break;
        }
    }
}


///  go back to the right path



#endif
