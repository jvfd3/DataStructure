
/* ================== BST_Delete ================== 
  This function deletes a node from the tree and 
  rebalances it if necessary. 
     Pre    tree initialized--null tree is OK
            dltKey is pointer to data structure 
                   containing key to be deleted 
     Post   node deleted and its space recycled 
            -or- An error code is returned 
     Return Success (true) or Not found (false)
*/
bool BST_Delete (BST_TREE* tree, void* dltKey) {
//  Local Definitions 
  bool  success;
  NODE* newRoot;
  
//  Statements 
  newRoot = _delete (tree, tree->root, dltKey, &success);
  if (success) {
    tree->root = newRoot;
    (tree->count)--;
    if (tree->count == 0) {// Tree now empty 
      tree->root = NULL;
    }
  } // if 
  return success;
}  // BST_Delete



/*  =============== BST_Destroy ============== 
  Deletes all data in tree and recycles memory.
  The nodes are deleted by calling a recursive
  function to traverse the tree in inorder sequence.
     Pre      tree is a pointer to a valid tree 
     Post     All data and head structure deleted 
     Return   null head pointer
*/
BST_TREE* BST_Destroy (BST_TREE* tree) 
{
//  Statements 
  if (tree)
    _destroy (tree->root);
    
  // All nodes deleted. Free structure 
  free (tree);
  return NULL;
}  // BST_Destroy 




/*  ================= BST_Insert ===================
  This function inserts new data into the tree.
     Pre    tree is pointer to BST tree structure
     Post   data inserted or memory overflow 
     Return Success (true) or Overflow (false)
*/
bool BST_Insert (BST_TREE* tree, void* dataPtr) {
//  Local Definitions 
  NODE* newPtr;

//  Statements 
  newPtr = (NODE*)malloc(sizeof(NODE));
  if (!newPtr)
     return false;

  newPtr->right   = NULL;
  newPtr->left    = NULL;
  newPtr->dataPtr = dataPtr;
   
  if (tree->count == 0) {
    tree->root  =  newPtr;
  } else {
    _insert(tree, tree->root, newPtr);
  }
      
  (tree->count)++;
  return true;
}  // BST_Insert 



/*  ==================== BST_Retrieve ===================  
  Retrieve node searches tree for the node containing 
  the requested key and returns pointer to its data.
     Pre     Tree has been created (may be null) 
             data is pointer to data structure 
                  containing key to be located 
     Post    Tree searched and data pointer returned 
     Return  Address of matching node returned 
             If not found, NULL returned 
*/
void* BST_Retrieve  (BST_TREE* tree, void* keyPtr) {
//  Statements 
  // return (tree->root)?_retrieve (tree, keyPtr, tree->root):NULL;  //ternary way
  
  if (tree->root) {
    return _retrieve (tree, keyPtr, tree->root);
  }
  return NULL;
  
}  // BST_Retrieve 



/*  =================== BST_Traverse =================== 
  Process tree using inorder traversal. 
     Pre   Tree has been created (may be null) 
           process �visits� nodes during traversal 
     Post  Nodes processed in LNR (inorder) sequence 
*/
void BST_Traverse (BST_TREE* tree,   void (*process) (void* dataPtr)) {
//  Statements 
  _traverse (tree->root, process);
  // return;
}  // end BST_Traverse 
