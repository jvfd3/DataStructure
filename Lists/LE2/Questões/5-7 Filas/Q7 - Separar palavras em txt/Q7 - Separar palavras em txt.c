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

/*  WIP
Eu parei após conseguir obter uma string. Consegui também (eu acho) colocar essa string em uma fila, porém estou tendo dificuldades
em colocar essa fila dentro de outra fila.
*/

void  selectString      (char* string, int choice) {   //Selects the string that is going to be used
  // selects which string wiqq be chosen
  switch (choice) {
    case 1:   strcpy(string,      "palavras.txt");   break;
    // case 4:   strcpy(string,      "./testes.txt");    break;         // use this if you want to add something different
    default:  strcpy(string,      "choice not available");              break;
  }
}

void  fileNameToRead    (char* fileID, int manualInput, int choice) {
  if (manualInput) {  //if you set to manualInput, you'qq need to write the fileID in the prompt
    printf ("Enter file ID for file to be parsed: ");
    scanf  ("%s", fileID);
  } else {            //if you didn't, a string wiqq be selected by your choice (or automatic choice)
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
    printf("File %s successfuqqy opened\n", fileID);
  }
  // fclose(fileID); //does this works?
}

/* void  checkMatchUp      (int* isWrong, int* lineCount, FILE* filePointer) { //checks if aqq tokens are paired correctly
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

void getString (char** str, int* token) {
  
  char* strTemp = (char *) malloc(sizeof(*str)++);
  strcpy(strTemp, *str);
  strncat(strTemp, token, 1);
  // free(*str);
  *str = strTemp;
  // printf(" Size: %d ; Pointer: %d ; partial: %s ;\n", sizeof(*str), *str,  *str);
}

void*   checkQueueChar (QUEUE* qq) {  //should return the first char of the first string of a queue of strings
  return (qq->front->dataPtr);
}

void insertSTRintoQintoQQ (char** str, QUEUE* qq) {   //should insert the first element of the first queue of the qq

}

void insertStringIntoLists (char** str, QUEUE* qq) {
  //THIS FUNCTION SHOULD INSERT THE string in a queue and then the queue in the queue of queues
  printf("(%s)   \n", *str);
/*   if (queueCount(qq) == 0) {
    insertSTRintoQintoQQ(str,qq); 
  } else {
    while (checkQueueChar(qq)==(*str)[0]) {
      
    }
  } */

  // printf("Completed String: <%c> %s\n", *str[0], *str);
 /*  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("(%s) *str (can be string)   \n", *str);
  printf("(%d) **str\t\t(%d) *str\t\t(%d) str\t(%d) &str\t   \n", **str, *str, str, &str);
  
  QUEUE* newList = createQueue();
  printf("(%d) *newList\t\t(%d) newList\t\t(%d) &newList\n", *newList, newList, &newList);

  enqueue(newList, *str);
  printf("(%d) *newList\t(%d) newList\t(%d) &newList\n", *newList, newList, &newList);
  printf("(%d) *nlfront\t(%d) nlfront\t\t(%d) &nlfront\n", *(newList->front), newList->front, &(newList->front));
  printf("(XXXXXXXXXX) XXXXXXXXX\t(%d) nldtptr\t(%d) &nldtptr \n", newList->front->dataPtr, &(newList->front->dataPtr));

  printf("(%d) *str == \t(%d) nldtptr\n", *str, newList->front->dataPtr);
  //  newList->front->dataPtr == *str
  printf("(%d) *qq\t\t(%d) qq\t\t(%d) &qq\t    \n", *qq, qq, &qq);
  enqueue(qq, &newList);
  printf("(%d) *qq\t\t(%d) qq\t\t(%d) &qq\t    \n", *qq, qq, &qq);
  printf("(%d) *qqfront\t(%d) qqfront\t(%d) &qqfront\t    \n", *(qq->front), qq->front, &(qq->front));
  printf("(XX) XXXXXXXXXXX\t(%d) qqfrontdata\t(%d) &qqfrontdata\t    \n", qq->front->dataPtr, &(qq->front->dataPtr));
   */
  // free(str);
  *str = (char *) malloc(sizeof(char));
  strcpy(*str, "");

}

void  fillListOfLists      (FILE* filePointer, QUEUE* qq) { //Fills queue with queues
  printf("Starting the process\n");
  // char token;
  int token;
  
  char* str = (char*) malloc (sizeof(char));
  strcpy (str, "");
  printf("Starting to get strings\n");
  while ((token = fgetc (filePointer)) != EOF ) {
    // printf("<%d>", token);
    if ((token!=' ')&&(token!='\n')) {
      getString(&str, &token);
    } else {
      if (strlen(str)!=0) {
        insertStringIntoLists(&str, qq);
      }
    }
  }
  free(str);
  printf("Finish\n");
}

/* 
void  printListOfLists  (QUEUE* qq) {
 
  QUEUE* tempQ = createQueue();     // temp must be a type of pointer to queue
  
  int cont=0;
  printf("( ");
  if (queueCount(qq)==0) {
    printf("Vazia ");
  } else {
    while (cont<queueCount(qq)) {
      //CHECK LATER IF THE TYPES ARE MATCHING (I GUESS THEY ARE NOT)
      dequeue     (qq, tempQ);
      printQueue  (    tempQ);
      enqueue     (qq, tempQ);
      cont++;
    }
  }
  printf(")");
}
 */

void q7 () {
  
  char    fileID[30];   //  string for the name of the file
  FILE*   filePointer;  //  pointer to the file
  int     manualInput = 0;  //line counter, toggle manual input 
  int     choice=1;
  
  fileNameToRead    (fileID,  manualInput, choice);       // sets the name of the file to fileID
  openFile          (fileID,  &filePointer);              // opens a file
  QUEUE* QueueOfQueues = createQueue();
  fillListOfLists   (filePointer, QueueOfQueues);

  // printListOfLists  (QueueOfQueues);
}

int main () {q7();}