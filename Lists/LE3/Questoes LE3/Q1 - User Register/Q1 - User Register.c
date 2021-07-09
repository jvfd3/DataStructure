#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD_BinaryTreeSearch/JV/Compacted/BST_ADT.h"

/* Q1 - User Register
Escreva um programa em C,
que leia uma lista de nomes de pessoas
e seus respectivos números de telefones,
a partir de um arquivo de texto, e
insira esses dados em uma árvore de busca binária.
Após a criação da árvore,
mostrar um menu que permita ao usuário:
  i. realizar uma busca na árvore por um nome específico;
  ii. inserir um novo nome;
  iii. eliminar um nome existente;
  iv. imprimir a lista inteira.

Ao finalizar,
escrever os dados da lista de volta ao arquivo.
Testar o programa com pelo menos 10 nomes.


*/


typedef struct User {
  char* name;
  int*  phoneNumber;
} USER;

// ############ INDEPENDENT FUNCTIONS ############
/*  ==================== comparePhoneNumber ====================  
      Compare two pointers and return low, equal, high.
      Pre user1 and user2 are valid pointers to the struct USER
      Post return low (-1), equal (0), or high (+1)
*/
int compareNodesNames (void* user1, void* user2) {
/*  review it later
  This part is ugly but what it does is:
  It gets two dataPointers that are actually pointers to the struct USER, so they cast it to be
  a pointer to USER type, and then gets the pointer for names, casts it into a pointer to int and then
  grab its internal value
*/
// is this * out of everything really needed?
  char* name1 = (char*)  ((USER*)user1)->name;
  char* name2 = (char*)  ((USER*)user2)->name;
  int strcmpResult = strcmp(name1,name2);
  /* switch (strcmpResult) {
    case -1:  {
      printf("Comparing names %s and %s. %s is bigger\n", name1, name2, name2);
      break;
    }
    case 1:  {
      printf("Comparing names %s and %s. %s is bigger\n", name1, name2, name1);
      break;
    }
    default: {
      printf("Comparing names %s and %s. They are the same.\n", name1, name2);
      break;
    }
  } */
  return strcmpResult;
}

/*  ====================== printUserBST ======================  
  Print Name and PhoneNumber from BST.
      Pre  user is a pointer to an USER struct
      Post "Name: Name_of_USER \t Phone Number: phone_number_of_the_user\n"
*/
void printUserBST (void* user) {
  //Not sure if name will need the extra *
  int   phone = *((int *)(((USER*)user)->phoneNumber));
  char* name  =   (char*)(((USER*)user)->name);

  printf("Name: %s \t Phone Number: %d\n", name, phone);
  return; //NECESSARY? I don't think so
}

USER* createStruct (char* name, int phone) {//CHECK LATER IF IT'S WORKING

  USER* userNode = (USER*) malloc (sizeof(USER));
  //Not really sure of what this if does. I guess it's not necessary in most cases
  if (!userNode) {
    printf("Memory Overflow in add\n"),
    exit(100);
  } // if overflow

  // Do I need to do these mallocs below? or does the USER* already does something like that?
  // or do they come already with different pointers?
  char* nameElem = (char*) malloc (sizeof(strlen(name)));
  strcpy(nameElem, name);
  userNode->name = nameElem;

  int* phoneElem = (int*) malloc (sizeof(int));
  *phoneElem = phone;
  userNode->phoneNumber = phoneElem;
  return userNode;
}

 
 
 
// ############ DEPENDENT FUNCTIONS ############
 
 
void printTree            (BST_TREE* tree) {
  printf("The tree (%X) contains the users:\n", tree->root);
  BST_Traverse (tree, printUserBST);
  printf("\n");
}
 
void insertUser           (BST_TREE* tree, char* name, int phone) {  //CHECK LATER IF IT'S WORKING
  BST_Insert (tree, createStruct(name, phone));
}
 
void autoFillUserTree1    (BST_TREE* tree) {
 // 5 3 2 1 4 6 7 9 8 10
 /* Balance: -1
      5
     / \
    3   6
   / \   \
  2   4   7
 /         \
1           8
           / \ 
          9   10
 
 */
  insertUser (tree, "e", 5);
  insertUser (tree, "c", 3);
  insertUser (tree, "b", 2);
  insertUser (tree, "a", 1);
  insertUser (tree, "d", 4);
  insertUser (tree, "f", 6);
  insertUser (tree, "g", 7);
  insertUser (tree, "i", 9);
  insertUser (tree, "h", 8);
  insertUser (tree, "j", 10);
  
}
 
void autoFillUserTree2    (BST_TREE* tree)  {
 // 8 6 7 2 1 4 3 5 9 13 11 10 12 14
 /* balance: 0
        8
       / \
      /   \
     /     \
    6       9
   / \       \
  2   7       13
 / \         /  \
1   4      11    14
   / \    /  \
  3   5 10    12

 */

  insertUser (tree, "h", 8);
  //LEFT
  insertUser (tree, "f", 6);
  insertUser (tree, "g", 7);
  insertUser (tree, "b", 2);
  insertUser (tree, "a", 1);
  insertUser (tree, "d", 4);
  insertUser (tree, "c", 3);
  insertUser (tree, "e", 5);
  //RIGHT
  insertUser (tree, "i", 9);
  insertUser (tree, "m", 13);
  insertUser (tree, "k", 11);
  insertUser (tree, "j", 10);
  insertUser (tree, "l", 12);
  insertUser (tree, "n", 14);
  
  
}
 
void autoFillUserTree     (BST_TREE* tree, int choice) {
  switch (choice) {
    case 1: autoFillUserTree1(tree); break;
    case 2: autoFillUserTree2(tree); break;
  }
}

void manualFillUserTree   (BST_TREE* tree) {
  int phone=-1;
  char name[100];
  printf("Enter the name and then the phone number;\n");
  printf("Enter \"break\" to stop.\n");

  do {
    printf("\nEnter the users name (or \"break\" to stop): ");
    scanf("%s", name);
    if (strcmp(name, "break")!=0) {
      printf("\nEnter the phone number: ");
      scanf("%d", &phone);
      insertUser(tree, name, phone);
    } else {
      printf("You decided to halt the operation. Redirecting to the main menu...\n");
    }
  } while (strcmp(name, "break")!=0);
}

void fillUserTree         (BST_TREE* tree, int isManual) {
  int choice=1;
  (isManual)?manualFillUserTree(tree):autoFillUserTree(tree,choice);
}
 
/*  ==================== _delete ==================== 
  Deletes node from the tree and rebalances 
  tree if necessary. 
     Pre    tree initialized--null tree is OK.
            dataPtr contains key of node to be deleted
     Post   node is deleted and its space recycled
            -or- if key not found, tree is unchanged 
     Return success is true if deleted; false if not found
            pointer to root
*/
NODE*  _check             (BST_TREE* tree, NODE* root, void* dataPtr) {
// Local Definitions 
//  Statements 
  if (!root) {
    return NULL;
  } // if 
  
  int compareReturn = tree->compare(dataPtr, root->dataPtr);

  NODE* temp;
  if (compareReturn < 0) {
    temp  = _check (tree, root->left, dataPtr);
  } else if (compareReturn > 0) {
    temp = _check (tree, root->right, dataPtr);
  } else {
    return root;  // node found
  }
  return temp;  // node found
}  // _check 

void checkUser            (BST_TREE* tree) { //WIP
  char name[100];
  printf("\n\nType the name you want to be checked: ");
  scanf("%s", name);
  int* nullInt = (int*) malloc (sizeof(int));  
  NODE* pointerFound = _check (tree, tree->root, createStruct(name, *nullInt));
  if (pointerFound) {
    printf("The user %s was found in the tree (%X) at the pointer (%X)\n", name, tree, pointerFound);
  } else {
    printf("The user %s was NOT found in the tree (%X)\n", name, tree, pointerFound);
  }
  
}

void removeUser           (BST_TREE* tree) {
  char name[100];
  printf("\n\n Type the name you want to be removed: ");
  scanf("%s", name);
  int* nullInt = (int*) malloc (sizeof(int));  
  NODE* pointerFound = _check (tree, tree->root, createStruct(name, *nullInt));
  if (pointerFound) {
    printf("The user %s was found in the tree (%X) at the pointer (%X) and will be erased\n", name, tree, pointerFound);
    // printf("user %s||tree (%X)||pointer (%X)||\n", name, tree, pointerFound);
    // printf("userName %s||userPhoneNumber\n", ((USER*)(pointerFound->dataPtr))->name, ((USER*)(pointerFound->dataPtr))->phoneNumber);

    
    BST_Delete (tree, pointerFound);
  } else {
    printf("The user %s was NOT found in the tree (%X)\n", name, tree, pointerFound);
  }
}
/* 
void fillFromTXT          (BST_TREE* tree) {
  // Read file, separate strings, turn phone into int, convert to the boat
}

void writeTreeToTXT       (BST_TREE* tree) {
  // Read tree, traversing, using stocked names, it prints the names in order
}
  */
void menu                 (BST_TREE* tree) {

  int choice=999;
  do {  //menu texts
    printf("= = = Welcome to the Menu, what do you want to do now? = = =\n\n");
    printf("(Enter \"0\" to stop)\n");
    printf("Type \t to\n");
    printf("1)\t type a name to check if it's in the tree\n");
    printf("2)\t insert a new user\n");
    printf("3)\t remove an existing user using its name\n");
    printf("4)\t print the whole tree\n\n");
    printf("Type your choice:\t");
    scanf("%d", &choice);
    printf("\nYour choice was %d.\n", choice);
    
    //THIS ISN'T WORKING AND I DON'T KNOW WHY

    while (!(0<choice && choice<5)) {
      printf("Invalid option, please type a valid one:\t");
      scanf("%d", &choice);
    }

    switch (choice) {
      case 0: printf("EXIT input, ending Menu...\n\n"); break;

      case 1: checkUser           (tree);  break;
      case 2: manualFillUserTree  (tree);  break;
      case 3: removeUser          (tree);  break;
      case 4: printTree           (tree);  break;

      default:printf("X X X X Invalid option X X X X\n");    break;
    }
  } while (choice!=0);
}

void q1() {
  printf("Start of Q1\n\n");
  
  int isManual=0;
  BST_TREE* tree = BST_Create(compareNodesNames);
  fillUserTree(tree, isManual);
  // fillFromTXT(tree);
  menu(tree);
  // printTree(tree);  
  //  writeTreeToTXT (tree);
  BST_Destroy (tree);

  printf("\nEnd of Q1\n\n");

/*
  Cria árvore       X
  FillFromText      O

  Menu:             X
    Fill            X
      AutoFill      X
      ManualFill    X
    Print           X
    Insert          X
    Remove          +-
    Search          X
  endMenu           X
  WriteToText       O
  Destroy           X

  
*/
  

}

int main () {
  q1();
}
