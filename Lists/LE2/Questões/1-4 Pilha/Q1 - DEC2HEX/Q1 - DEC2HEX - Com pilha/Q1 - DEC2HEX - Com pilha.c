#include <stdio.h>
#include <stdlib.h>

#include "PilhaJV.h"

/*  Q1 - DEC2HEX

Escreva um programa que converta um numero decimal em hexadecimal,
usando o metodo de divisoes sucessivas e uma pilha.

OK - Obs. Lembrar que caso o resto da divisao for 10, 11, 12, 13, 14 ou 15, o digito correspondente devera ser A, B, C, D, E ou F.

*/


/* //Testing void pointers
void testingVoidPointer(int dec) {

  // variable used just for aesthetics purposes
  int embelezamento=dec;
  // beginning of the code
  printf("%d->\t\n", embelezamento);
  // creating the pointer for a stack.
  STACK *pilha = createStack();

  // I'll try to push and pop;
  // I'll need a dataPtr to malloc and then send it's pointer to be pushed.

  int* dataPtr;
  dataPtr =(int*) malloc (sizeof(int));

  // Now I'll put a value 50 to the content of this pointer
  *dataPtr = dec;

  // Only now I can push it, but casting it to be a void
  pushStack(pilha, (void*) dataPtr);
  printf("%d was pushed\n", *dataPtr);

  // I'll now pop the value inserted but for it i'll need a void* variable (or a casting to another variable)
  void* aux;
  aux = popStack(pilha);

  // Converting aux to a more accessible pointer
  int* intPtr = (int*) aux;

  // Now I'll print the interior of intPtr
  printf("%d was popped\n", *intPtr);

  // finishing with aesthetics
  printf("\t<-%d\n", embelezamento);

}
 */


int   hexChar(int dec) {
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

void  pushInt       (STACK* pilha, int dec) { // Function that pushes an int
  
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

void  insertValues  (STACK* pilha, int dec) { // Function to insert all ascII into a stack
  
  // While the decimal value is not 0...
  while (dec>0) {
    // It will push it's remainder of 16 (converted to hexASCII) 
    pushInt(pilha, hexChar(dec%16));
    // and then receive the quotiente of itself divided by 16
    dec/=16;
  }
}

int   popInt        (STACK* pilha) { // Function that pops an int
   // I'll now pop the value inserted but for it i'll need a void* variable (or a casting to another variable)
  void* aux;
  aux = popStack(pilha);

  int* intPtr = (int*) aux;  // Converting aux to a more accessible pointer

  // printf("%c was popped\n", *intPtr);  // Now I'll print the interior of intPtr
  printf("%c", *intPtr);
  return *intPtr;
}

void  popValues     (STACK* pilha) {     //Function tu empty all the stack
  int x;
  while (!emptyStack(pilha)) {    // While the stack is not empty
    //pops it 
    x = popInt(pilha);
  }
}

void  dec2hex       (int dec) {

  int embelezamento=dec;                    // variable used just for aesthetics purposes
  printf("%d->\t", embelezamento);        // beginning of the code
  STACK *pilha = createStack();             // creating the pointer for a stack.

  insertValues(pilha, dec); 
  
  popValues(pilha);


  // printf("\t<-%d", embelezamento);        // finishing with aesthetics
  printf("\n");
}

int   main () {
  int i;
  for (i=1; i<555; i++) {
    dec2hex(i);
  }
  
  // dec2hex(162254319);
}
