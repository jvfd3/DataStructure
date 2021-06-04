#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "PilhaJV.h"
// #include "B:\HDExterno\UENF\4Periodo\Estruturas de Dados\GitHub_Repository\DataStructure\Lists\LE2\Questões\1-4 Pilha\PilhaJV.h"

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

void printString  (char* string) {  // simply prints a string aesthetically
  printf("->%s<-\n", string);
}

void selectString    (int choice, char* string) {   //Create all strings that are going to be tested

  // Selecting which string will be chosen

  switch (choice) {
    case 1:   strcpy(string,      "A base do teto desaba.");                    break;
    case 2:   strcpy(string,      "A diva em Argel alegra-me a vida.");         break;
    case 3:   strcpy(string,      "Adias a data da saida.");                    break;
    case 4:   strcpy(string,      "Socorram-me, subi no onibus em Marrocos.");  break;
    default:  strcpy(string,      ""); break;
  }

}

bool isBetween (int n, int min, int max) {
  return ((min <= n) && (n <= max));
}

bool isAlpha (int n) {
  return (isBetween(n,65,90)||isBetween(n,97,122));
}

void cleanSpecialChar (char* s) {     // turns punctuation into spaces " ' , . - { [ ( ) ] } @ ! #
  int i;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    // printf("%d\n",i);
    if (!(isBetween(s[i],65,90)||isBetween(s[i],97,122)||s[i]=='\0')) {
      s[i] = ' ';
    }
  }
  printf("After cleanSpecialChar\t");
  printString(s);
}

/*
void normalizeCharacter (char* s) {   // turns special characters into normal characters ç á à â ã é ê í ó ô õ ú Ç Á À Â Ã É Ê Í Ó Ô Õ Ú
  
  int i;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    // it will now turn all of the ascii equivalent of vowels and c to it correspondent normal letter
    if (isBetween(s[i],192,198)||isBetween(s[i],224,230)) {
      s[i] = 'a';
    } else if (isBetween(s[i],200,203)||isBetween(s[i],232,235)) {
      s[i] = 'e';
    } else if (isBetween(s[i],204,207)||isBetween(s[i],236,239)) {
      s[i] = 'i';
    } else if (isBetween(s[i],210,214)||isBetween(s[i],242,246)) {
      s[i] = 'o';
    } else if (isBetween(s[i],217,220)||isBetween(s[i],249,252)) {
      s[i] = 'u';
    } else if (s[i] == 199) {
      s[i] = 'c';
    }
  }
  printf("After normalizeCharacter\t");
  printString(s);
}
*/

int alphaSize(char* s) {
  int i, cont=0;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    if (isAlpha(s[i])) {
      cont++;
    }
  }
  return cont;
}

int spaceCount(char* s) {
  int i, cont=0;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    if (s[i]==' ') {
      cont++;
    }
  }
  return cont;
}

void alphaCopy (char* newS, char* s) {
  int i, j=0;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    if (isAlpha(s[i])) {
      // printf(">%c< isAlpha. inserting...\n", s[i]);
      newS[j] = s[i];
      j++;
    }
  }
  s=newS;
}

void spaceless1 (char* s) {            // remove all of the spaces
  int newSize;

  newSize = alphaSize(s);
  printf("%d\n",newSize);
  char newString[newSize];
  // printString(s);
  // printString(newString);
  strcpy(newString,s);
  // printString(s);
  // printString(newString);
  
  // alphaCopy(newString, s);

  printf("After spaceless\t\t");
  printString(s);
}

void swap (int* a, int* b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void spacelessSwap (char* s) {            // remove all of the spaces
  // this part of the code is chaos. don't stare at him too much
  int i=0, j, spaces=spaceCount(s);
  do {
  // printf("%dspaces\n", spaces);
        // printString(s);
    if (s[i]==' ') {
      for (j=i; j<(int) strlen(s);j++) {
        // swap (&(s[j]), &(s[j+1]));
        // i'm sweeping dirty over the \0
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

void turnLower (char* s) {              // turn all characters to minuscule
  int i;
  for (i=0;i<(int) strlen(s);i++) {
    if (isBetween(s[i],65,90)) {
      s[i] += 32;
    }
  }
  printf("After turnLower\t\t");
  printString(s);
}

void cleanString      (char* limpa, char* original) {   //Clean all non-"normal" characters of the strings
  
  strcpy(limpa, original);
  
  printf("Before cleanString\t");
  printString(limpa);

  // normalizeCharacter(limpa);    // turns special characters into normal characters ç á à â ã é ê í ó ô õ ú Ç Á À Â Ã É Ê Í Ó Ô Õ Ú 
  cleanSpecialChar(limpa);      // turns punctuation into spaces " ' , . - { [ ( ) ] } @ ! #
  turnLower(limpa);               // turn all characters to minuscule
  // spaceless1(limpa);             // remove all of the spaces
  spacelessSwap(limpa);             // remove all of the spaces
  // printString(original);
  // printString(limpa);
}

void invertString     (char* limpa, char* invertida) {
  printString (limpa);
  STACK* pilha;
  pilha = createStack();
  int i;
  for (i=0;i<(int) strlen(limpa);i++) {
    pushStack(pilha, (void*) &limpa[i]);
    printf("Pushing: (%d, %d, %c)\n", &limpa[i], limpa[i], limpa[i]);
  }
    // invertida+=(*popStack(pilha));
  void* dataPtr;
  dataPtr = popStack(pilha);
  int* temp = (int*) popStack(pilha);
  printf("dataptr\t%d\n", ((int*) dataPtr));
  printf("temp\t%d\n", temp);
  printf("temp\t%d\n", (int*) popStack(pilha));

  // do { } while (!emptyStack(pilha));
  printString (invertida);
}

/* 
void palindromeCheck  (char* limpa, char* invertida) {

} */


int main () {
  int size=50, choice=4;
  char stringOriginal[size], stringLimpa[size] , stringInvertida[size] ;

  /*
    Precisaremos de funcoes para
    Filtrar (espacos, pontuacao, maiúscula, (acentuação))
    Inserir caracteres na pilha
    remover caracteres da pilha em uma outra string
    comparar duas strings e retorne booleano (strcmp)

  */
  
  selectString    (choice,      stringOriginal);         //Create all strings that are going to be tested
  cleanString     (stringLimpa, stringOriginal);         //Clean all non-"normal" characters of the strings
  invertString    (stringLimpa, stringInvertida);
  // palindromeCheck (stringLimpa, stringInvertida);
}
