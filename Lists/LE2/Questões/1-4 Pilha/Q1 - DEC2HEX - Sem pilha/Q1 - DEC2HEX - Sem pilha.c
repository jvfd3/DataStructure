#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "mainPilha.c"

/*  Q1 - DEC2HEX

Escreva um programa que converta um numero decimal em hexadecimal,
usando o metodo de divisoes sucessivas e uma pilha.

OK - Obs. Lembrar que caso o resto da divisao for 10, 11, 12, 13, 14 ou 15, o digito correspondente devera ser A, B, C, D, E ou F.

*/
int hexChar(int dec) {
  // if (dec<10) {
  //   return dec+'0';
  // }

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

void printFinalHex (int size, int* pArray) {
  // printf("{");
  // 1 to dec and hex
  // 0 to (dec/hex)
  int j;
  if(0) {
    for (j=size-1; j>=-0; j--) {
      checkValue(pArray[j]);
    }
  } else {
  // printf("{");
  //   for (j=size-1; j>=-0; j--) {
  //     printf("%d,", pArray[j]);
  //   }
    for (j=size-1; j>=-0; j--) {
      printf("%c", pArray[j]);
    }
  }
}

void dec2hex(int dec) {
  int newDec=dec, hexASCII[5], i=0;
  
  printf("%d->\t", dec);

  while (newDec > 0) {
    hexASCII[i] = hexChar(newDec%16);
    // checkValue(hexChar(newDec%16));
    newDec = newDec/16;
    i++;
  }
  hexASCII[i]= hexChar(newDec);
  // printf(" | ");
  printFinalHex (i, hexASCII);

  printf("\t<-%d\n", dec);
}

int main () {
  int i;
  for (i=500; i<512; i++) {
    dec2hex(i);
  }
}
