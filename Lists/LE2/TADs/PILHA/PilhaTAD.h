/*  ================== insertData ==================
  This program creates random character data and 
  inserts them into a linked list stack.
     Pre  pStackTop is a pointer to first node 
     Post Stack has been created 
*/
void insertData (STACK_NODE** pStackTop){
//  Local Definitions 
  char  charIn;
  bool  success;

//  Statements 
  printf("Creating characters: ");
  int nodeCount;
  for (nodeCount = 0; nodeCount < 10; nodeCount++) {
    // Generate uppercase character 
    charIn  = rand() % 26 + 'A';
    printf("%c", charIn);
    success = push(pStackTop, charIn);
    if (!success) {
      printf("Error 100: Out of Memory\n");
      exit (100);
    } // if 
  } // for 
  printf("\n");
  return;
}  // insertData 


/*  =================== push ====================
  Inserts node into linked list stack. 
     Pre  pStackTop is pointer to valid stack
     Post charIn inserted
     Return  true  if successful
             false if underflow
*/
bool push (STACK_NODE** pStackTop, char charIn) {
//  Local Definitions 
  STACK_NODE* pNew;
  bool        success;
  
//  Statements 
  pNew = (STACK_NODE*)malloc(sizeof (STACK_NODE));
  if (!pNew) {
    success = false;
  } else {
    pNew->data =  charIn;
    pNew->link = *pStackTop;
    *pStackTop =  pNew;
    success = true;
  } // else 
  return success;
}  // push 


/*  ===================== print ==================== 
  This function prints a singly linked stack.
     Pre     pStackTop is pointer to valid stack
     Post    data in stack printed
*/
void print (STACK_NODE** pStackTop) {
  //  Local Definitions 
  char printData;

  //  Statements 
  printf("Stack contained:     ");
  while (pop(pStackTop, &printData)) {
    printf("%c", printData);
  }
  // return;  // eh necessario esse return? imagino que nao
}  // print 


/*  =================== pop ====================
  Delete node from linked list stack. 
     Pre  pStackTop is pointer to valid stack
     Post charOut contains deleted data
     Return  true  if successful
             false if underflow
*/
bool pop (STACK_NODE** pStackTop, char* charOut) {
  //  Local Definitions
  STACK_NODE* pDlt;
  bool         success;
  
  //  Statements 
  if (*pStackTop) {
    success    = true;
    *charOut   = (*pStackTop)->data;
    pDlt       = *pStackTop;
    *pStackTop = (*pStackTop)->link;
    free (pDlt);
  } else {
    success = false;
  }
  return success;
}  // pop 



// /*  ================= emptyStack ================
//   This function determines if a stack is empty 
//      Pre  stack is pointer to a stack
//      Post returns 1 if empty; 0 if data in stack 
// */
// bool emptyStack(STACK *stack) {
//   //  Statements
//   return (stack->count == 0);
// } // emptyStack
