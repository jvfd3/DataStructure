//	Header file for stack ADT.

#include <stdlib.h>
#include <stdbool.h>

#include "StackADTTypeDefinitions.h"		/* Stack ADT Definitions */

/*	ADT Prototype Declarations */
STACK* createStack  (void);
bool   pushStack    (STACK* stack, void* dataInPtr);
void*  popStack     (STACK* stack);
void*  stackTop     (STACK* stack);
bool   emptyStack   (STACK* stack);
bool   fullStack    (STACK* stack);
int    stackCount   (STACK* stack);
STACK* destroyStack (STACK* stack);

#include "CreateStack.h"		/* Create Stack */
#include "PushStack.h"		/* Push Stack */
#include "PopStack.h"		/* Pop Stack */
#include "RetrieveStackTop.h"		/* Retrieve Stack Top */
#include "EmptyStack.h"		/* Empty Stack */
#include "FullStack.h"		/* Full Stack */
#include "StackCount.h"		/* Stack Count */
#include "DestroyStack.h"		/* DestroyStack */
