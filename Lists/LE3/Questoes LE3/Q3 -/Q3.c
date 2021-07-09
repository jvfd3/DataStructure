#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD_BinaryTreeSearch/JV/Compacted/BST_ADT.h"
// I can't import Queue 
#include "../../LE2/Questoes/5-7 Filas/FilaJV/FilaJV.h"
// #include "..\..\..\LE2\Questões\5-7 Filas\FilaJV\FilaJV.h"

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
  char* char1;
  char* code; //not really sure if code is needed here
  int*  frequency;
} TABLE;



/*  ==================== comparePhoneNumber ====================  
      Compare two pointers and return low, equal, high.
      Pre user1 and user2 are valid pointers to the struct USER
      Post return low (-1), equal (0), or high (+1)
*/
int huffCompare (void* user1, void* user2) {
/*  review it later
  This part is ugly but what it does is:
  It gets two dataPointers that are actually pointers to the struct USER, so they cast it to be
  a pointer to USER type, and then gets the pointer for names, casts it into a pointer to int and then
  grab its internal value
*/
// is this * out of everything really needed?
int something;
  char* name1 = something;
  char* name2 = something;
  return strcmp(name1,name2);
}

/*  ====================== printUserBST ======================  
  Print Name and PhoneNumber from BST.
      Pre  user is a pointer to an USER struct
      Post "Name: Name_of_USER \t Phone Number: phone_number_of_the_user\n"
*/
void huffPrint (void* user) {
  //Not sure if name will need the extra *
  int something;
  int   phone = something;
  char* name  =   something;

  printf("Name: %s \t Phone Number: %d\n", name, phone);
  return; //NECESSARY? I don't think so
}

int createHuffmanTree () {
  return 0;
}

int createHuffNode () {
  return 0;
}

int createHuffStruct () {
  return 0;

}

int _huffRecursive () {
  return 0;

}

void q3 () {
  int choice = 1;
  char* str = selectString(choice);
  QUEUE* queue = characterCount(str);
  orderQueue(queue);
  BST_TREE* huffmanTree = BST_Create(huffCompare);
  createHuffmanTree (huffmanTree, queue);
}

int main () {
  q3();
}
