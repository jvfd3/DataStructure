#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../PilhaJV/PilhaJV.h"

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

void  selectString      (char* string, int choice) {   //Selects the string that is going to be used
  // selects which string will be chosen
  switch (choice) {
    case 1:   strcpy(string,      "./Exemplos/open-miss.c");   break;
    case 2:   strcpy(string,      "./Exemplos/close-miss.c");  break;
    case 3:   strcpy(string,      "./Exemplos/no-error.c");    break;
    // case 4:   strcpy(string,      "./Exemplos/testes.txt");    break;         // use this if you want to add something different
    default:  strcpy(string,      "choice not available");              break;
  }
}

void  fileNameToRead    (char* fileID, int manualInput, int choice) {
  if (manualInput) {  //if you set to manualInput, you'll need to write the fileID in the prompt
    printf ("Enter file ID for file to be parsed: ");
    scanf  ("%s", fileID);
  } else {            //if you didn't, a string will be selected by your choice (or automatic choice)
    selectString (fileID, choice);
  }
  
  printf("\n\nthe file \"%s\" was chosen.\n", fileID);
}

void  openFile          (char* fileID, FILE** filePointer) {  //opens a file
  //opens a file using the fileID and puts it's pointer in file pointer
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

  /*  //another option of code if you don't like/understand ternary operations
    if (token==')') {
      token-=1;
    } else {
      token-=2;
    }
  */

  // same thing as the commented if statement above... but shorter
  token -= (token==')') ? 1 : 2 ;
  // it's purpose is to set the token as the opening token related to the closing token read as seen in the
  // following cheat sheet
  
  /*  ASCII tokens cheat sheet
    40    (
    41    )

    91    [
    93    ]

    123   {
    125   }
  */

  // I guess the prints are self explanatory
  if (emptyStack (pilha)) {
    printf("Token %c at line %d didn't have a match, because the stack is empty\n", token, lineCount);
    *isWrong=1;
    //attention to that variable. That's what changes the final message
  } else {
    poppedToken = popInt(pilha);
    if(poppedToken != token) {
      printf ("Poped token %c didn't match %c token at line %d\n", poppedToken, token, lineCount);
      *isWrong=1;
      // same here, if it's wrong, it will say it's wrong. but only in the future
    }
  }
}

void  checkMatchUp      (int* isWrong, int* lineCount, FILE* filePointer) { //checks if all tokens are paired correctly
  int token;
  STACK*  pilha = createStack (); //creates a stack to deal with stackin' and poppin' 
  // variables need to be started somewhere
  *lineCount=1;
  *isWrong=0;
  // while token is not the end of file and there is nothing wrong...
  while (((token = fgetc (filePointer)) != EOF ) && (!*isWrong)) {
    switch  (token) {
      case  '\n': (*lineCount)++;                             break;
      // if the token is a '\n', it only increment the line counter

      case  '(' : 
      case  '[' : 
      case  '{' : pushInt(pilha, token);                      break;
      // if it is any of the opening tokens, the token is pushed in the stack as an integer

      case ')'  : 
      case ']'  : 
      case '}'  : poppingTokens(pilha, *lineCount, token, isWrong);    break;
      // if it is any of the closing tokens, the token is popped from the stack and some magic happens
    }
  }
  destroyStack    (pilha);
  // destroying the stack in case you want to use this function again with no problem
}

void  finalMessage      (int isWrong, int lineCount) {
  char message[2];

  // don't you like ternary operators? I'do. They are confusing at first, but then it's so more compact
  strcpy(message, isWrong? "An":"No");
  // In case you don't like it, I'll explain: If there was an error, the first one "an" will be set to message
  // If not, "no" will be
  printf ("%s errors have been found after %d Lines have been parsed\n\n", message, lineCount);
  // That's all, folks.
}

int   main (void) {
//  Local Definitions 
  char    fileID[30];   //  string for the name of the file
  FILE*   filePointer;  //  pointer to the file
  int     lineCount, isWrong, manualInput = 0;  //line counter, check if is wronge and toggle manual input 
  int     choice;
  // choice=3;     //  test Options: 1) open;2) close;3) no-error;

  for (choice = 1; choice < 4; choice++) {
    fileNameToRead  (fileID,  manualInput, choice);       // sets the name of the file to fileID
    openFile        (fileID,  &filePointer);              // opens a file
    checkMatchUp    (&isWrong, &lineCount, filePointer);  // here's where the fun stuff begins
    finalMessage    (isWrong, lineCount);                 // 
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

