#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "PilhaJV.h"

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
    case 1:   strcpy(string,      "open-miss.c");   break;
    case 2:   strcpy(string,      "close-miss.c");  break;
    case 3:   strcpy(string,      "no-error.c");    break;
    case 4:   strcpy(string,      "testes.txt");    break;
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
}

void  openFile          (char* fileID, FILE** filePointer) {
  *filePointer = fopen (fileID, "r");
  if (!*filePointer) {
    printf("Error opening %s\n", fileID), exit(100);
  }
}

int   closeError        (STACK* stack, int lineCount) {
  if (!emptyStack (stack)) {
    printf ("Close paren missing at line %d\n", lineCount);
    return 1;
  }
}

void  noErrorMessage    (int lineCount) {
  printf ("\n%d Lines parsed.\n\n", lineCount);
}

void  finalMessage      (STACK* stack, int lineCount) {
  if (! closeError(stack, lineCount)){
    noErrorMessage    (lineCount);
  }
}

void  checkMatchUp      (STACK* stack, int* lineCount, FILE* filePointer ) {
  char token;
  char* dataPtr;  
  while ((token = fgetc (filePointer)) != EOF ) {
    switch  (token) {

      case  '\n': {  (*lineCount)++; break;}

      case  '(' : {
                    dataPtr   = (char*) malloc (sizeof (char));
                    *dataPtr  = token;
                    pushStack (stack, dataPtr);
                    break;
                  }

      case ')' :  {
                    if (emptyStack (stack)) {
                        printf ("Open paren missing at line %d\n", *lineCount);
                        // return 1;
                    } else {
                      popStack (stack);
                    }
                    break;
                  }
    }
  }
}

int main (void) {
//  Local Definitions 
  FILE*  filePointer;
  STACK* stack = createStack ();
  char   fileID[30];
  int    lineCount = 1, manualInput = 0, choice=1;   //choices: 1) open;2) close;3) no-error;4) teste;

  fileNameToRead  (fileID, manualInput, choice);
  openFile        (fileID, &filePointer);
  checkMatchUp    (stack, &lineCount, filePointer);
  finalMessage    (stack, lineCount);
  destroyStack    (stack);
}

/*  Results
Run 1:
  Enter file ID for file to be parsed: no-errors.txt
  Parsing is OK: 65 Lines parsed.
Run 2:  
  Enter file ID for file to be parsed: open-match.txt
  Open paren missing at line 23
Run 3:
  Enter file ID for file to be parsed: close-match.txt
  Close paren missing at line 46
*/

