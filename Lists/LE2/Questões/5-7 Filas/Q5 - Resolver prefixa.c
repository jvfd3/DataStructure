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

  Por exemplo, a seguinte expressao a uma expressao prefixa cujo resultado e 159.

- + * 9 + 2 8 * + 4 8 6 3

Por exemplo, quando um operador a seguido de dois operandos, tal como + 2 8, colocamos o
resultado, 10, na fila.
Apos a primeira avaliacao da expressao temos:
- + * 9 10 * 12 6 3

Apos a segunda avaliacao, temos:
 - + 90 72 3

Apos a terceira avaliacao, temos:
 - 162 3

Apos a quarta avaliacao, temos:
159

*/


bool  isBetween        (int n, int min, int max) {
  return ((min <= n) && (n <= max));
}

/*  =========== fillQueue ==========
*/
void  fillQueue     (QUEUE* queue, char* cExpression) {
  int i;  
  for (i=0; i<(int)strlen(cExpression);i++) {
    if (isBetween(cExpression[i],48,57)) {
      pushFilaInt(queue, cExpression[i]-48);
    } else {
      pushFilaInt(queue, cExpression[i]);
    }
    // printQueue(queue, 'c');
  }
  printf("Queue filled:\t");
  printQueue(queue, 'c');
  printf("\n");
}

/*  =========== isOperator ============
*/
int isOperator (int token) {
  return ((token=='+')||(token=='-')||(token=='*')||(token=='/'));  //boolean return
  
  /* // switch return
  switch (token) {
    case '+':
    case '-':
    case '*':
    case '/': return 1;
  }
  return 0;
 */
}

/*  ============ isNumber ===============
*/
int isNumber (int token) {
  return ((token>=0)&&(token<=9));  //Boolean return
  // (probably the parentheses are useless, but I like them that way)

  /* //if return
  if ((token>='0')&&(token<='9')) {
    return 1;
  }
  return 0;
  */
}

void fillPrefix (int manual, char* prefix) {
  if (manual) {
    strcpy(prefix, "Not Yet Implemented");
  } else {
    strcpy(prefix, "- + * 9 + 2 8 * + 4 8 6 3");
  }
  printf("\n\nYour prefix expression is: \"%s\"\n", prefix);
}

void  printString      (char* string) {  // simply prints a string aesthetically
  printf("->%s<-\n", string);
}

/* 
int   opNumSize        (char* s) {
  int i, cont=0;
  for (i=0; s[i]!='\0';i++) {  // Runs through all characters of the string
    if (isOperator(s[i])||isNumber(s[i])) {
      printf("%d ", cont);
      cont++;
    }
  }
  return cont;
}
 */

void  cleanNonNumNonOperators (char* s) {     // turns punctuation into spaces " ' , . - { [ ( ) ] } @ ! #
  int i;
  // printString(s);
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    if (!(isNumber(s[i])||isOperator(s[i]))&&(s[i]!='\0')) {
      s[i] = ' ';
    }
  }
  printf("After cleanNonNumNonOperators\t");
  printString(s);
}

int   spaceCount       (char* s) {
  int i, cont=0;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    if (s[i]==' ') {
      cont++;
    }
  }
  return cont;
}

void  spacelessSwap    (char* s) {            // remove all of the spaces
  // this part of the code is chaos. don't stare at him too much
  int i=0, j, spaces=spaceCount(s);
  do {
  // printf("%dspaces\n", spaces);
        // printString(s);
    if (s[i]==' ') {
      for (j=i; j<(int) strlen(s);j++) {
        // swap (&(s[j]), &(s[j+1]));
        // i'm sweeping dirt over the \0
        s[j]    = s[j] + s[j+1];
        s[j+1]  = s[j] - s[j+1];
        s[j]    = s[j] - s[j+1];

        // printString(s);
      }
      spaces--;
      i--;
    }
    i++;
  } while (spaces!=0);


  printf("After spaceless\t\t");
  printString(s);
}

void  cleanString      (char* limpa, char* original) {   //Clean all non-"normal" characters of the strings
  
  strcpy(limpa, original);
  
  printf("\nBefore cleanString\t");
  printString   (limpa);
  // cleanNonNumNonOperators(limpa);        // turns punctuation into spaces " ' , . - { [ ( ) ] } @ ! #
  spacelessSwap (limpa);           // remove all of the spaces
  // printString   (original);
  // printString   (limpa);
  
  printf("\nAfter cleanString\t");
  printString   (limpa);
}

int   doOperation      (QUEUE* worm) {
  int a = popFilaInt(worm), b = popFilaInt(worm), c = popFilaInt(worm);
  switch (a) {
    case '+': return b+c;
    case '-': return b-c;
    case '*': return b*c;
    case '/': return b/c;
  }
  return 0;
}

void  worm2Temp         (QUEUE* worm, int* x, int* y, int* z) {

  *x = popFilaInt(worm);
  *y = popFilaInt(worm);
  *z = popFilaInt(worm);
      pushFilaInt(worm, *x);
      pushFilaInt(worm, *y);
      pushFilaInt(worm, *z);
}

void printWormQueue (QUEUE* worm, QUEUE* queue) {
  printf("Worm:\t");
  printQueue(worm, 'd');
  printf("\nQueue:\t");
  printQueue(queue, 'd');
  printf("\n");
}

int   isValidOperation         (QUEUE* worm) {
  int a, b, c;
  worm2Temp (worm, &a, &b, &c);
  return (isOperator(a)&&isNumber(b)&&isNumber(c));
}

void fillWorm (QUEUE* worm, QUEUE* queue) {
  int i;
  for (i=0; i<3; i++) {
    pushFilaInt(worm, popFilaInt(queue));
  }
}

void printCounters (int c, int tcm, int ce, int w) {
  printf("==>Counter: %d\tTempCounter: %d\tCounterEnq: %d\tCounterWorm: %d<==\n", c, tcm, ce, w);
}

void runQueue          (QUEUE* queue) {
  printf("RunningQueue.\n");
  int cont=0, temp;
  int tempCount=queueCount(queue);
  QUEUE* worm = createQueue();
  if (queueCount(queue)==0) {
    printf("Vazia ");
  } else {
    
    printCounters (cont, tempCount, queueCount(enqueue), queueCount(worm));
    while ((cont<=tempCount)&&(tempCount!=1)) {
      cont++;
      if (queueCount(worm)==0) {
        if ((tempCount-cont)>=3) {
          printf("3 at once\n");
          fillWorm(worm, queue);
          printWormQueue(worm,queue);
          printf("=>Cont1: <=\n");
          cont+=2;
          printCounters (cont, tempCount, queueCount(queue), queueCount(worm));
        } else {
          while (cont<=tempCount) {
            pushFilaInt(queue,popFilaInt(queue));
            printf("preparing new round.\n");
            printWormQueue(worm,queue);
            printf("=>Cont2: <=\n");
            printCounters (cont, tempCount, queueCount(queue), queueCount(worm));
            cont++;
          }
          tempCount=queueCount(queue);
          cont=0;
          printWormQueue(worm, queue);
          printf("XXXXXXXXXXXXX END OF RUN XXXXXXXXXXXXX\n");
        }
      }
      if (isValidOperation(worm)) {
        printf("Vomiting\n");
        pushFilaInt(queue, doOperation(worm));
        printWormQueue(worm,queue);
      } else if(queueCount(worm)==3) {
        printf("Cagando e andando:\n");
        
        // printWormQueue(worm, queue);
        temp= popFilaInt(queue);     pushFilaInt(worm, temp);
        // printWormQueue(worm, queue);
        temp= popFilaInt(worm);      pushFilaInt(queue, temp);
        printWormQueue(worm,queue);
        // cont++;
      }
      printf("=>Cont3: <=\n");
    printCounters (cont, tempCount, queueCount(queue), queueCount(worm));
      printWormQueue(worm, queue);
      // if (cont==tempCount) {
      //   tempCount=queueCount(queue);
      // }
    }
    printf("Out of the loop.\n");
    printWormQueue(worm,queue);
  }
  printf("\n");
}

void solvePrefix (char* cExpression) {
  QUEUE*  fila = createQueue();
  // QUEUE*  worm = createQueue();

  fillQueue (fila, cExpression);
  runQueue  (fila);
  // int i;
  // int result;
  // int cont = 0;
  
  /*  Done:
  primeiro eu coloco todos os caracteres na fila
  fazer função baseada no print para poder percorrer todos esses elementos
  se o contador for 0, preenche a worm com 3 elementos

  */
  /*
  se ela tiver Operator Operator Number, ela retorna o resultado,
  enquanto a fila não tiver apenas um elemento:
  a worm avança 1 a 1
  senão, ela retorna o primeiro elemento inserido.
  a worm vai percorrer toda a fila
  se ela chegar no ultimo elemento, ela dá unstack de tudo


  */

  destroyQueue  (fila);               //  Destroi Fila
}

int main () {
  int     manual=0, SIZE=50;
  char    prefixExpression[SIZE], cleanedExpression[SIZE];

  fillPrefix    (manual,      prefixExpression);         //Create all strings that are going to be tested
  cleanString   (cleanedExpression, prefixExpression);         //Clean all non-"normal" characters of the strings
  solvePrefix   (cleanedExpression);
  printf("fim");
}
