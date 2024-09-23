#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibRecursion(int number);
int fib_mem(int number);
long int fib_table[300];

// For this program, argv[0] is fib, argv[1] is the integer we are calculating the fibonacci for, argv[2] is the method, and argv[3] is the file
   // The methods include: 'r' for recursion, and 'i' for iterative
   
int main(int argc, char* argv[]) { // argc is the argument count and argv is a vector of arguments
   if(argc < 3) {
      printf("[-] Must pass an integer and either 'i' or 'r' as command line arguements\n");
      printf("[-] EXAMPLE: ./fib 5 r\n");
   } // END if(argc < 4)
   else {

      int fib_counter = atoi(argv[1]) - 1;
      
      // strcmp returns 0 if the strings are equal
      if(!strcmp(argv[2], "i")) { // Iterative implementation of fibonacci
         __uint128_t current_number = 1; // __uint128_t can hold up to 18446744073709551615
         __uint128_t prev_number = 0;
         __uint128_t prev_prev_number = 0;

         if(fib_counter == 0) {
            current_number = 0;
         } // END if(fib_counter == 0)
         else {
            for(int i = 1; i < fib_counter; i++) {
               prev_prev_number = prev_number;
               prev_number = current_number;
               current_number = prev_prev_number + prev_number;
            }// END for(int i = 1; i < argv[1]; i++)
         } // END else
         

         // printf("The answer is %lu\n", current_number);
         printf("%lu", current_number);
      } // END if(argv[2] == 'i')
      else if(!strcmp(argv[2], "r")) { // Recursive implementation of fibonacci
         __uint128_t fibonacci_answer = fibRecursion(fib_counter);

         // printf("The answer is %lu\n", fibonacci_answer);
         printf("%lu", fibonacci_answer);
      } // END else else if(argv[2] == 'r')
      else {
         printf("[-] Invalid argument...Must pass in either 'i' or 'r'\n");
         printf("[-] EXAMPLE: ./fib 5 r\n");
      }
   } // END else

   return 0;
}

// Recursive implementation of fibonacci
int fibRecursion(int number) {
   // This is the original implementation of fibonacci using recursion
   if(number == 0) {
      return 0;
   } // END if(number == 0)
   else if(number == 1) {
      return 1;
   } // END else if(number == 1)

   return fibRecursion(number - 1) + fibRecursion(number - 2);
}