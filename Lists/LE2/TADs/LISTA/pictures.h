//============16============
/*	Data Structure for Academy Awards
	   Written by:
	   Date:
*/

//const short STR_MAX = 41;
#define STR_MAX 41

typedef struct
	{
	 short   year; 
	 char    picture [STR_MAX];
	 char    director[STR_MAX];
	} PICTURE; 

//============16============
//============18============
/*	================== printInstr =================
	Print instructions to user.
	   Pre    nothing
	   Post   instructions printed
*/
void printInstr (void)
{
//	Statements 
	printf("This program prints the Academy Awards \n"
	  "Best Picture of the Year and its director.\n"
	  "Your job is to enter the year; we will do\n"
	  "the rest. Enjoy.\n");
	return;
}	// instr 

//============18============
//============19============
/*	==================== buildList ====================
	Reads a text data file and loads the linked list
	Pre    file exists in format: yy \t 'pic' \t 'dir'
	Post   list contains data
	       -or- program aborted if problems
*/
LIST* buildList (void)
{
//	Local Definitions 
	FILE* fpData;
	LIST* list;
	
	short  yearIn;
	int    addResult;
	
	PICTURE* pPic;
	
//	Statements 
	list   = createList (cmpYear);
	if (!list)
	    printf("\aCannot create list\n"),
	           exit (100);
	fpData = fopen("pictures.dat", "r");
	if (!fpData)
	    printf("\aError opening input file\n"),
	           exit (110);
	while (fscanf(fpData, " %hd", &yearIn) == 1)
	   {
	    pPic = (PICTURE*) malloc(sizeof(PICTURE));
	    if (!(pPic))
	        printf("\aOut of Memory in build list\n"),
	               exit (100);
	    pPic->year = yearIn;
	    	    
	    // Skip tabs and quote 
	    while ((fgetc(fpData)) != '"')
	       ;
	    fscanf(fpData, "%40[^\"] %*c", pPic->picture);
			    	    
	    while ((fgetc(fpData)) != '"')
	       ;
	    fscanf(fpData, "%40[^\"] %*c", pPic->director);
			            
	    // Insert into list 
	    addResult = addNode (list, pPic);
	    if (addResult != 0)
	        if (addResult == -1)
	            printf("Memory overflow adding movie\a\n"),
	                    exit (120);
	        else
	            printf("Duplicate year %hd not added\n\a",
	                    pPic->year);
	    while (fgetc(fpData) == '\n')
	       ;
	   } // while 
	return list;
}	// buildList 

//============19============
//============20============
/*	=================== process ===================
	Process user choices
	Pre    list has been created
	Post   all of user's choice executed
*/
void process (LIST* list)
{
//	Local Definitions 
	char choice;

//	Statements 
	do
	   {
	    choice = getChoice ();

	    switch (choice)
	       {
	        case 'P': printList (list);
	                  break;
	        case 'S': search (list);
	        case 'Q': break;
	       } // switch 
	   } while (choice != 'Q');
	return;
}	// process 

//============20============
//============21============
/*	================== getChoice ==================
	Prints the menu of choices.
	   Pre    nothing
	   Post   menu printed and choice returned
*/
char getChoice (void)
{
//	Local Definitions 
	char choice;
	bool valid;
	
//	Statements 
	printf("======== MENU ======= \n"
	       "Here are your choices:\n"
	       "  S: Search for a year\n"
	       "  P: Print all years  \n"
	       "  Q: Quit             \n\n"
	       "Enter your choice: ");
	do
	   {
	    scanf(" %c", &choice);
	    choice = toupper(choice);
	    switch (choice)
	       {
	        case 'S':
	        case 'P':
	        case 'Q': valid = true;
	                  break;
	        default:  valid = false;
	                  printf("\aInvalid choice\n"
	                         "Please try again: ");
	                  break;
	       } // switch 
	   } while (!valid);
	return choice;
}	// getChoice 

//============21============
//============22============
/*	================== printList ==================
	Prints the entire list
	   Pre    list has been created
	   Post   list printed
*/
void printList (LIST* list)
{
//	Local Definitions 
	PICTURE* pPic;
	
//	Statements 
	
	// Get first node 
	if (listCount (list) == 0)
	   printf("Sorry, nothing in list\n\a");
	else
	   {
	    printf("\nBest Pictures List\n");
	    traverse (list, 0, (void**)&pPic);
	    do
	      {
	       printf("%hd %-40s %s\n",
	              pPic->year,      pPic->picture, 
	              pPic->director);
	      } while (traverse (list, 1, (void**)&pPic));
	   } // else 
	printf("End of Best Pictures List\n\n");
}	// printList 

//============22============
//============23============
/*	==================== search ====================
	Searches for year and prints year, picture, and
	director.
	   Pre    list has been created
	          user has selected search option
	   Post   year printed or error message
*/
void search (LIST* list)
{
//	Local Definitions 
	short    year;
	bool     found;
	
	PICTURE  pSrchArgu;
	PICTURE* pPic;
	
//	Statements 
	printf("Enter a four digit year: ");
	scanf ("%hd", &year);
	pSrchArgu.year = year;
	
	found = searchList (list, &pSrchArgu, 
	                    (void**)&pPic);
	
	if (found)
	    printf("%hd %-40s %s\n",
	            pPic->year, pPic->picture, pPic->director);
	else
	    printf("Sorry, but %d is not available.\n", year);
	return;
}	// search 

//============23============
//============24============
/*	==================== cmpYear ====================
	Compares two years in PICTURE structures
	   Pre  year1 is a pointer to the first structure
	        year2 is a pointer to the second structure
	   Post two years compared and result returned
	Return -1 if year1 less; 0 if equal; +1 greater
*/

int cmpYear (void* pYear1, void* pYear2)
{
//	Local Definitions 
	int   result;
	short year1;
	short year2;

//	Statements 
	year1 = ((PICTURE*)pYear1)->year;
	year2 = ((PICTURE*)pYear2)->year;

	if (year1 < year2)
	    result = -1;
	else if (year1 > year2)
	    result = +1;
	else
	    result = 0;
	return result;
}	// cmpYear 

//============24============