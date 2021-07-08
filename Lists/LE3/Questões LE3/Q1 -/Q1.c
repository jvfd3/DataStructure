#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD_BinaryTreeSearch/JV/Compacted/BST_ADT.h"

/* Q1 - 
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

/*  ==================== comparePhoneNumber ====================  
      Compare two pointers and return low, equal, high.
      Pre user1 and user2 are valid pointers to the struct USER
      Post return low (-1), equal (0), or high (+1)
*/
int compareNodesPhoneNumbers (void* user1, void* user2) {
/*
  This part is ugly but what it does is:
  It gets two dataPointers that are actually pointers to the struct USER, so they cast it to be
  a pointer to USER type, and then gets the pointer for phoneNumbers, casts it into a pointer to int and then
  grab its internal value
*/
  int key1 = *((int*)  ((USER*)user1)->phoneNumber);
  int key2 = *((int*)  ((USER*)user2)->phoneNumber);

  // return ((key1>key2)?1:(key1==key2)?0:-1);   //Ternary way, but not so easy to understand

  // if less, return -1
  // if equal, return 0
  // else return 1
  if (key1 < key2) {
    return -1;
  }
  if (key1 == key2) {
    return 0;
  }
  return +1;
}


/*  ====================== printUserBST ======================  
  Print Name and PhoneNumber from BST.
      Pre  user is a pointer to an USER struct
      Post "Name: Name_of_USER \t Phone Number: phone_number_of_the_user\n"
*/
void printUserBST (void* user) {
  //Not sure if name will need the extra *
  printf("Name: %s \t Phone Number: %d\n", *((char*)(((USER*)user)->name)), *((int*)(((USER*)user)->phoneNumber)));
  return; //NECESSARY? I don't think so
}


void insertUser       (BST_TREE* RootPointer, int phone, char* name) {  //CHECK LATER IF IT'S WORKING

  USER* userNode = (USER*) malloc (sizeof(USER));
  // Do I need to do these mallocs below? or does the USER* already does something like that?
  // or do they come already with different pointers?
  char* nameElem = (char*) malloc (sizeof(char));
  int* phoneElem = (int*) malloc (sizeof(int));
  //Not really sure of what this if does. I guess it's not necessary in most cases
  if (!userNode) {
    printf("Memory Overflow in add\n"),
    exit(100);
  } // if overflow
  strcpy(nameElem, name);
  *phoneElem = phone;
  userNode->name = nameElem;
  userNode->phoneNumber = phoneElem;
  BST_Insert (RootPointer, userNode);
}


void autoFillUserTree1   (BST_TREE* RootPointer) {
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
  insertUser (RootPointer, "e", 5);
  insertUser (RootPointer, "c", 3);
  insertUser (RootPointer, "b", 2);
  insertUser (RootPointer, "a", 1);
  insertUser (RootPointer, "d", 4);
  insertUser (RootPointer, "f", 6);
  insertUser (RootPointer, "g", 7);
  insertUser (RootPointer, "i", 9);
  insertUser (RootPointer, "h", 8);
  insertUser (RootPointer, "j", 10);
  
}

void autoFillUserTree2   (BST_TREE* RootPointer)  {
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

  insertUser (RootPointer, "h", 8);
  //LEFT
  insertUser (RootPointer, "f", 6);
  insertUser (RootPointer, "g", 7);
  insertUser (RootPointer, "b", 2);
  insertUser (RootPointer, "a", 1);
  insertUser (RootPointer, "d", 4);
  insertUser (RootPointer, "c", 3);
  insertUser (RootPointer, "e", 5);
  //RIGHT
  insertUser (RootPointer, "i", 9);
  insertUser (RootPointer, "m", 13);
  insertUser (RootPointer, "k", 11);
  insertUser (RootPointer, "j", 10);
  insertUser (RootPointer, "l", 12);
  insertUser (RootPointer, "n", 14);
  
  
}

void autoFillUserTree    (BST_TREE* RootPointer, int choice) {
  switch (choice) {
    case 1: autoFillTree1(RootPointer); break;
    case 2: autoFillTree2(RootPointer); break;
  }
}

void manualFillUserTree  (BST_TREE* RootPointer) {
  int num=0;
  char name[100];
  printf("Enter the name and then the phone number;\n");
  printf("Enter \"break\" to stop.\n");

  do {
    printf("\nEnter the users name: ");
    scanf("%s", name);
    if (strcmp(name, "break")==0) {
      printf("\nEnter the phone number: ");
      scanf("%d", &num);
      insertUser(RootPointer, name, num);
    } else {
      printf("You decided to halt the operation. Redirecting to the main menu...\n");
    }
  } while (strcmp(name, "break")==0);
}

void fillUserTree (BST_TREE* RootPointer, int isManual) {
  int choice=1;
  (isManual)?manualFillTree(RootPointer):autoFillTree(RootPointer,choice);
}

void printTree (BST_TREE* RootPointer) {

  printf("The tree (%X) contains the users:\n", RootPointer->root);
  BST_Traverse (RootPointer, printUserBST);
  printf("\n");
}

void removeUser (BST_TREE* RootPointer) {
  char name[100];
  printf("\n\n Type the name you want to be removed: ");
  scanf("%d", name);
  BST_Delete (RootPointer, (NODE*) checkUserTraversing (RootPointer, name));
}

void matches (void* nodeName) { //WIP
  printf("Still WIP, don't bother\n\n");
  /*I should do something here so that the code could traverse the BST comparing it*/
}

void checkUserTraversing (BST_TREE* RootPointer, char* name) { //WIP
  // somewhere during those traverses, I should receive a pointer to the node that is equal
  BST_Traverse (RootPointer, matches);
}

/*Should somehow return the pointer, so it can be used to erase a user*/
void checkUser (BST_TREE* RootPointer) { //WIP
  char name[100];
  printf("\n\n Type the name you want to be checked: ");
  scanf("%d", name);
  checkUserTraversing (RootPointer, name);
}

void fillFromTXT(tree) {
  /*Read file, separate strings, turn phone into int, convert to the boat*/
}

void writeTreeToTXT(tree) {
  /*Read tree, traversing, using stocked names, it prints the names in orderm*/
}

void menu (BST_TREE* RootPointer) {
  
  int choice=-1;
  do {

    printf("= = = Welcome to the Menu, what do you want to do now? = = =\n\n");
    printf("(Enter \"0\" to stop)\n");
    printf("Type \t to\n");
    printf("1)\t type a name to check if it's in the tree\n");
    printf("2)\t insert a new user\n");
    printf("3)\t remove an existing user using its name\n");
    printf("4)\t print the whole tree\n");
    scanf("%d", &choice);

    while ((choice>4)||(choice<0)) {
      printf("Invalid option, please type another option:\t");
      scanf("%d", &choice);
    }

    switch (choice) {
      case 0: printf("EXIT input, ending Menu...\n\n"); break;

      case 1: checkUser           (RootPointer);  break;
      case 2: manualFillUserTree  (RootPointer);  break;
      case 3: removeUser          (RootPointer);  break;
      case 4: printTree           (RootPointer);  break;

      default:printf("Not a valid option.\n");    break;
    }
  } while (choice!=0);
}

void q1() {
  printf("Start of Q1\n\n");
  
  int isManual=0;
  BST_TREE* tree = BST_Create(compareNodesPhoneNumbers);
  // fillFromTXT(tree);
  menu(tree);
  // fillTree(tree, isManual);
  //  writeTreeToTXT (tree);
  // printTree(tree);  
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
    Search          +-
  endMenu           X
  WriteToText       O
  Destroy           X

  
*/
  

}

int main () {
  q1();
}
