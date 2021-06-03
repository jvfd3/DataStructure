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
  int newDec=dec;
  int* dataPtr;
  printf("%d->\t", dec);

  STACK *pilha;
  while (newDec > 0) {
  printf("1");
    dataPtr = malloc (sizeof(int));
    *dataPtr = hexChar(newDec%16);
    pushStack(pilha, (void*) &dataPtr);
    newDec = newDec/16;
  }
  printf("chega");
  // dataPtr = malloc (sizeof(int));
  // *dataPtr = hexChar(newDec);
  // pushStack(pilha, (void*) &dataPtr);
  
  print(pilha);

  printf("\t<-%d\n", dec);
}

int main () {
  int i;
  /* for (i=1; i<17; i++) {
    dec2hex(i);
  } */
  
  dec2hex(2);
}
