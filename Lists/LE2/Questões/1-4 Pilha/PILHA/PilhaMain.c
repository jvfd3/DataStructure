/*  This program is a test driver to demonstrate the 
  basic operation of the stack push and pop functions. 
     Written by: 
     Date:       
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//  The following includes are not shown in the text
#include "PilhaFunctions.h"

//  Structure Declarations
typedef struct node {
  char data;
  struct node *link;
} STACK_NODE;

//  Prototype Declarations
void insertData(STACK_NODE **pStackTop);
void print(STACK_NODE **pStackTop);

bool push(STACK_NODE **pList, char dataIn);
bool pop(STACK_NODE **pList, char *dataOut);


int main(void) {
//  //  Local Definitions
//  STACK_NODE *pStackTop;
//
//  //  Statements
//  printf("Beginning Simple Stack Program\n\n");
//
//  pStackTop = NULL;
//  insertData(&pStackTop);
//  print(&pStackTop);
//
//  printf("\n\nEnd Simple Stack Program\n");
//  return 0;
} // main

/*  Results
Beginning Simple Stack Program

Creating characters: QMZRHLAJOE
Stack contained:     EOJALHRZMQ

End Simple Stack Program
*/
