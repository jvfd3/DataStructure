/*  This program reads a source program and parses it to 
  make sure all opening-closing parentheses are paired.
     Written by:
     Date:
*/
#include <stdio.h>
#include "PilhaJV.h"


//  Error Messages 
const char closMiss[ ] = "Close paren missing at line";
const char openMiss[ ] = "Open paren missing at line";

int main (void)
{
//  Local Definitions 
  STACK* stack;
  char   token;
  char*  dataPtr;
  char   fileID[25];
  FILE*  fpIn;
  int    lineCount = 1;

//  Statements 
  // Create Stack 
  stack = createStack ();
  printf ("Enter file ID for file to be parsed: ");
  scanf  ("%s", fileID);
  
  fpIn = fopen (fileID, "r");
  if (!fpIn)
      printf("Error opening %s\n", fileID), exit(100);

  // read characters from the source code and parse 
  while ((token = fgetc (fpIn)) != EOF )
     {
      if (token == '\n')
         lineCount++;
      if (token == '(' )
         {
          dataPtr = (char*) malloc (sizeof (char));
          *dataPtr = token;                         // Corre��o!!     
      pushStack (stack, dataPtr);
         } // if 
      else
         {
          if (token == ')')
             {
              if (emptyStack (stack))
                 {
                  printf ("%s %d\n", 
                          openMiss, lineCount);
                  return 1;
                 } // if true 
              else
                 popStack (stack);
             } // token == 
         } // else 
     } // while 

  if (!emptyStack (stack))
     {
      printf ("%s %d\n", closMiss, lineCount);
      return 1;
     } // if 

  // Now destroy the stack 
  destroyStack (stack);
  printf ("Parsing is OK: %d Lines parsed.\n", lineCount);
  return 0;
}  // main 

/*  Results
Run 1:
  Enter file ID for file to be parsed: no-errors.txt
  Parsing is OK: 65 Lines parsed.
Run 2:  
  Enter file ID for file to be parsed: open-match.txt
  Open paren missing at line 23
Run 3:
  Enter file ID for file to be parsed: close-match.txt
  Close paren missing at line 46
*/
