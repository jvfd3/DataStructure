//  Header file for stack ADT.

#include <stdlib.h>
#include <stdbool.h>

#include "StackFunctions.c"     /*All Functions*/

//  Stack ADT Type Defintions 
typedef struct node2 {
  void*        dataPtr;
  struct node2* link;
} STACK_NODE;

typedef struct stack{
  int         count; 
  STACK_NODE* top; 
} STACK;

/*  ADT Prototype Declarations */
STACK* createStack  (void);
STACK* destroyStack (STACK* stack);
int    stackCount   (STACK* stack);
void*  popStack     (STACK* stack);
void*  stackTop     (STACK* stack);
bool   emptyStack   (STACK* stack);
bool   fullStack    (STACK* stack);
bool   pushStack    (STACK* stack, void* dataInPtr);

