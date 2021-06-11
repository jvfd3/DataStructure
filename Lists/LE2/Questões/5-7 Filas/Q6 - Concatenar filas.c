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

/*
Organizando o pensamento:
preciso concatenar. fim.
conservando e não conservando a segunda

create12
input 12
print 12
concatDestructive
explode12

create12
input 12
print 12
concatConservative
explode12
*/

int main () {
    
  QUEUE* q1;
  // QUEUE* q2;
  // int i;

  
  q1 = createQueue();
  fillQueueRandInt(q1, 0, 4);
  // printQueue(q1, 'd');


  /* for (i=0;i<2;i++) {
    q1 = createQueue();
    q2 = createQueue();
    fillQueueRandInt(q1, 0, 4);
    fillQueueRandInt(q2, 0, 4);
    printQueue(q1, 'd');
    printQueue(q2, 'd');

    (i)? concatDestructive(q1,q2):concatConservative(q1,q2);

    destroyQueue(q1);
    destroyQueue(q2);
  } */
}
