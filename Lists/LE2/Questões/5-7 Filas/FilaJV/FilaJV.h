#include <stdlib.h>
#include <stdbool.h>
/*
    QUEUE* fila_inteiros = createQueue();
    int manual=0, size=5;
*/

// Queue ADT Type Defintions 

  typedef struct node {
    void*        dataPtr;
    struct node* next;
  } QUEUE_NODE;

  typedef struct    {
    QUEUE_NODE* front; 
    QUEUE_NODE* rear; 
    int         count; 
  } QUEUE;

#include "FilaJV.c"

//  Prototype Declarations 
  QUEUE* createQueue      (void);
  QUEUE* destroyQueue     (QUEUE* queue);
  bool  enqueue           (QUEUE* queue, void*  itemPtr);
  bool  dequeue           (QUEUE* queue, void** itemPtr);
  bool  queueFront        (QUEUE* queue, void** itemPtr);
  bool  queueRear         (QUEUE* queue, void** itemPtr);
  bool  emptyQueue        (QUEUE* queue);
  bool  fullQueue         (QUEUE* queue);
  int   queueCount        (QUEUE* queue);
  int   popFilaInt        (QUEUE* queue);
  void  printQueue        (QUEUE* queue, int mode);
  void  pushFilaInt       (QUEUE* queue, int dec);
  void  fillQueueRandInt  (QUEUE* queue, int manual, int size);
//End of Queue ADT Definitions