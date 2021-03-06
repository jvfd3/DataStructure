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
