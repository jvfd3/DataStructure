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

int main (void) {

  int     boardSize /* = getSize () */;
  STACK*  stack;

  // test for all of the boardsizes available
  for (boardSize=4; boardSize<=8; boardSize++) {
    stack = createStack ();
    fillBoardMulti  (stack, boardSize);
    destroyStack    (stack);
  }
}