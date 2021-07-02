#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "./FilaJV/FilaJV.h"

/*  Q7 - Separar palavras em txt
  Escreva um programa em C
  que classifique as palavras em um texto, disponivel na forma de arquivo,
  em categorias de acordo com a letra inicial de cada palavra.
  As palavras iniciadas com a mesma letra deverao ser colocadas em uma mesma fila.
  Apos a classificacao, exiba o numero de palavras existentes em cada categoria.
*/

/*  Ideia para o algoritmo:

ler um arquivo:
  (CONFERIR UM EXERCICIO ANTERIOR QUE LIA TXT)
  (se não me engano ele lê colocando todos os caracteres em uma só string. (CONFERIR))
  Opcao 1:
    Ler tudo de uma vez e colocar em uma String só (teria que ver como alocar dinamicamente)
    porque vai depender do tamanho recebido.
    
    Com a string completa, pode-se usar as 
  Opcao 2:
    Lidar com uma string lida por vez.
    talvez precise alocar dinamicamente, mas não tenho certeza
  

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
  fclose(fileID); //does this works?
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

int main () {
    

    
  char    fileID[30];   //  string for the name of the file
  FILE*   filePointer;  //  pointer to the file
  int     lineCount, isWrong, manualInput = 0;  //line counter, check if is wrong and toggle manual input 
  int     choice;
  
  fileNameToRead  (fileID,  manualInput, choice);       // sets the name of the file to fileID
  openFile        (fileID,  &filePointer);              // opens a file
}
