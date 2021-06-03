
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  Header file for stack ADT.
#include "PilhaJV.C"


//  Stack ADT Type Defintions 
typedef struct node {
  void*        dataPtr;
  struct node* link;
} STACK_NODE;

typedef struct stack{
  int         count; 
  STACK_NODE* top; 
} STACK;

//  Prototype Declarations
void   print        (STACK* stack);

STACK* createStack  (void);
STACK* destroyStack (STACK* stack);
int    stackCount   (STACK* stack);
void*  popStack     (STACK* stack);
void*  stackTop     (STACK* stack);
bool   emptyStack   (STACK* stack);
bool   fullStack    (STACK* stack);
bool   pushStack    (STACK* stack, void* dataInPtr);

