
/*  =================== BST_Count ==================
  Returns number of nodes in tree.
     Pre     tree has been created 
     Returns tree count 
*/
int BST_Count (BST_TREE* tree)
{
//  Statements 
  return (tree->count);
}  // BST_Count 



/*  ================= BST_Create ================
  Allocates dynamic memory for an BST tree head
  node and returns its address to caller
     Pre    compare is address of compare function 
            used when two nodes need to be compared 
     Post   head allocated or error returned 
     Return head node pointer; null if overflow 
*/
BST_TREE* BST_Create   (int  (*compare) (void* argu1, void* argu2))
{
//  Local Definitions 
  BST_TREE* tree;

//  Statements 
  tree = (BST_TREE*) malloc (sizeof (BST_TREE));
  if (tree)
     {
      tree->root    = NULL;
      tree->count   = 0;
      tree->compare = compare;
     } // if 

  return tree;
}  // BST_Create 



/*  =================== BST_Empty ==================
  Returns true if tree is empty; false if any data.
     Pre      Tree has been created. (May be null) 
     Returns  True if tree empty, false if any data 
*/
bool BST_Empty (BST_TREE* tree)
{
//  Statements 
  return (tree->count == 0);
}  // BST_Empty 



/*  ===================== BST_Full ==================== 
  If there is no room for another node, returns true.
     Pre      tree has been created 
     Returns  true if no room for another insert
              false if room
*/
bool BST_Full (BST_TREE* tree)
{
//  Local Definitions 
  NODE* newPtr;
  
//  Statements 
  newPtr = (NODE*)malloc(sizeof (*(tree->root)));
  if (newPtr)
     {
      free (newPtr);
      return false;
     } // if 
  else
       return true;
}  // BST_Full 
