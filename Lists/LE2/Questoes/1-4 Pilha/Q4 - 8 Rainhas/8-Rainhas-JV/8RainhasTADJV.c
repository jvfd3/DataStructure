//  ===================== 8QUEENS TADFILES =====================

// not used at all
/*  ===================== getSize =====================
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

// really important but a little forgotten
/*  ===================== guarded =====================
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

// not used: it only runs once
/*  =================== fillBoard =====================
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

// not used: it empties the stack, I don't want my stack gone
/*  =================== printBoard =====================
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


//  =================== MY LITTLE MESS =====================


/*  =================== placeQueen =====================
    it places a 1 in the board and stacks the position of the queen
*/
void placeQueen (int board[][9], int row, int col, STACK* stack) {
  board[row][col] = 1;  //is it necessary? Yes, "Guarded" will use this to compare

  POSITION* pPos = (POSITION*)malloc(sizeof(POSITION));
  pPos->row = row;
  pPos->col = col;
    
  pushStack(stack, pPos);
}


/*  =================== removeQueen =====================
    if the stack is not empty,  it unstacks the queen and set its position as the
    new position so that the code can keep running from its last location
    if the stack is empty, it is set to stop repeating, because if it is empty
    it means that all the queens are gone, and the queen from the first row is gone
    (is already after the last column in the first row), so it needs to be stopped
*/
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


/*  =================== nonDestructivePrintBoard =====================
  Prints the layout of the queens that are stacked, but without losing the stack
  so the function cocktails all the popped pointers back in the stack
  It's similar to a printStack function in a way.
*/
void nonDestructivePrintBoard (STACK* stack, int boardSize) {


  int col;
  POSITION* pPos;
  STACK*    pOutStack = createStack ();
  // if everything is right, you'll only see it when boardSize==2 or ==3
  if (emptyStack(stack)) {
    printf("There are no positions on this board\n");
    return;
  }

  // Reverse stack for printing (get ready for the cocktail)
  while (!emptyStack (stack)) {
    pushStack (pOutStack, popStack (stack));
  }

  // Now print board 
  while (!emptyStack (pOutStack)) {
    pPos = popStack (pOutStack);
    printf("Row %d-Col %d: \t|", pPos->row, pPos->col);
    for (col = 1; col <= boardSize; col++) {
      // Ternary operators FTW
      printf("%s", (pPos->col == col)?" Q |":"   |");
      
      //  If you don't like ternary operators, here is the equivalent if else statement 
      /*  
        if (pPos->col == col){
          printf(" Q |");
        } else {
          printf("   |");
        }
      */

    }
    // who doesn't like some space?
    printf("\n");
    
    // Here is your cocktail
    pushStack (stack, pPos);
    // probably that is the most significant change from the other code
  }

  destroyStack(pOutStack);

}  // printBoard 


/*  =================== fillBoardMulti =====================
    It prints multiple layouts from 4 to 8 queens.
*/
void fillBoardMulti (STACK* stack, int boardSize) {
  
  // I would like to start the column as 1, but failed everytime
  int   row = 1, col = 0, cont=0, keepRepeating = 1, board[9][9] = {0};
  // I think using "keepReapting" was kinda cheat, but it worked *shrug*

  printf("\n\n### STARTING THE FUNCTION FOR BOARDSIZE = %d!!! ###\n\n", boardSize);

  while (keepRepeating) {   // Maybe another condition could be better
    while (row <= boardSize && col<=boardSize) {  //it is better to stay inside, kids
      col++;

      /*  If it's not guarded by any previous queen and col <=boardsize, 
        place a new Queen */
      if ((!guarded  (board, row, col, boardSize)) && col<=boardSize) {
        placeQueen  (board, row, col, stack);
        row++;
        col = 0;
      }
      //  if a queen was placed in the last row (row>boardSize and col==0)

      //  if row>boardSize, and col was just reseted, add one layout and print it
      if ((row>boardSize) && (col==0)) {
        cont++;
        printf("\n\t\tLayout %d:\t\n", cont);
        nonDestructivePrintBoard (stack, boardSize);
      }

      /*  this will unstack queens when a valid layout was not achieved and absorb
          her position so that the code resumes at it
          but if the stack goes empty, "keepRepeating" turns 0 and it stops
      */
      while ((col >= boardSize) && keepRepeating) {
        removeQueen (board, &row,  &col, stack, &keepRepeating);
      }

    }
    
    /*  I'm not really sure what I actully did here.
        if I'm not wrong, when a valid layout was found, the last Queen is popped
        and by doing so, the code can keep running after it.
        and will only stop when the Queen from the first row reached col>boardSize
    */
    if ((row>=boardSize) && keepRepeating) {
        removeQueen (board, &row,  &col, stack,&keepRepeating);
    }
  }

  printf("\nThere were %d total different layouts.\n", cont);
  printf("\n\n### ENDING THE FUNCTION FOR BOARDSIZE = %d!!! ###\n\n", boardSize);
}  // fillBoard 
