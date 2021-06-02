/*	This program maintains and displays a list of
	Academy Awards Motion Pictures.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <cType.h>
#include <stdbool.h>
#include "linkListADT.h"


//	Prototype Declarations 
	void  printInstr (void);
	LIST* buildList  (void);
	void  process    (LIST* list);
	char  getChoice  (void);
	void  printList  (LIST* list);
	void  search     (LIST* list);

	int   cmpYear    (void* pYear1, void* pYear2);

//	Application Functions
	#include "pictures.h"		//junction
	#include "P5-16.h"          // Data Structure
	#include "P5-18.h"          // Academy Awards Functions
	#include "P5-19.h" 
	#include "P5-20.h" 
	#include "P5-21.h" 
	#include "P5-22.h" 
	#include "P5-23.h" 
	#include "P5-24.h" 

int main (void)
{
//	Local Definitions 
	LIST* list;

//	Statements 
	printInstr ();
	list = buildList ();
	process (list);

	printf("End Best Pictures\n"
	       "Hope you found your favorite!\n");
	return 0;
}	// main 


/* Results:
This program will print the Academy Awards 
Best Picture of the Year and its director. 
Your job is to enter the year;  we will do 
the rest. Enjoy.
Duplicate year 1942 not added
======== MENU ======= 
Here are your choices:
  S: Search for a year
  P: Print all years  
  Q: Quit             

Enter your choice: p

Best Pictures List
1932 Cavalcade                                Frank Lloyd
1934 It Happened One Night                    Frank Capra
1938 You Can't Take It With You               Frank Capra
1939 Gone With the Wind                       Victor Fleming
1941 How Green Was My Valley                  John Ford
1942 Mrs. Miniver                             William Wyler
1943 Casablanca                               Michael Curtiz
1945 The Lost Weekend                         William Wyler
1946 The Best Years of Our Lives              William Wyler
1947 Gentleman's Agreement                    Elia Kazan
1950 All About Eve                            Joseph L. Mankiewicz
1953 From Here To Eternity                    Fred Zinnemann
End of Best Pictures List

======== MENU ======= 
Here are your choices:
  S: Search for a year
  P: Print all years  
  Q: Quit             

Enter your choice: s
Enter a four digit year: 1946
1946 The Best Years of Our Lives              William Wyler
======== MENU ======= 
Here are your choices:
  S: Search for a year
  P: Print all years  
  Q: Quit             

Enter your choice: q
End Best Pictures
Hope you found your favorite!
*/
