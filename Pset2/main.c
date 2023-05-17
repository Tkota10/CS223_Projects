//Main.c
//Tarun Kota
//CS223 Pset #2
//February, 9th, 2023
// The purpose of this program is that it's the main file that lays out all
// the logic behind how the game of life works. Specifically, it reads in 
// arguments from the user and calls shouldDie, isAlive and advanceTime functions
// to carry out game of life. Finally, it also formats the print output correctly
// to meet the desired specifications.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

int main(int argc, char* argv[]){


   //Exits program if less than 4 arguments are inputted.
   if (argc < 4) {
      return 1;
   }

   // Code Segment that checks if time_steps input is a integer
   // and then input that variable into time_steps variable.
   int time_steps; 
   if (atoi(argv[1]) == 0){
      if (argv[1][0] != '0') { //Would it be a string?
         return 1;
      } else if (argv[1][1] != '\0') {
         return 1;
      } else {
         time_steps = atoi(argv[1]);;
      }
   } else {
      time_steps = atoi(argv[1]);
   }
   //Code Segment that checks if game_size input is a integer
   //and then input that variable into game_size variable.
   int game_size;
   if (atoi(argv[2]) == 0) {
      if (argv[2][0] != '0'){ //Would it be a string?
         return 1;
      } else if (argv[2][1] != '\0') {
         return 1;
      } else { 
         game_size = atoi(argv[2]);;
      }
   } else {
      game_size = atoi(argv[2]);
   }
   if ((time_steps < 0) || (game_size <= 0)){
      return 1;
   }
   

   //Code segment to check if the inputted string contains
   //anything outside of a zero or 1. If conditions are met,
   //put string into a integer array. 
   char* start = argv[3];
   int new[game_size];
   for (int i = 0; i < game_size; i++) {
      if (start[i] == '0'){
         new[i] = 0;   
      } else if (start[i] == '1') {
         new[i] = 1;
      } else {
         return 1;
      }
   }

   //Code block to see if the length of the 
   //string is bigger than the game_size.
   int count = 0;
   for (int i = 0; start[i] != '\0'; i++) {
      count++; 
   }
   if (game_size > count) {
      return 1;
   }

   //First print the initial values!
   printf("Initial values                   [");
   for (int i = 0; i < (game_size -1); i++){
      printf("%d, ", new[i]);
   }
   printf("%d]\n",new[game_size -1]);

   //Code segment that prints out all the timesteps
   //that needs to be printed out.
   for (int i = 0; i < time_steps; i++) {
      (advanceTime (new, 0, game_size)) ;
      printf("Values after timestep");
      printf(" %-11d", i+1);
      printf("%c", '[');
      for(int j = 0; j < game_size - 1; j++) {
         printf("%d, ", new[j]);
      }
      printf("%d]\n", new[game_size -1]);
   }
   return 0;

}