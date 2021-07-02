#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../FilaJV/FilaJV.h"
#include "../../StringManipulationJV.c"


/*  Q7 - Separar palavras em txt
  Escreva um programa em C
  que classifique as palavras em um texto, disponivel na forma de arquivo,
  em categorias de acordo com a letra inicial de cada palavra.
  As palavras iniciadas com a mesma letra deverao ser colocadas em uma mesma fila.
  Apos a classificacao, exiba o numero de palavras existentes em cada categoria.
*/

/*  Ideia para o algoritmo:
ler um arquivo:
  Criar uma lista de listas
  ela começa vazia.
  Enquanto nao chega no EOF
    Le uma string do arquivo
    checa se já existe uma lista que tenha o seu primeiro char
    (vai chegar o primeiro caracter do primeiro elemento)
      se possui:
        insere a string no final
      se não possui:
        cria uma fila, inserir essa string nela e inserir um ponteiro para essa lista na lista de listas
  
  criar função de printar a lista de listas:
  vai percorrer todos os seus elementos que são filas, sempre printando toda a fila uma a umma

*/

void  selectString      (char* string, int choice) {   //Selects the string that is going to be used
  // selects which string will be chosen
  switch (choice) {
    case 1:   strcpy(string,      "palavras.txt");   break;
    // case 4:   strcpy(string,      "./testes.txt");    break;         // use this if you want to add something different
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
  } else {
    printf("File %s successfully opened\n", fileID);
  }
  fclose(fileID); //does this works?
}

/* void  checkMatchUp      (int* isWrong, int* lineCount, FILE* filePointer) { //checks if all tokens are paired correctly
  int token;
  QUEUE*  fila = createStack (); //creates a stack to deal with stackin' and poppin' 
  // variables need to be started somewhere
  *lineCount=1;
  *isWrong=0;
  // while token is not the end of file and there is nothing wrong...
  while (((token = fgetc (filePointer)) != EOF ) && (!*isWrong)) {
    switch  (token) {
      case  '\n': (*lineCount)++;                             break;
     
      case  '{' : pushInt(fila, token);                      break;
      // if it is any of the opening tokens, the token is pushed in the stack as an integer

      case '}'  : poppingTokens(fila, *lineCount, token, isWrong);    break;
      // if it is any of the closing tokens, the token is popped from the stack and some magic happens
    }
  }
  destroyQueue    (fila);
  // destroying the stack in case you want to use this function again with no problem
}
 */


void  fillListOfLists      (FILE* filePointer, QUEUE* ll) { //checks if all tokens are paired correctly
  int token;
  QUEUE*  fila = createStack (); //creates a stack to deal with stackin' and poppin' 


  // while token is not the end of file...
  while ((token = fgetc (filePointer)) != EOF ) {
    
  }
  destroyQueue    (fila);
  // destroying the stack in case you want to use this function again with no problem
}


void  printListOfLists  (QUEUE* ll) {
 
  QUEUE* tempQ = createQueue();     // temp must be a type of pointer to queue
  
  int cont=0;
  printf("( ");
  if (queueCount(ll)==0) {
    printf("Vazia ");
  } else {
    while (cont<queueCount(ll)) {
      //CHECK LATER IF THE TYPES ARE MATCHING (I GUESS THEY ARE NOT)
      dequeue     (ll, tempQ);
      printQueue  (    tempQ);
      enqueue     (ll, tempQ);
      cont++;
    }
  }
  printf(")");
}


void q7 () {
  
  char    fileID[30];   //  string for the name of the file
  FILE*   filePointer;  //  pointer to the file
  int     manualInput = 0;  //line counter, toggle manual input 
  int     choice=1;
  
  fileNameToRead    (fileID,  manualInput, choice);       // sets the name of the file to fileID
  openFile          (fileID,  &filePointer);              // opens a file
  QUEUE* ListOfLists = createQueue();
  fillListOfLists   (filePointer, ListOfLists);
  printListOfLists  (ListOfLists);
}

int main () {q7();}