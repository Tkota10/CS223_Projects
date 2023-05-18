#include <stdio.h>

typedef char* string;

int main(int argc, string argv[] ) {

   char* exe_name = argv[1]; //Initialized exe_name to give me a mechanism of checking the command line arguments.
   char str[129]; //Initialized str to consider up 129 characters.
   str[0] = 5; //Intialize the string to be a random number
   if (argc > 1){ //this is to consider the case of where this is more than 1 command line argument.
      printf("Hello, %s\n", exe_name);
   } else {
   
   printf( "What is your name? ");
   scanf("%129[^\n]",str); //Getsthe maximum input of 129
  
   if (str[0] == 5){ //If the user inputs nothing (return line), than the program finishes.
      return -1;
   }
   printf( "Hello, "); //all other inputs.
   puts( str );
}
   
   return 0; //ends program
}



