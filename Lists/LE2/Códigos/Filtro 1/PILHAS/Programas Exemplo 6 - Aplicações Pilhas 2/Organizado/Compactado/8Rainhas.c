/*	This program tests the eight queens algorithm. Eight 
	queens is a classic chess problem in which eight 
	queens are placed on a chess board in positions 
	such that no queen can capture another queen.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include "stacksADT.h" 

/*	Structure Declarations */
	typedef struct
	   {
	    int  row;
	    int  col;
	   } POSITION;

/*	Prototype Declarations */
int  getSize   (void);

void fillBoard  (STACK* stack, int boardSize);
void printBoard (STACK* stack, int boardSize);

bool guarded (int board[][9], int row, int col, int boardSize);

#include "8Rainhas.h"		/* Eight Queens everything*/

// #include "GetSize.h"			/* Eight Queens: Get Board Size */
// #include "FillBoard.h"		/* Eight Queens: Fill Board */
// #include "Guarded.h"			/* Eight Queens: Guarded */
// #include "PrintBoard.h"		/* Eight Queens: Print Board */

int main (void) 
{
/*	Local Definitions */
	int  boardSize;
	
	STACK* stack ;

/*	Statements */
	boardSize = getSize ();
	stack     = createStack ();
	
	fillBoard    (stack, boardSize);
	printBoard   (stack, boardSize);
	destroyStack (stack);

	printf("\nWe hope you enjoyed Eight Queens.\n");
	return 0;
}	/* main */

/*	Results
Welcome to Eight Queens. You may select
a board size from 4 x 4 to 8 x 8. I will
then position a queen in each row of the
board so no queen may capture another 
queen. Note: There are no solutions for  
boards less than 4 x 4.

Please enter the board size: 4

Place queens in following positions:
Row 1-Col 2:    | Q |   |   |
Row 2-Col 4:    |   |   | Q |
Row 3-Col 1:  Q |   |   |   |
Row 4-Col 3:    |   | Q |   |

We hope you enjoyed Eight Queens.
*/