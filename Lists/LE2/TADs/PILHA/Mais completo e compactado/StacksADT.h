//	Header file for stack ADT.

#include <stdlib.h>
#include <stdbool.h>

//	Stack ADT Type Defintions 
	typedef struct node2 
	   {
	    void*        dataPtr;
	    struct node2* link;
	   } STACK_NODE;

	typedef struct
	   {
	    int         count; 
	    STACK_NODE* top; 
	   } STACK;

/*	ADT Prototype Declarations */
STACK* createStack  (void);
bool   pushStack    (STACK* stack, void* dataInPtr);
void*  popStack     (STACK* stack);
void*  stackTop     (STACK* stack);
bool   emptyStack   (STACK* stack);
bool   fullStack    (STACK* stack);
int    stackCount   (STACK* stack);
STACK* destroyStack (STACK* stack);

#include "StackFunctions.h"     /*All Functions*/
