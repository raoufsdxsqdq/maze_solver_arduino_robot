#include <Arduino.h>
#include "difinitions.h"
#include "M_operations.h"
#include "U_Sonic.h"
#include "short_path.h"
char *maze_array; // >>>>>>>>>>>>>> array where the maze will be saved
int rest_distance = 0; // >>>>>>>>>>>> variable for the distance  of the condition
int i = 0; //  >>>>>>>>>>>>>   index of the array

void functions(){

for (int i = 2; i < 10; i++){
pinMode(i,OUTPUT);

}

for (int i =10; i < 13; i++)
{

pinMode(i,INPUT);
}
pinMode(Trigo_pin_front, OUTPUT);
pinMode(Trigo_pin_right, OUTPUT);
pinMode(Trigo_pin_left, OUTPUT);
}

void setup() {
   Serial.begin(9600);
functions();
//delay(1000); // >>>>>>>>>>>>>>>>>>>>>>>>> delay for starting
//move_forward();
//delay(500); // >>>>>>>>>>>>>>>>>>>>>>>>> delay for entring the mize
//stopp();
}

void loop() {


US_left(); 
US_right();
US_front();
 // >>>>>>>>>>>>>>>>>>>   start calculations of distance



move_forward(100,100);
if (distance_left < rest_distance && distance_front > rest_distance && distance_right < rest_distance )//Straight path
    {
     move_forward();
    }

if (distance_left > rest_distance && distance_front > rest_distance ||
  distance_right > rest_distance && distance_front > rest_distance ||   //  >>>>>>>>  if is there any intersaction then do
  distance_left > rest_distance && distance_right > rest_distance  ||
   distance_left < rest_distance && distance_front < rest_distance && distance_right < rest_distance){

//move_forward();
//delay(0);



// shortest path will start after the code enter this condition 




  

//CALCULATE_SHORTEST_PATH('L',200);

stopp();


if (distance_left > rest_distance){
*(maze_array +i) = 'L';
turn_left();

}
else if (distance_front > rest_distance){
 *(maze_array +i) = 'S';
move_forward();

}
else if (distance_right > rest_distance){
 *(maze_array +i) = 'R';
turn_right();

}

else {
   *(maze_array +i)= 'B';
   move_backward();
}
i++; // each time move by one index in the array
   }


if ( IR == 1){ //   the IR name should be change since IR is the pin 

path_logic(maze_array,i);

}




}


