#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "./FilaJV/FilaJV.h"

/*  Q6 - Concatenar filas

Usando somente algoritmos no TAD fila, escreva uma funcao em C chamada catQueue()
que concatene duas filas. A segunda fila deve ser colocada no final da primeira fila.
Considere os casos em que:
i)    a segunda fila precisa ser preservada;
ii)   a segunda fila não deve ser preservada;
iii)  posso adicionar operacoes extras ao TAD para ganhar eficiencia na concatenacao em ii).

*/


void  printQueues (QUEUE* q1, QUEUE* q2) {
  printf("\nQ1:\t");
  printQueue(q1, 'd');
  printf("\nQ2:\t");
  printQueue(q2, 'd');
  printf("\n\n");
}


void  concatDestructive   (QUEUE* q1, QUEUE* q2) {
  printf("DESTRUCTIVE ");
  while(!(fullQueue(q1)&&emptyQueue(q2))) {
    pushFilaInt(q1,popFilaInt(q2));
  }
}

void  concatConservative  (QUEUE* q1, QUEUE* q2) {
  QUEUE* tempQueue = createQueue();
  int tempInt;
  printf("CONSERVATIVE ");
  while(!(fullQueue(q1)&&emptyQueue(q2))) {
    tempInt = popFilaInt(q2);
    pushFilaInt(q1,tempInt);
    pushFilaInt(tempQueue,tempInt);
  }
  while(!(fullQueue(q2)&&emptyQueue(tempQueue))) {
    pushFilaInt(q2,popFilaInt(tempQueue));
  }
  destroyQueue(tempQueue);
}

void  concatPointers      (QUEUE* q1, QUEUE* q2) {
  printf("POINTERS ");
  q1->rear->next=q2->front;
  q1->rear=q2->rear;
  q1->count+= q2->count;
  q2->count=0;
  q2->front=NULL;
  q2->rear=NULL;
}

int main () {
    
  QUEUE* q1;
  QUEUE* q2;
  int i, size=4, hasManualInput= 0;

  for (i=0;i<3;i++) {

    q1 = createQueue();
    q2 = createQueue();
    fillQueueRandInt(q1, hasManualInput, size);
    fillQueueRandInt(q2, hasManualInput, size);

    printf("\nQUEUES:");
    printQueues(q1, q2);



    printf("AFTER ");
    
    switch (i) {
      case 0:   concatConservative(q1,q2);    break;
      case 1:   concatDestructive(q1,q2);     break;
      case 2:   concatPointers(q1,q2);        break;
      default:  break;
    }
    printf("CONCAT:");
    printQueues(q1, q2);


    destroyQueue(q1);
    destroyQueue(q2);
  }
}
