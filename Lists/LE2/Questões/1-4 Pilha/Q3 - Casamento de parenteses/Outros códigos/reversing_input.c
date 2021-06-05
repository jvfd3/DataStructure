/*  This program reverses a list of integers read
  from the keyboard by pushing them into a stack
  and retrieving them one by one
     Written by:
     Date:
*/
#include <stdio.h>
#include <stdbool.h>
#include "PilhaJV.h"


int main (void)
{
//  Local Definitions 
  int  done = false;
  int* dataPtr ;

  STACK* stack ;

//  Statements 
  // Create a stack and allocate memory for data 
  stack = createStack ();

  // Fill stack 
  while (!done)
     {
      dataPtr = (int*) malloc (sizeof(int));
      printf ("Enter a number: <EOF> to stop: ");
      if ((scanf ("%d" , dataPtr)) == EOF 
             || fullStack (stack))
         done = true;
      else
         pushStack (stack, dataPtr);
     } // while 

//  Now print numbers in reverse 
  printf ("\n\nThe list of numbers reversed:\n");
  while (!emptyStack (stack))
     {
      dataPtr = (int*)popStack (stack);
      printf ("%3d\n", *dataPtr);
      free (dataPtr);
     } // while 

//  Destroying Stack 
  destroyStack (stack);
  return 0;
}  // main 

/*  Results 
Enter a number: <EOF> to stop: 3
Enter a number: <EOF> to stop: 5
Enter a number: <EOF> to stop: 7
Enter a number: <EOF> to stop: 16
Enter a number: <EOF> to stop: 91
Enter a number: <EOF> to stop:

The list of numbers reversed:
 91
 16
  7
  5
  3
*/