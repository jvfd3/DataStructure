
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../PilhaJV/PilhaJV.h"

/*  Structure Declarations */
  typedef struct {
    int  row;
    int  col;
  } POSITION;

#include "8RainhasTADJV.c"         /* Eight Queens everything*/

  /*  Prototype Declarations */
  int   getSize     (void);
  void  fillBoard   (STACK* stack, int boardSize);
  void  printBoard  (STACK* stack, int boardSize);
  bool  guarded     (int board[][9], int row, int col, int boardSize);
