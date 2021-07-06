#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD_BinaryTreeSearch/JV/Compacted/BST_ADT.h"

/* Q2 - 
  Escreva uma função em C para
  calcular o fator de balanceamento de uma árvore binária.
  A função deve receber como argumentos:
    um ponteiro à árvore binária,     //why?
    e um ponteiro ao nó raiz da árvore ou sub-árvore 
      cujo fator de balanceamento será calculado.
*/

//	Prototype Declarations 
int   compareInt (void* num1, void* num2);
void  printBST   (void* num1);

void  insertInt     (BST_TREE* RootPointer, int num);
void  autoFillTree1 (BST_TREE* RootPointer);
void  autoFillTree2 (BST_TREE* RootPointer);
void  autoFillTree  (BST_TREE* RootPointer, int choice);
void  manualFillTree(BST_TREE* RootPointer);
void  fillTree      (BST_TREE* RootPointer, int isManual);
void  printTree     (BST_TREE* RootPointer);
int   bigger        (int Left, int Right);
int   _longestBranch (NODE* Tree);
int   SolveBinaryTreeBalanceFactor (BST_TREE* RootPointer, NODE* treeRoot);
void  BinaryTreeBalanceFactor (BST_TREE* tree);
void  q2 ();

int main () {
  q2();
}


/*	==================== compareInt ====================  
	Compare two integers and return low, equal, high.
	    Pre  num1 and num2 are valid pointers to integers
	    Post return low (-1), equal (0), or high (+1)
*/
int compareInt (void* num1, void* num2) {
  int key1 = *((int*) num1);
  int key2 = *((int*) num2);

  if (key1 < key2) {
    return -1;
  }
  if (key1 == key2) {
    return 0;
  }
  return +1;
}

/*	====================== printBST ======================  
	Print one integer from BST.
	    Pre  num1 is a pointer to an intger
	    Post integer printed and line advanced
*/
void printBST (void* num1) {
  printf("%4d\n", *(int*)num1);
  return; //NECESSARY? I don't think so
}


void insertInt (BST_TREE* RootPointer, int num) {
  int* x = (int*) malloc (sizeof(int));
  //Not really sure of what this if does. I guess it's not necessary in most cases
  if (!x) {
    printf("Memory Overflow in add\n"),
    exit(100);
  } // if overflow
  *x = num;
  BST_Insert (RootPointer, x);
}

void autoFillTree1 (BST_TREE* RootPointer) {
 // 5 3 2 1 4 6 7 9 8 10
 /*
                      5
                  3       6
               2    4       7
            1                  8 
                            9     10
 
 */
  insertInt (RootPointer, 5);
  insertInt (RootPointer, 3);
  insertInt (RootPointer, 2);
  insertInt (RootPointer, 1);
  insertInt (RootPointer, 4);
  insertInt (RootPointer, 6);
  insertInt (RootPointer, 7);
  insertInt (RootPointer, 9);
  insertInt (RootPointer, 8);
  insertInt (RootPointer, 10);
  
}

void autoFillTree2 (BST_TREE* RootPointer)  {
 // 8 6 7 2 1 4 3 5 9 13 11 10 12 14
 /*
                     8
                   6  9
               2    7        13
              1  4       11    14
                3 5    10  12  

 */

  insertInt (RootPointer, 8);
  //LEFT
  insertInt (RootPointer, 6);
  insertInt (RootPointer, 7);
  insertInt (RootPointer, 2);
  insertInt (RootPointer, 1);
  insertInt (RootPointer, 4);
  insertInt (RootPointer, 3);
  insertInt (RootPointer, 5);
  //RIGHT 
  insertInt (RootPointer, 9);
  insertInt (RootPointer, 13);
  insertInt (RootPointer, 11);
  insertInt (RootPointer, 10);
  insertInt (RootPointer, 12);
  insertInt (RootPointer, 14);
  
  
}

void autoFillTree (BST_TREE* RootPointer, int choice) {
  switch (choice) {
    case 1: autoFillTree1(RootPointer); break;
    case 2: autoFillTree2(RootPointer); break;
  }
}

void manualFillTree (BST_TREE* RootPointer) {
  int num=0;

  printf("Enter a list of positive integers;\n");
  printf("Enter a negative number to stop.\n");

  do {
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num > -1) {
      insertInt(RootPointer, num);
    } // valid data
  } while (num > -1);
}

void fillTree (BST_TREE* RootPointer, int isManual) {
  int choice=1;
  (isManual)?manualFillTree(RootPointer):autoFillTree(RootPointer,choice);
}

void printTree(BST_TREE* tree) {

  printf("The tree (%X) is\n", tree->root);
  BST_Traverse (tree, printBST);
  printf("\n");
}

int bigger (int Left, int Right) {
  return ((Left>=Right)?Left:Right);
}

int _longestBranch (NODE* rootPointer) {
  if (rootPointer == NULL) {
    return 0;
  }
  return bigger(_longestBranch(rootPointer->left), _longestBranch(rootPointer->right)) + 1;
}

int SolveBinaryTreeBalanceFactor (BST_TREE* tree, NODE* treeRoot) { //WHY DO I NEED BST_TREE?
  // return _longestBranch(treeRoot->left) - _longestBranch(treeRoot->right);
  // return _longestBranch(tree->root->left) - _longestBranch(tree->root->right);
  return _longestBranch(tree->root->left) - _longestBranch(treeRoot->right);

}

void BinaryTreeBalanceFactor (BST_TREE* tree) {
  printf("The Balance Factor of tree (%X) is %d\n", (int*) tree->root, SolveBinaryTreeBalanceFactor (tree, tree->root));
}

void q2 () {
  printf("Start of Q2\n\n");
  
  int isManual=1;
  BST_TREE* tree = BST_Create(compareInt);
  fillTree(tree, isManual);
  // printTree (tree);
  BinaryTreeBalanceFactor (tree);
  BST_Destroy (tree);

  printf("\nEnd of Q2\n\n");
}

