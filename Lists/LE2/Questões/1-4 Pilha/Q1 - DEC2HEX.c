#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "PilhaJV.h"

/*  Q1 - DEC2HEX

Escreva um programa que converta um numero decimal em hexadecimal,
usando o metodo de divisoes sucessivas e uma pilha.

OK - Obs. Lembrar que caso o resto da divisao for 10, 11, 12, 13, 14 ou 15, o digito correspondente devera ser A, B, C, D, E ou F.

*/

int hexChar(int dec) {
  switch (dec) {
    case 10:  return 'A';
    case 11:  return 'B';
    case 12:  return 'C';
    case 13:  return 'D';
    case 14:  return 'E';
    case 15:  return 'F';
    default:  return dec +'0' ;
  }
}

void checkValue (int value) {
  printf("(%d/%c)", value, value);
}

// void printFinalHex (int size, STACK_NODE* pilha) {
//   int j;
//   char c;
//   for (j=0; j<=size; j++) {
//     c=(char)popStack(pilha);
//     printf("(%c/%d)", c, c);
//   }
// }

void dec2hex(int dec) {

  STACK *pilha = createStack();
  int newDec=dec, temp;
  int* dataPtr;
  
  printf("%d->\t", dec);

  while (newDec > 15) {
    temp = hexChar(newDec%16);
    dataPtr = malloc (sizeof(int));
    *dataPtr = temp;
    pushStack(pilha, (void*) &dataPtr);
    printf("%c.", temp);
    newDec = newDec/16;
  }
  temp = hexChar(newDec);
  printf("%c.", temp);
  dataPtr = malloc (sizeof(int));
  *dataPtr = temp;
  pushStack(pilha, (void*) &dataPtr);
  
  print(pilha);

  printf("\t<-%d\n", dec);
}

int main () {
  // int i;
  // for (i=1; i<65; i++) {
  //   dec2hex(i);
  // }
  
  dec2hex(18);
}
