#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../PilhaJV/PilhaJV.h"
#include "./8-Rainhas-JV/8RainhasTADJV.h"         /* Eight Queens everything*/

/*  Q4 - 8 rainhas

  Escreva um programa para encontrar todas as solucoes para o problema das 8 rainhas.
  Observe que nao basta apenas uma configuracao viavel, queremos descobrir todas elas.
  O programa deve ser capaz de continuar a busca apos a primeira configuracao valida.
  Contar o numero de solucoes encontradas e imprimir essas configuracoes na tela.

*/

/*  This program tests the eight queens algorithm. Eight 
  queens is a classic chess problem in which eight 
  queens are placed on a chess board in positions 
  such that no queen can capture another queen.
     Written by:
     Date:
*/

void  pushInt          (STACK* pilha, int dec) { // Function that pushes an int
  
  // I'll try to push and pop;
  // I'll need a dataPtr to malloc and then send it's pointer to be pushed.
  int* dataPtr;
  dataPtr =(int*) malloc (sizeof(int));

  // Now I'll put a value 50 to the content of this pointer
  *dataPtr = dec;

  // Only now I can push it, but casting it to be a void
  pushStack(pilha, (void*) dataPtr);
  // printf("%c was pushed\n", *dataPtr);
}

int   popInt           (STACK* pilha) { // Function that pops an int
   // I'll now pop the value inserted but for it i'll need a void* variable (or a casting to another variable)
  void* aux;
  aux = popStack(pilha);

  int* intPtr = (int*) aux;  // Converting aux to a more accessible pointer

  // printf("%c was popped\n", *intPtr);  // Now I'll print the interior of intPtr
  // printf("%c", *intPtr);
  return *intPtr;
}

int main (void) {
  /*  Local Definitions */

  // int     boardSize = getSize ();
  int     boardSize = 4;
  STACK*  stack     = createStack ();

  /*  Statements */  

  // fillBoard    (stack, boardSize);
  // printBoard   (stack, boardSize);
  
  fillBoardMulti    (stack, boardSize);
  printBoard   (stack, boardSize);

  destroyStack (stack);
  printf("\nWe hope you enjoyed Eight Queens.\n");
  
}  /* main */

/*  Results
Welcome to Eight Queens. You may select
a board size from 4 x 4 to 8 x 8. I will
then position a queen in each row of the
board so no queen may capture another
queen. Note: There are no solutions for
boards less than 4 x 4.

Please enter the board size: 4

Place queens in following positions:
Row 1-Col 2:    | Q |   |   |
Row 2-Col 4:    |   |   | Q |
Row 3-Col 1:  Q |   |   |   |
Row 4-Col 3:    |   | Q |   |

We hope you enjoyed Eight Queens.
*/

