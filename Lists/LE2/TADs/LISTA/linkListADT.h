/*	This header file contains the functions to maintain
	and process a linked list.
	   Written by:
	   Date:
*/

//=====================11========================/* Singly-Linked List ADT Type Definitions */
//	List ADT Type Defintions 
	typedef struct node 
	   {
	    void*        dataPtr;
	    struct node* link;
	   } NODE; 

	typedef struct
	   {
	    int   count; 
	    NODE* pos;
	    NODE* head; 
	    NODE* rear;
	    int    (*compare) (void* argu1, void* argu2); 
	   } LIST;
//=====================11========================/* Singly-Linked List ADT Type Definitions */
//=====================22========================/* List ADT Prototype Declarations */
//	Prototype Declarations 
	LIST* createList   (int (*compare)(void* argu1, void* argu2));
	LIST* destroyList  (LIST* list);

	int   addNode   (LIST* pList, void* dataInPtr);
	bool  removeNode   (LIST*  pList, 	                    void*  keyPtr,	                    void** dataOutPtr);
	bool  searchList   (LIST*  pList,	                    void*  pArgu,	                    void** pDataOut);
	bool  retrieveNode (LIST*  pList,	                    void*  pArgu,	                    void** dataOutPtr);
	bool  traverse     (LIST*  pList,	                    int    fromWhere,	                    void** dataOutPtr);
	int   listCount    (LIST*  pList);
	bool  emptyList    (LIST*  pList);
	bool  fullList     (LIST*  pList); 
	static int _insert   (LIST* pList,	                      NODE* pPre,	                      void* dataInPtr);
	static void _delete  (LIST*  pList,	                      NODE*  pPre,	 NODE*  pLoc,	void** dataOutPtr);
	static bool _search  (LIST*  pList,	                      NODE** pPre,NODE** pLoc,void*  pArgu);
//	End of List ADT Definitions 
//=====================22========================/* List ADT Prototype Declarations */
//=====================33========================/* Create linked list */
/*	=============== createList ==============
	Allocates dynamic memory for a list head
	node and returns its address to caller
	   Pre    compare is address of compare function 
	          used to compare two nodes.
	   Post   head has allocated or error returned
	   Return head node pointer or null if overflow 
*/
LIST* createList 
     (int (*compare) (void* argu1, void* argu2))
{
//	Local Definitions 
	LIST* list;

//	Statements 
	list = (LIST*) malloc (sizeof (LIST));
	if (list)
	   {
	    list->head    = NULL;
	    list->pos     = NULL;
	    list->rear    = NULL;
	    list->count   = 0;
	    list->compare = compare;
	   } // if 

	return list;
}	// createList 
//=====================33========================/* Create linked list */
//=====================44========================/* Add Node */
/*	================== addNode =================
	Inserts data into list.
	   Pre    pList is pointer to valid list
	          dataInPtr pointer to insertion data
	   Post   data inserted or error
	   Return -1 if overflow
	           0 if successful
	           1 if dupe key
*/
int addNode (LIST* pList, void* dataInPtr)
{
//	Local Definitions 
	bool found;
	bool success;
	
	NODE* pPre;
	NODE* pLoc;
	
//	Statements 
	found = _search (pList, &pPre, &pLoc, dataInPtr);
	if (found)
	   // Duplicate keys not allowed 
	   return (+1);

	success = _insert (pList, pPre, dataInPtr);
	if (!success)
	   // Overflow 
	   return (-1);
	return (0);
}	// addNode 
//=====================44========================/* Add Node */
//=====================55========================/* Insert Node */
/*	=================== _insert ================== 
	Inserts data pointer into a new node.
	   Pre    pList pointer to a valid list 
	          pPre  pointer to data's predecessor 
	          dataInPtr data pointer to be inserted 
	   Post   data have been inserted in sequence 
	   Return boolean, true  if successful, 
	                   false if memory overflow 
*/
bool _insert (LIST* pList, NODE* pPre,
                     void* dataInPtr)
{
//	Local Definitions 
	NODE* pNew;

//	Statements 
	if (!(pNew = (NODE*) malloc(sizeof(NODE))))
	   return false;

	pNew->dataPtr   = dataInPtr; 
	pNew->link      = NULL; 
 
	if (pPre == NULL)
	   {
	    // Adding before first node or to empty list. 
	    pNew->link       = pList->head;
	    pList->head      = pNew;
	    if (pList->count == 0)
	       // Adding to empty list. Set rear 
	       pList->rear = pNew;
	   } // if pPre 
	else
	   {
	    // Adding in middle or at end 
	    pNew->link  = pPre->link;
	    pPre->link  = pNew;
 
	    // Now check for add at end of list 
	    if (pNew->link     == NULL)
	         pList->rear   =  pNew;
	   } // if else 

	(pList->count)++;
	return true;
}	// _insert 
//=====================55========================/* Insert Node */
//=====================66========================/* Remove Node */
/*	================= removeNode ================ 
	Removes data from list. 
	   Pre    pList pointer to a valid list
	          keyPtr pointer to key to be deleted
	          dataOutPtr pointer to data pointer
	   Post   Node deleted or error returned.
	   Return false not found; true deleted
*/
bool removeNode  (LIST*  pList, void*  keyPtr,
                  void** dataOutPtr)
{
//	Local Definitions 
	bool found;
	
	NODE* pPre;
	NODE* pLoc;
	
//	Statements 
	found = _search (pList, &pPre, &pLoc, keyPtr);
	if (found)
	   _delete (pList, pPre, pLoc, dataOutPtr);
	
	return found;
}	// removeNode 
//=====================66========================/* Remove Node */
//=====================77========================/* Delete Node */
/*	================= _delete ================ 
	Deletes data from a list and returns 
	pointer to data to calling module.
	   Pre    pList pointer to valid list.
	          pPre  pointer to predecessor node
	          pLoc  pointer to target node
	          dataOutPtr pointer to data pointer
	   Post   Data have been deleted and returned 
	          Data memory has been freed
*/
void _delete (LIST* pList, NODE*  pPre,
              NODE* pLoc,  void** dataOutPtr)
{
//	Statements 
	*dataOutPtr = pLoc->dataPtr;
	if (pPre == NULL)
	   // Deleting first node 
	   pList->head = pLoc->link;
	else
	   // Deleting any other node 
	   pPre->link = pLoc->link;
	 
	// Test for deleting last node 
	if (pLoc->link == NULL)
	    pList->rear = pPre;

	(pList->count)--;
	free (pLoc);

	return;
}	// _delete 
//=====================77========================/* Delete Node */
//=====================88========================/* Search Interface */
/*	================== searchList ================= 
	Interface to search function. 
	   Pre    pList pointer to initialized list.
	          pArgu pointer to key being sought
	   Post   pDataOut contains pointer to found data
	     -or- NULL if not found
	   Return boolean true successful; false not found 
*/
bool searchList (LIST*  pList, void* pArgu,
                 void** pDataOut)
{
//	Local Definitions 
	bool  found;
	
	NODE* pPre;
	NODE* pLoc;

//	Statements 
	found = _search (pList, &pPre, &pLoc, pArgu);
	if (found)
	    *pDataOut = pLoc->dataPtr;
	else
	    *pDataOut = NULL;
	return found;
}	// searchList 
//=====================88========================/* Search Interface */
//=====================99========================/* Search List */
/*	================== _search =================
	Searches list and passes back address of node 
	containing target and its logical predecessor.
	   Pre    pList pointer to initialized list 
	          pPre  pointer variable to predecessor
	          pLoc  pointer variable to receive node
	          pArgu pointer to key being sought
	   Post   pLoc points to first equal/greater key 
	     -or- null if target > key of last node
	          pPre points to largest node < key
	     -or- null if target < key of first node
	   Return boolean true found; false not found 

*/
bool _search (LIST*  pList, NODE** pPre,
              NODE** pLoc,  void*  pArgu)
{
//	Macro Definition 
#define COMPARE \
	( ((* pList->compare) (pArgu, (*pLoc)->dataPtr)) )

#define COMPARE_LAST \
	((* pList->compare) (pArgu, pList->rear->dataPtr))

//	Local Definitions 
	int result;
	
//	Statements 
	*pPre  = NULL;
	*pLoc  = pList->head;
	if (pList->count == 0)
	    return false;
	
	// Test for argument > last node in list 
	if ( COMPARE_LAST > 0) 
	   {
	    *pPre = pList->rear;
	    *pLoc = NULL;
	    return false;
	   } // if 

	while ( (result = COMPARE) > 0 )
	   {
	    // Have not found search argument location 
	    *pPre = *pLoc;
	    *pLoc = (*pLoc)->link;
	   } // while 
	
	if (result == 0)
	   // argument found--success 
	   return true;
	else
	   return false;
}	// _search 
//=====================99========================/* Search List */
//=====================10========================/* Retrieve Node */
/*	================== retrieveNode ================ 
	This algorithm retrieves data in the list without
	changing the list contents. 
	   Pre    pList pointer to initialized list.
	          pArgu pointer to key to be retrieved
	   Post   Data (pointer) passed back to caller
	   Return boolean true success; false underflow
*/
static bool retrieveNode (LIST*  pList,
                          void*  pArgu, 
                          void** dataOutPtr)
{
//	Local Definitions 
	bool  found;
	
	NODE* pPre;
	NODE* pLoc;
	
//	Statements 
	found = _search (pList, &pPre, &pLoc, pArgu);
	if (found)
	   {
	    *dataOutPtr = pLoc->dataPtr;
	    return true;
	   } // if 

	*dataOutPtr = NULL;
	return false;
}	// retrieveNode 
//=====================10========================/* Retrieve Node */
//=====================11========================/* Empty List */
/*	================= emptyList ================
	Returns boolean indicating whether or not the
	list is empty
	   Pre    pList is a pointer to a valid list 
	   Return boolean true empty; false list has data 
*/
bool emptyList (LIST* pList) 
{
//	Statements 
	return (pList->count == 0);
}	// emptyList 
//=====================11========================/* Empty List */
//=====================12========================/* Full List */
/*	================== fullList =================
	Returns boolean indicating no room for more data.
	This list is full if memory cannot be allocated for
	another node. 
	   Pre    pList pointer to valid list 
	   Return boolean true if full
	                  false if room for node 
*/
bool fullList (LIST* pList) 
{
//	Local Definitions 
NODE* temp;

//	Statements 
	if ((temp = (NODE*)malloc(sizeof(*(pList->head)))))
	   {
	    free (temp);
	    return false;
	   } // if 

	// Dynamic memory full 
	return true;

}	// fullList 
//=====================12========================/* Full List */
//=====================13========================/* List Count */
/*	================== listCount ==================
	Returns number of nodes in list.
	   Pre    pList is a pointer to a valid list
	   Return count for number of nodes in list
*/
int listCount(LIST* pList) 
{
//	Statements 

	return pList->count; 
	
}	// listCount 
//=====================13========================/* List Count */
//=====================14========================/* Traverse List */
/*	================== traverse =================
	Traverses a list. Each call either starts at the
	beginning of list or returns the location of the 
	next element in the list.
	   Pre    pList       pointer to a valid list
	          fromWhere   0 to start at first element
	          dataPtrOut  address of pointer to data
	   Post   if more data, address of next node 
	   Return true node located; false if end of list
*/
bool traverse (LIST*  pList,
              int    fromWhere,
              void** dataPtrOut)
{
//	Statements 
	if (pList->count == 0)
	    return false;

	if (fromWhere == 0)
	   {
		 //Start from first node 
	    pList->pos  = pList->head;
	    *dataPtrOut = pList->pos->dataPtr;
	    return true;
	   } // if fromwhere 
	else
	   {
	    // Start from current position 
	    if (pList->pos->link == NULL)
	        return false;
	    else
	       {
	        pList->pos  = pList->pos->link;
	        *dataPtrOut = pList->pos->dataPtr;
	        return true;
	       } // if else 
	   } // if fromwhere else 
}	// traverse 
//=====================14========================/* Traverse List */
//=====================15========================/* Destroy List */
/*	================== destroyList =================
	Deletes all data in list and recycles memory
	   Pre    List is a pointer to a valid list.
	   Post   All data and head structure deleted
	   Return null head pointer
*/
LIST* destroyList (LIST* pList) 
{
//	Local Definitions 
	NODE* deletePtr;

//	Statements 
	if (pList)
	   {
	    while (pList->count > 0) 
	       {
	        // First delete data 
	        free (pList->head->dataPtr);
 
	        // Now delete node 
	        deletePtr    = pList->head;
	        pList->head  = pList->head->link; 
	        pList->count--;
	        free (deletePtr); 
	       } // while 
	    free (pList);
	   } // if 
	return NULL;
}	// destroyList 
//=====================15========================/* Destroy List */


