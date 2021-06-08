#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "FilaJV/FilaJV.h"

/*  Q5 - Resolver prefixa

  Escreva um programa em C para avaliar o resultado de uma expressao prefixa.

  O programa devera utilizar uma fila para armazenar os elementos da expressao
  (operadores e operandos).
  O processo de avaliacao consiste em
  fazer a leitura dos elementos armazenados (tokens) na fila,
  substituindo-se, sempre que encontrada,
  uma sequencia de um operador seguida de dois operandos
  pelo resultado da operacao indicada.
  Caso contrario, os elementos lidos sao reinseridos na fila.
  O processo e repetido ate a fila conter um unico elemento
  que e o resultado da expressao.

  Por exemplo, a seguinte expressao a uma expressao prefixa cujo resultado a 159.

- + * 9 + 2 8 * + 4 8 6 3

Por exemplo, quando um operador a seguido de dois operandos, tal como + 2 8, colocamos o resultado, 10, na fila. 
Apos a primeira avaliacao da expressao temos:
- + * 9 10 * 12 6 3

Apos a segunda avaliacao, temos:
 - + 90 72 3

Apos a terceira avaliacao, temos:
 - 162 3

Apos a quarta avaliacao, temos:
159

*/

int main () {
  // Cria uma fila e aloca memoria aos dados 
  QUEUE* fila = createQueue();
  int manual=0;
  
  fillQueue     (fila, manual); // Preenche a fila 
  printQueue    (fila);               //  Imprime os numeros da fila

  
  destroyQueue  (fila);               //  Destroi Fila
  printf("fim");
}
