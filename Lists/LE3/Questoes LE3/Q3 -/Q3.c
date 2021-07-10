#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD_BinaryTreeSearch/JV/Compacted/BST_ADT.h"
// #include "../../LE2/Questoes/5-7 Filas/FilaJV/FilaJV.h"
// #include "..\..\..\LE2\Questões\5-7 Filas\FilaJV\FilaJV.h"

// I couldn't import Queue from LE2, I'll copy the file here for now
#include "FilaHuffmanJV/FilaJV.h"

/* Q3 - 
Escreva um programa em C,
que implemente o algoritmo de Huffman.
Utilize a seguinte tabela
para designar os pesos dados aos caracteres
ou outra que considere conveniente.

IMAGEM

O programa deverá contemplar as seguintes tarefas:

  i) Construir uma árvore
  que defina a codificação de cada caráter.
  Após construir a árvore de codificação
  imprima o código de cada caráter.

  ii) Codificar.
  O programa deverá ler um texto de um arquivo
  e converter esse texto no código de Huffman.
  Salvar esse código.

  iii) Decodificar.
  O programa deverá ler um código de Huffman
  de um arquivo e converter ele de volta em texto.

Utilize o texto da sua escolha, com pelo menos 2 linhas, para testar o programa.


*/

typedef struct table {
  char* code; //not really sure if code is needed here
  char* token;
  int*  frequency;
} TABLE;

//I know this struct below is not optimal, but I already wrote nearly 300 lines of code, I don't want to refactor it
// so that I use a tree instead of a struct; I'll just convert a queue of structs into a queue of trees with this new struct here

typedef struct treeData {
  int* frequency;
  TABLE* structData;
} TREEDATA;


/*  ==================== comparePhoneNumber ====================  
      Compare two pointers and return low, equal, high.
      Pre user1 and user2 are valid pointers to the struct USER
      Post return low (-1), equal (0), or high (+1)
*/
/*  review it later
  This part is ugly but what it does is:
  It gets two dataPointers that are actually pointers to the struct USER, so they cast it to be
  a pointer to USER type, and then gets the pointer for names, casts it into a pointer to int and then
  grab its internal value
*/

/* int huffCompare (void* user1, void* user2) {
// is this * out of everything really needed?
int something;
  char* name1 = something;
  char* name2 = something;
  return strcmp(name1,name2);
} */

/*  ====================== printUserBST ======================  
  Print Name and PhoneNumber from BST.
      Pre  user is a pointer to an USER struct
      Post "Name: Name_of_USER \t Phone Number: phone_number_of_the_user\n"
*/
/* void huffPrint (void* user) {
  //Not sure if name will need the extra *
  int something;
  int   phone = something;
  char* name  =   something;

  printf("Name: %s \t Phone Number: %d\n", name, phone);
  return; //NECESSARY? I don't think so
} */
/* 
int createHuffmanTree () {
  return 0;
}

int createHuffNode () {
  return 0;
}


int _huffRecursive () {
  return 0;

} */


//  ################### START INDEPENDENT FUNTIONS ###################


void message(char* string, int number) {
  printf("\n\n = = = %s of Q%d = = = \n\n", string, number);
}


//  ################### END INDEPENDENT FUNTIONS ###################

//  ################### START STRING SELECTION ###################

void  autoSelectString    (char* string, int choice) {   //Create all strings that are going to be tested
  
    // I manually cleaned strings for simplification
    // The goal of the code is not to actually cleand the string
    // so why complicate it even more?
    
  switch (choice) {     // Selecting which string will be chosen
    case 1:   strcpy(string, "a base do teto desaba");                     break;
    case 2:   strcpy(string, "a diva em argel alegra me a vida");          break;
    case 3:   strcpy(string, "adias a data da saida");                     break;
    case 4:   strcpy(string, "socorram me subi no onibus em marrocos");    break;
    default:  strcpy(string, "Invalid option");                            break;
  }
}

void  manualSelectString  (char* string) {
  printf("Enter the String you want to encrypt using Huffman's algorith:\n");
  scanf("%s", string);
  //Should I do the below code instead?
  /* 
  char* tidyName = (char*) malloc (sizeof(strlen(name)));
  strcpy(tidyName, name);
  return tidyName;
 */

}

void  selectString        (char* string, int isManual) {
  int choice=3;
  (isManual)?manualSelectString(string):autoSelectString(string, choice);
}

void  printChosenString   (char* string) {
  printf("\nYour chosen string is \"%s\" with sizeof (%d)\n", string, strlen(string));
}

//  ################### END STRING SELECTION ###################


//  ################### START CHARACTER COUNT ###################

TABLE* createHuffStruct (char token) {
  TABLE* tableNode = (TABLE*) malloc (sizeof(TABLE));


  char* code            = (char*) malloc (sizeof(char));
  char* tokenToInsert   = (char*) malloc (sizeof(char));
  int*  frequency       = (int*)  malloc (sizeof(int ));

  strcpy(code, "NotYetDefined");
  *tokenToInsert  = token;
  *frequency      = 1;

  tableNode->token = tokenToInsert;
  tableNode->frequency = frequency;
  tableNode->code = code;

  return tableNode;
}

char toknGetFromNode (QUEUE_NODE* node) {
  char tempChar = *((char*)(((TABLE*)(node->dataPtr))->token));
  // printf("The node to be returned is %c\n", tempChar);
  return tempChar;
}

void setNewFrequency (QUEUE_NODE* tempNode) {
  TABLE* tempTable = tempNode->dataPtr;
  int* tempFrequency = tempTable->frequency;
  *tempFrequency = *tempFrequency+1;
  // *((int*)(((TABLE*)(tempNode->dataPtr))->frequency))++;
}

void updadeFrequency (QUEUE* queue, TABLE* tableNode) {
  char tokenToCompare = *(tableNode->token);
  char tokenFromNode;
  int isPresent = 0;
  QUEUE_NODE* tempNode;
  if (queueCount(queue)!=0) {                          // if the queueCount is not empty
    tempNode = queue->front;                          // tempNode will receive the first node pointer
    while (!((tempNode== NULL) || isPresent) ) {     // it will loop while the node is not null, nor the token has been found
      tokenFromNode = toknGetFromNode(tempNode);   // simplification of some messy pointer stuff
      if (tokenFromNode == tokenToCompare) {       // if the token has been found
        setNewFrequency (tempNode);               // set the new frequency
        isPresent=1;                             // and say it's present (it will stop the loop)
      } else {                                  // else...
        tempNode = tempNode->next;             // (if it is not the same), advance one node (if node is Null, it will stop the loop)
      }
    }
  }
  if (!isPresent) {
    // maybe I'll change that to a function that enqueue and also orders it
    enqueue(queue, tableNode);                                    // if it scanned all queue and didn't find the token, it will enqueue the new one
  }
}

void characterCount (char* string, QUEUE* queue) {
  int i;
  char token;
  TABLE* tableNode;

  for (i=0; i<(int)strlen(string); i++) {
    token = string[i];
    // printf(" %c ", token);
    tableNode = createHuffStruct(token);
    updadeFrequency(queue, tableNode);

    //updadeFrequency(queue, createHuffStruct(string[i]));
  }

}

//  ################### END CHARACTER COUNT ###################

//  ################### START PRINT HUFF QUEUE ###################

int   freqGetFromNode (QUEUE_NODE* node) {
  int tempFrequency = *((int*)(((TABLE*)(node->dataPtr))->frequency));
  // printf("The frequency to be returned is %d\n", tempFrequency);
  return tempFrequency;
}

char* codeGetFromNode (QUEUE_NODE* node) {
  char* tempCode = (char*)(((TABLE*)(node->dataPtr))->code);
  // printf("The code to be returned is %s\n", tempCode);
  return tempCode;
}

void  printHuffQueue  (QUEUE* queue) {

  QUEUE_NODE*    node;

  char  tokn;
  int   freq;
  char* code;

  if (queueCount(queue)!=0) {                                // if the queueCount is not empty
    node = queue->front;                                // tempNode will receive the first node pointer
    // printf("Printing Huffman Queue (%X):\n", queue);
    while (node!= NULL) {                          // it will loop while the node is not null, nor the token has been found
      tokn = toknGetFromNode(node);         // simplification of some messy pointer stuff
      freq = freqGetFromNode(node);
      code = codeGetFromNode(node);

      printf("(Token: %c||Freq: %d||Code: %s)\n", tokn, freq, code);
      // printf("%d ", freq);  //DEBUGGING PURPOSE
      // printf("%X ", node);  //DEBUGGING PURPOSE


      node = node->next;             // (if it is not the same), advance one node (if node is Null, it will stop the loop)
      
    }
  } else {
    printf("The Queue is Empty. \n");
  }
  printf("\n"); //DEBUGGING PURPOSE
}

//  ################### END PRINT HUFF QUEUE ###################

//  ################### START ORDER QUEUE ###################

void changeNodePosition (QUEUE_NODE* node) {
  // That is actually not changing the node position ;p
  // I was trying to, but it seemed complex, so I thought a little more and realized:
  // changing the dataPtr positions would be much simpler

  void*    tempTable;
  // printf("(%d/%d)->", freqGetFromNode(node), freqGetFromNode(node->next));  //not working but I don't know why
  tempTable           = node->dataPtr;
  node->dataPtr       = node->next->dataPtr;
  node->next->dataPtr = tempTable;
  // printf("(%d/%d)\n", freqGetFromNode(node), freqGetFromNode(node->next));  //not working but I don't know why
}

void  orderQueue  (QUEUE* queue) {

  QUEUE_NODE*    node;

  int   freq1, freq2;
  
  if (queueCount(queue)!=0) {
    node = queue->front;
    while (node != NULL) {
      if (node->next != NULL) {
        freq1 = freqGetFromNode(node);
        freq2 = freqGetFromNode(node->next);
        if (freq1>freq2) {
      // if (freq1<freq2) { //this is for decrescent order, I need crescent
          changeNodePosition(node);
          // printHuffQueue(queue);
          node = queue->front;
        } else {
          node = node->next;
        }
      } else {
        node = node->next;
      }
    }
  }
}

//  ################### END ORDER QUEUE ###################

//  ################### START turn Queue Into Huff Tree Queue ###################

void createLeafTreeData (TABLE* dataPtr, TREEDATA* treeData) {
  treeData = (TREEDATA*) malloc (sizeof(TREEDATA));
  treeData->frequency = dataPtr->frequency;
  treeData->structData = dataPtr;
}

int compareFreq (void* treeData1, void* treeData2) {
  int key1 = *((int*)(((TREEDATA*)treeData1)->frequency));
  int key2 = *((int*)(((TREEDATA*)treeData2)->frequency));

  if (key1 < key2) {
    return -1;
  }
  if (key1 == key2) {
    return 0;
  }
  return +1;
}

void turnQueueIntoHuffTreeQueue (QUEUE* queue) {
  BST_TREE* huffTree;
  TREEDATA* treeData;
  TABLE*    dataPtr;
  QUEUE*    huffTreeQueue = createQueue();

  while (queueCount(queue)!=0) {
    dequeue(queue,dataPtr);
    huffTree = BST_Create (compareFreq);
    createLeafTreeData (dataPtr, treeData);
    BST_Insert(huffTree, dataPtr);
    enqueue(huffTreeQueue, huffTree);
  }
  destroyQueue(queue);
  queue = huffTreeQueue;

}

//  ################### END turn Queue Into Huff Tree Queue ###################


void q3 () {
  message("Start",3);

  int isManual = 0;
  char* str = (char*) malloc (sizeof(char));
  QUEUE* queue = createQueue();

  selectString(str, isManual);
  printChosenString (str);
  characterCount(str, queue);
  orderQueue(queue);
  printHuffQueue(queue);
  // turnQueueIntoHuffTreeQueue(queue);
  // BST_TREE* huffmanTree = BST_Create(huffCompare);
  // createHuffmanTree (huffmanTree, queue);
  // char* code = getCode (huffmanTree, queue);
  // solveCode (code);
  
  // destroyQueue(queue); 
  //FOR SOME REASON THIS DESTROY IS BUGGING, I'LL JUST NOT DESTROY IT THEN.
  // WHICH IS NOT RIGHT, BUT I'LL DO IT ANYWAY
  message("End",3);
}

int main () {
  q3();
  // printf(".");

  // the code wasn't stopping unless I putted a dot here
  // but I kept changing things on the code and it's not needed anymore.
  // I don't know what caused that and also don't know what solved
}
