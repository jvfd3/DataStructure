#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../PilhaJV/PilhaJV.h"
#include "../../StringManipulationJV.c"

/*  Q2 - Palindromo

Um palindromo eh uma string que pode ser lida para frente e para tras com o mesmo resultado.
Por exemplo, as seguintes frases sao palindromos:

A base do teto desaba.
A diva em Argel alegra-me a vida.
Adias a data da saida.
Socorram-me, subi no onibus em Marrocos.

Observe que nos palindromos se deve ignorar o espacamento, a pontuacao, e as diferencas entre letras maiusculas e minusculas.
Escreva uma funcao para testar se uma string eh um palindromo usando uma pilha. A ideia eh armazenar os caracteres da string
na pilha e recuperar eles formando uma nova string. Depois comparar a nova string com a string original. Teste a sua funcao
com os exemplos mostrados acima.

*/

void  selectString     (int choice, char* string) {   //Create all strings that are going to be tested

  // Selecting which string will be chosen

  switch (choice) {
    case 1:   strcpy(string,      "A base do teto desaba.");                    break;
    case 2:   strcpy(string,      "A diva em Argel alegra-me a vida.");         break;
    case 3:   strcpy(string,      "Adias a data da saida.");                    break;
    case 4:   strcpy(string,      "Socorram-me, subi no onibus em Marrocos.");  break;
    default:  strcpy(string,      ""); break;
  }

}

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

void  empilha          (STACK* pilha, char* s) {  //  insert all characters of a string in a stack
  int i;
  for (i=0;i<(int) strlen(s);i++) {
    pushInt(pilha, s[i]);
    // printf("Pushing: (%d, %d, %c)\n", &s[i], s[i], s[i]);
  }
}

void  desempilha       (STACK* pilha, char* s) {
  // printf("Popping->\n");

  int i=0;
  do {
    // printf("(%d)\t", pilha->count);
    s[i]=popInt(pilha);
    s[i+1]='\0';
    // printf("unpopped:\t%c\n", s[i]);
    // printf("during desempilha:\t");
    // printString (s);
    i++;
  } while (!emptyStack(pilha));

  printf("after desempilha:\t");
  printString (s);
  // printf("\n<-Popping\n");
}

void  invertString     (char* limpa, char* invertida) {
  STACK* pilha = createStack();
  empilha     (pilha, limpa);
  desempilha  (pilha, invertida);

  // printf      ("After invertString\t");
  // printString (invertida);

}

int   palindromeCheck  (char* limpa, char* invertida) {
  // printf("samesize: %d\n", sameSize (limpa, invertida));
  // printf("samecharacters: %d\n", sameCharacters (limpa, invertida));
  // samesize may be useless
  if (sameSize(limpa, invertida)) {
    if (sameCharacters(limpa, invertida)) {
      return 1;
    }
  }
  return 0;
}

void  isPalindrome     (char* original, char* limpa, char* invertida) {

  // printf("isPalindrome:\t%d\n", isPalindrome(limpa, invertida));
  if (palindromeCheck(limpa, invertida)) {
    printf("\n\"%s\" is palindrome\n\n", original);
  } else {
    printf("\n\"%s\" is NOT palindrome\n\n", original);
  }
}

int main () {
  int size=50, choice;
  char stringOriginal[size], stringLimpa[size] , stringInvertida[size];

  /*
    Precisaremos de funcoes para
    Filtrar (espacos, pontuacao, maiúscula, (acentuação))
    Inserir caracteres na pilha
    remover caracteres da pilha em uma outra string
    comparar duas strings e retorne booleano (strcmp)

  */
  
  for (choice=1; choice <5; choice ++) {
    selectString    (choice,      stringOriginal);         //Create all strings that are going to be tested
    cleanString     (stringLimpa, stringOriginal);         //Clean all non-"normal" characters of the strings
    invertString    (stringLimpa, stringInvertida);
    isPalindrome    (stringOriginal, stringLimpa, stringInvertida);
  }
}
