#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "FilaJV.h"

int main() {
  
  // Cria uma fila e aloca memoria aos dados 
  QUEUE* fila_inteiros = createQueue();
  int manual=0, size=5;
  
  fillQueue     (fila_inteiros, manual, size); // Preenche a fila 
  printQueue    (fila_inteiros, 'd');               //  Imprime os numeros da fila

  
  destroyQueue  (fila_inteiros);               //  Destroi Fila
  printf("fim");
}