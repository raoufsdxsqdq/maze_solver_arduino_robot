#include <Arduino.h>

void CALCULATE_SHORTEST_PATH(char MAZE_ARRAY[], int SIZE_OF_ARRAY)
{
  /*ONCE THE ROBOT COMPLETES THE MAZE THE FINAL SHORTEST PATH CALCULATED
  IS STORED IN THE ROBOT MEMORY.THIS SHORTEST PATH IS USED TO COMPLETE
  THE SAME MAZE IN SHORTEST AMOUNT OF TIME.(L :LEFT, R:RIGHT, B:BACK,S:STRAIGHT)
  BELOW ARE THE FEW SUBSTITUTIONS TO CONVERT FULL MAZE PATH TO ITS 
  SHORTEST PATH:
  LBL = S
  LBR = B
  LBS = R
  RBL = B
  SBL = R
  SBS = B
  LBL = S */
  
  
  char ACTION;
  
  for(int i = 0; i <= SIZE_OF_ARRAY-2; i++)
    {
      ACTION = MAZE_ARRAY[i];
           
      if(ACTION == 'B')
        {
          if(MAZE_ARRAY[i-1]== 'L' && MAZE_ARRAY[i+1] == 'R')
            {
              MAZE_ARRAY[i] = 'B';
              MAZE_ARRAY[i-1] = 0;
              MAZE_ARRAY[i+1] = 0;
              //REARRANGE(MAZE_ARRAY,SIZE_OF_ARRAY,i-1,i,i+1); 
            }

           if(MAZE_ARRAY[i-1]== 'L' && MAZE_ARRAY[i+1] == 'S')
            {
              MAZE_ARRAY[i] = 'R';
              MAZE_ARRAY[i-1] = 0;
              MAZE_ARRAY[i+1] = 0;
             // REARRANGE(MAZE_ARRAY,SIZE_OF_ARRAY,i-1,i,i+1);
            }

            if(MAZE_ARRAY[i-1]== 'R' && MAZE_ARRAY[i+1] == 'L')
            {
              MAZE_ARRAY[i] = 'B';
              MAZE_ARRAY[i-1] = 0;
              MAZE_ARRAY[i+1] = 0;
             // REARRANGE(MAZE_ARRAY,SIZE_OF_ARRAY,i-1,i,i+1);         
            }

            if(MAZE_ARRAY[i-1]== 'S' && MAZE_ARRAY[i+1] == 'L')
            {
              MAZE_ARRAY[i] = 'R';
              MAZE_ARRAY[i-1] = 0;
              MAZE_ARRAY[i+1] = 0;
             // REARRANGE(MAZE_ARRAY,SIZE_OF_ARRAY,i-1,i,i+1);             
            }

            if(MAZE_ARRAY[i-1]== 'S' && MAZE_ARRAY[i+1] == 'S')
            {
              MAZE_ARRAY[i] = 'B';
              MAZE_ARRAY[i-1] = 0;
              MAZE_ARRAY[i+1] = 0;
             // REARRANGE(MAZE_ARRAY,SIZE_OF_ARRAY,i-1,i,i+1);             
            }

            if(MAZE_ARRAY[i-1]== 'L' && MAZE_ARRAY[i+1] == 'L')
            {
              MAZE_ARRAY[i] = 'S';
              MAZE_ARRAY[i-1] = 0;
              MAZE_ARRAY[i+1] = 0;
            //  REARRANGE(MAZE_ARRAY,SIZE_OF_ARRAY,i-1,i,i+1);
            }
            
          i = -1;
        }
       
       delay(100);   
    }
}
  
  
  
void REARRANGE(char MAZE_ARRAY[], int SIZE_OF_ARRAY){
//char old;
for (int i =0; i < SIZE_OF_ARRAY; i++){


MAZE_ARRAY[i-1] = MAZE_ARRAY[i];
MAZE_ARRAY[i] = MAZE_ARRAY[i+1];



}
  
}  
  