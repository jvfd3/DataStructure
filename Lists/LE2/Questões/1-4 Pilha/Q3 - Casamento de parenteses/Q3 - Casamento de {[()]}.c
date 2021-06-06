#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../PilhaJV/PilhaJV.h"

/*  ASCII
40    (
41    )

91    [
93    ]

123   {
125   }
*/

/*  Q3 - Casamento de parenteses

  1) Modifique o programa de casamento de parenteses para considerar o casamento de { }, [ ] e ( ).

  2)  O programa devera verificar a correspondencia entre o simbolo de abertura
      e seu correspondente de fechamento

  3)  Identifique e reporte os tipos de erro possiveis caso existam,
      indicando a linha, ou uma mensagem indicando que o casamento eh perfeito.

  4)  Teste o seu programa com arquivos de texto, com erros e sem erros.

*/

/*  This program reads a source program and parses it to 
  make sure all opening-closing parentheses are paired.
     Written by:
     Date:
*/

void  selectString      (char* string, int choice) {   //Create all strings that are going to be tested
  // Selecting which string will be chosen
  switch (choice) {
    case 1:   strcpy(string,      "./Exemplos/open-miss.c");   break;
    case 2:   strcpy(string,      "./Exemplos/close-miss.c");  break;
    case 3:   strcpy(string,      "./Exemplos/no-error.c");    break;
    // case 4:   strcpy(string,      "testes.txt");    break;
    default:  strcpy(string,      "");              break;
  }
}

void  fileNameToRead    (char* fileID, int manualInput, int choice) {
  if (manualInput) {
    printf ("Enter file ID for file to be parsed: ");
    scanf  ("%s", fileID);
  } else {
    selectString (fileID, choice);
  }
  
  printf("\n\nthe file \"%s\" was chosen.\n", fileID);
}

void  openFile          (char* fileID, FILE** filePointer) {
  *filePointer = fopen (fileID, "r");
  if (!*filePointer) {
    printf("Error opening %s\n", fileID), exit(100);
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

void  poppingTokens    (STACK* pilha, int lineCount, int token, int* isWrong) {
  int poppedToken;

  // token = (token==')') ? token-1 : token-2 ;
  
  if (token==')') {
    token-=1;
  } else {
    token-=2;
  }

  if (emptyStack (pilha)) {
    printf("Token %c at line %d didn't have a match, because the stack is empty\n", token, lineCount);
    *isWrong=1;
  } else {
    poppedToken = popInt(pilha);
    if(poppedToken != token) {
      printf ("Poped token %c didn't match %c token at line %d\n", poppedToken, token, lineCount);
      *isWrong=1;
    }
  }
}

void  checkMatchUp      (int* isWrong, int* lineCount, FILE* filePointer) {
  int token;
  STACK*  pilha = createStack ();
  // int* dataPtr;
  (*lineCount)=1;
  *isWrong=0;
  while (((token = fgetc (filePointer)) != EOF ) && (!*isWrong)) {
    switch  (token) {

      case  '\n': (*lineCount)++;                             break;

      case  '(' : 
      case  '[' : 
      case  '{' : pushInt(pilha, token);                      break;

      case ')'  : 
      case ']'  : 
      case '}'  : poppingTokens(pilha, *lineCount, token, isWrong);    break;
    }
  }
  destroyStack    (pilha);
}

void  finalMessage      (int isWrong, int lineCount) {
  char message[2];
  strcpy(message, isWrong? "An":"No");
  printf ("%s errors have been found after %d Lines have been parsed\n\n", message, lineCount);
}

int   main (void) {
//  Local Definitions 
  FILE*   filePointer;
  char    fileID[30];
  int     lineCount, manualInput = 0, isWrong=0;
  int     choice=3;   //choices: 1) open;2) close;3) no-error;

  for (choice = 1; choice < 4; choice++) {
    fileNameToRead  (fileID,  manualInput, choice);
    openFile        (fileID,  &filePointer);
    checkMatchUp    (&isWrong, &lineCount, filePointer);
    finalMessage    (isWrong, lineCount);
  }
}

/*
Results


the file "open-miss.c" was chosen.
Poped token { didn't match ( token at line 23
An errors have been found after 23 Lines have been parsed



the file "close-miss.c" was chosen.
Poped token ( didn't match { token at line 31
An errors have been found after 31 Lines have been parsed



the file "no-error.c" was chosen.
No errors have been found after 66 Lines have been parsed

*/

