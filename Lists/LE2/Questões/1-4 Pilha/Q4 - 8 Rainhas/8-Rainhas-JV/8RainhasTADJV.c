

/*  ===================== getSize ======================
  Prompt user for a valid board size.
    Pre  nothing 
    Post valid board size returned 
*/
int getSize (void) {
  //  Local Definitions 
  int boardSize;

//  Statements 
  printf("Welcome to Eight Queens. You may select\n"
         "a board size from 4 x 4 to 8 x 8. I will\n" 
         "then position a queen in each row of the\n"
         "board so no queen may capture another\n"
         "queen. Note: There are no solutions for \n"
         "boards less than 4 x 4.\n");
  printf("\nPlease enter the board size: ");
  scanf ("%d", &boardSize);
  while (boardSize < 4 || boardSize > 8) {
    printf("Board size must be greater than 3 \n"
           "and less than 9. You entered %d.\n"
           "Please re-enter. Thank you.\a\a\n\n"
           "Your board size: ", boardSize);
    scanf ("%d", &boardSize);
  } // while 
  return boardSize;
}  // getSize 


/*  ===================== guarded ==================
  Checks rows, columns, diagonals for guarding queens 

     Pre  board contains current positions for queens
          chkRow & chkCol are position for new queen
          boardSize is number of rows & cols in board
     Post returns true if guarded; false if not
*/
bool guarded (int board[][9], int chkRow, int chkCol, int boardSize) {
  //  Local Definitions 
  int row;
  int col = chkCol;
  
  //  Statements 

  // Check current col for a queen 
  for (row = 1; row <= chkRow; row++) {
    if (board[row][col] == 1) {
      return true;
    }
  }
  // Check diagonal right-up 
  for (row = chkRow - 1, col = chkCol + 1; row > 0 && col <= boardSize; row--, col++) {
    if (board[row][col] == 1) {
      return true;
    }
  }

  // Check diagonal left-up 
  for (row = chkRow - 1, col = chkCol - 1; row > 0 && col > 0; row--, col--) {
    if (board[row][col] == 1) {
      return true;
    }
  }
  return false;
}  // guarded 


/*  =================== fillBoard ====================
  Position chess queens on game board so that no queen 
  can capture any other queen.
    Pre  boardSize number of rows & columns on board
    Post Queens positions filled
*/
void fillBoard (STACK* stack, int boardSize) {
  //  Local Definitions
  int  row;
  int  col;
  int  board[9][9] = {0};  // 0 no queen: 1 queen 
                           // row 0 & col 0 !used 
  POSITION* pPos;

  //  Statements 
  row = 1;    //why do rows starts at 1 but not columns?  Because chess starts with row 1
  col = 0;
  
  while (row <= boardSize) {    //Can I remove this while?
    while (col <= boardSize && row <= boardSize) {
      col++;    //can I take it out and start columns as 1? NO.
                // but could I postpone it?
      if (!guarded(board, row, col, boardSize)) {
        board[row][col] = 1;

        pPos = (POSITION*)malloc(sizeof(POSITION));
        pPos->row = row;
        pPos->col = col;
          
        pushStack(stack, pPos);
        
        row++;
        col = 0;  // can I make it equal to 1?
      } // if 
      while (col >= boardSize) {  //could it be an if?
        pPos = popStack(stack);
        row  = pPos->row;
        col  = pPos->col;
        board[row][col] = 0;
        free (pPos);
      } // while col 
    } // while col 
  } // while row 
  // return; // do I need it here? I guess not
}  // fillBoard 



/*  =================== printBoard ====================
  Print positions of chess queens on a game board 
  Pre  stack contains positions of queen
       boardSize is the number of rows and columns
  Post Queens� positions printed
*/
void printBoard (STACK* stack, int boardSize) {
  //  Local Definitions 
  int col;
  
  POSITION* pPos;
  STACK*    pOutStack;
  
  //  Statements 
  if (emptyStack(stack)) {
    printf("There are no positions on this board\n");
    return;
  } // if 
      
  printf("\nPlace queens in following positions:\n");
  
  // Reverse stack for printing 
  pOutStack = createStack ();
  while (!emptyStack (stack)) {
    pPos = popStack (stack);
    pushStack (pOutStack, pPos);
  } // while 
  
  // Now print board 
  while (!emptyStack (pOutStack)) {
    pPos = popStack (pOutStack);
    printf("Row %d-Col %d: \t|", pPos->row, pPos->col);
    for (col = 1; col <= boardSize; col++) {
      if (pPos->col == col){
        printf(" Q |");
      } else {
        printf("   |");
      }
    } // for 
    printf("\n");
  } // while 
  destroyStack(pOutStack);
  return;   //Is it needed? I guess it's not
}  // printBoard 

//  ===================== MY LITTLE MESS ============================

void placeQueen (int board[][9], int row, int col, STACK* stack) {
  board[row][col] = 1;  //is it necessary? Yes, "Guarded" will use this to compare

  POSITION* pPos = (POSITION*)malloc(sizeof(POSITION));
  pPos->row = row;
  pPos->col = col;
    
  pushStack(stack, pPos);
}

void removeQueen  (int board[][9], int* row, int* col, STACK* stack, int* keepRepeating)  {
  if (!emptyStack(stack)) {
    POSITION* pPos = popStack(stack);
    *row  = pPos->row;
    *col  = pPos->col;
    board[*row][*col] = 0;
    free (pPos);
  } else {
    *keepRepeating=0;
  }
}

/*  =================== printBoard ====================
  Print positions of chess queens on a game board 
  Pre  stack contains positions of queen
       boardSize is the number of rows and columns
  Post Queens� positions printed
*/
void printBoardMuli (STACK* stack, int boardSize, int* row2, int* col2) {
  //  Local Definitions 
  int col;


  POSITION* pPos = stackTop (stack);;
  STACK*    pOutStack;

  
  *row2=pPos->row;
  *col2=pPos->col;
  
  //  Statements 
  if (emptyStack(stack)) {
    printf("There are no positions on this board\n");
    return;
  } // if 
      
  printf("\nPlace queens in following positions:\n");
  
  // Reverse stack for printing 
  pOutStack = createStack ();
  while (!emptyStack (stack)) {
    pPos = popStack (stack);
    pushStack (pOutStack, pPos);
  } // while 
  
  // Now print board 
  while (!emptyStack (pOutStack)) {
    pPos = popStack (pOutStack);
    printf("Row %d-Col %d: \t|", pPos->row, pPos->col);
    for (col = 1; col <= boardSize; col++) {
      if (pPos->col == col){
        printf(" Q |");
      } else {
        printf("   |");
      }
    } // for 
    printf("\n");
  } // while 
  destroyStack(pOutStack);
  return;   //Is it needed? I guess it's not
}  // printBoard 


/*  =================== printBoard ====================
  Print positions of chess queens on a game board 
  Pre  stack contains positions of queen
       boardSize is the number of rows and columns
  Post Queens� positions printed
*/
void nonDestructivePrintBoard (STACK* stack, int boardSize) {
  //  Local Definitions 
  int col;
  
  POSITION* pPos;
  STACK*    pOutStack;
  
  //  Statements 
  if (emptyStack(stack)) {
    printf("There are no positions on this board\n");
    return;
  } // if 
      
  printf("\nPlace queens in following positions:\n");
  
  

  // Reverse stack for printing 
  pOutStack = createStack ();
  while (!emptyStack (stack)) {
    pPos = popStack (stack);
    // printf("outta stack (%X)\n",pPos);
    pushStack (pOutStack, pPos);
  } // while 
  
  // Now print board 
  while (!emptyStack (pOutStack)) {
    pPos = popStack (pOutStack);
    printf("Row %d-Col %d: \t|", pPos->row, pPos->col);
    for (col = 1; col <= boardSize; col++) {
      if (pPos->col == col){
        printf(" Q |");
      } else {
        printf("   |");
      }
    } // for 
    printf("\n");
    // printf("into stack (%X)",pPos);
    pushStack (stack, pPos);
  } // while 
  destroyStack(pOutStack);
  return;   //Is it needed? I guess it's not
}  // printBoard 


/*  =================== fillBoardMulti ====================
  Position chess queens on game board so that no queen 
  can capture any other queen.
    Pre  boardSize number of rows & columns on board
    Post Queens positions filled
*/
void fillBoardMultiOld (STACK* stack, int boardSize) {
  //  Local Definitions
  int  row = 1;
  int  col = 0;
  int  board[9][9] = {0};  // 0 no queen: 1 queen row 0 & col 0 !used 
  int cont=0;
  int keepRepeating = 1;

  printf("\n\n\n");
  printf("##########################################################\n");
  printf("STARTING THE FUNCTION FOR BOARDSIZE = %d!!!\n\n", boardSize);

  while ((cont<94)&&keepRepeating) {

    while (row <= boardSize && col<=boardSize) {  //is this "col" useless?
      col++;    //can I take it out and start columns as 1? NO. but could I postpone it?

      if (!guarded  (board, row, col, boardSize)) {
        placeQueen  (board, row, col, stack);
        printf("P(%d, %d) ", row, col);
        row++;
        col = 0;  // can I make it equal to 1?  
      } // if 

      if (row>boardSize) {
        cont++;
        printf("\nLayout %d:\t", cont);
        if (cont>8) {
          nonDestructivePrintBoard (stack, boardSize);
        }
      }
        if (cont>8) {
          printf(" (%d, %d) ", row, col);
        }
      while ((col >= boardSize)&&keepRepeating) {  //could it be an if? No. But why?
        printf("(%d, %d)->R->", row, col);
        removeQueen (board, &row,  &col, stack,&keepRepeating);
        printf("(%d, %d) ", row, col);
      } // while col 
    } // while col 
    
    if ((row>=boardSize)&&keepRepeating) {
        printf("(%d, %d)->X->", row, col);
        removeQueen (board, &row,  &col, stack,&keepRepeating);
        printf("(%d, %d) ", row, col);
    }
  }
  printf("\n\nThere were %d total different layouts\n", cont);

  printf("ENDING THE FUNCTION FOR BOARDSIZE = %d!!!\n\n", boardSize);
  printf("##########################################################\n");
  printf("\n\n\n");
}  // fillBoard 



/*  =================== fillBoardMulti ====================
  Position chess queens on game board so that no queen 
  can capture any other queen.
    Pre  boardSize number of rows & columns on board
    Post Queens positions filled
*/
void fillBoardMulti (STACK* stack, int boardSize) {
  //  Local Definitions
  int  row = 1;
  int  col = 0;
  int  board[9][9] = {0};  // 0 no queen: 1 queen row 0 & col 0 !used 
  int cont=0;
  int keepRepeating = 1;

  printf("\n\n\n");
  printf("##########################################################\n");
  printf("STARTING THE FUNCTION FOR BOARDSIZE = %d!!!\n\n", boardSize);

  while ((cont<94)&&keepRepeating) {

    while (row <= boardSize && col<=boardSize) {  //is this "col" useless?
      col++;    //can I take it out and start columns as 1? NO. but could I postpone it?
      
      //  If it's not guarded by any previous queen, place a new Queen
      if (!guarded  (board, row, col, boardSize)) {
        placeQueen  (board, row, col, stack);
        printf("P(%d, %d) ", row, col);
        row++;
        col = 0;  // can I make it equal to 1?  
      } // if 
      // then row++ and col=0

      //  if a queen was placed in the last row (row>boardSize and col==0
      //  add one layout and print it
      if ((row>boardSize) && (col==0)) {
        cont++;
        printf("\nLayout %d:\t", cont);
        if (cont>8) { //temp
          nonDestructivePrintBoard (stack, boardSize);
        }
      }
      //This part doesn't seem weird at all

      if (cont>8) {
        printf(" (%d, %d) ", row, col);
      }

      while ((col >= boardSize)&&keepRepeating) {  //could it be an if? No. But why?
        printf("(%d, %d)->R->", row, col);
        removeQueen (board, &row,  &col, stack,&keepRepeating);
        printf("(%d, %d) ", row, col);
      } // while col 
    } // while col 
    
    if ((row>=boardSize)&&keepRepeating) {
        printf("(%d, %d)->X->", row, col);
        removeQueen (board, &row,  &col, stack,&keepRepeating);
        printf("(%d, %d) ", row, col);
    }
  }
  printf("\n\nThere were %d total different layouts\n", cont);

  printf("ENDING THE FUNCTION FOR BOARDSIZE = %d!!!\n\n", boardSize);
  printf("##########################################################\n");
  printf("\n\n\n");
}  // fillBoard 
