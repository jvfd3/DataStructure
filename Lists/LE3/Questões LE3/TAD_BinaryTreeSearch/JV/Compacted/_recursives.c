/*  ==================== _delete ==================== 
  Deletes node from the tree and rebalances 
  tree if necessary. 
     Pre    tree initialized--null tree is OK.
            dataPtr contains key of node to be deleted
     Post   node is deleted and its space recycled
            -or- if key not found, tree is unchanged 
     Return success is true if deleted; false if not found
            pointer to root
*/
NODE*  _delete (BST_TREE* tree,    NODE* root,    void*     dataPtr, bool* success)
{
// Local Definitions 
  NODE* dltPtr;
  NODE* exchPtr;
  NODE* newRoot;
  void* holdPtr;

//  Statements 
  if (!root)
     {
      *success = false;
      return NULL;
     } // if 
  
  if (tree->compare(dataPtr, root->dataPtr) < 0)
       root->left  = _delete (tree,    root->left, 
                              dataPtr, success);
  else if (tree->compare(dataPtr, root->dataPtr) > 0)
       root->right = _delete (tree,    root->right, 
                              dataPtr, success);
  else
      // Delete node found--test for leaf node 
      {
       dltPtr = root;
       if (!root->left)
           // No left subtree 
           {
            free (root->dataPtr);       // data memory
            newRoot = root->right;
            free (dltPtr);              // BST Node
            *success = true;
            return newRoot;             // base case 
           } // if true 
       else
           if (!root->right)
               // Only left subtree 
               {
                newRoot = root->left;
                free (dltPtr);
                *success = true;
                return newRoot;         // base case 
              } // if 
           else
               // Delete Node has two subtrees 
               {
                exchPtr = root->left;
                // Find largest node on left subtree
                while (exchPtr->right)
                    exchPtr = exchPtr->right;

                // Exchange Data 
                holdPtr          = root->dataPtr;
                root->dataPtr    = exchPtr->dataPtr;
                exchPtr->dataPtr = holdPtr;
                root->left       = 
                   _delete (tree,   root->left, 
                            exchPtr->dataPtr, success);
               } // else 
      } // node found 
  return root; 
}  // _delete 



/*  =============== _destroy ============== 
  Deletes all data in tree and recycles memory.
  It also recycles memory for the key and data nodes.
  The nodes are deleted by calling a recursive 
  function to traverse the tree in inorder sequence.
     Pre      root is pointer to valid tree/subtree 
     Post     All data and head structure deleted 
     Return   null head pointer 
*/
void _destroy (NODE* root)
{
//  Statements 
  if (root)
     {
      _destroy (root->left);
      free (root->dataPtr);
      _destroy (root->right);
      free (root);
     } // if 
  return;
}  // _destroy



/*  ==================== _insert ====================
  This function uses recursion to insert the new data 
  into a leaf node in the BST tree.
     Pre    Application has called BST_Insert, which  
            passes root and data pointer
     Post   Data have been inserted
     Return pointer to [potentially] new root
*/
NODE* _insert (BST_TREE* tree, NODE* root, NODE* newPtr) {
//  Statements 
  if (!root) {// if NULL tree 
    return newPtr;
  }

  if (tree->compare(newPtr->dataPtr,  root->dataPtr) < 0) {// Locate null subtree for insertion 
    root->left = _insert(tree, root->left, newPtr);
    return root; 
  } // new < node 
  else  {// new data >= root data 
    root->right = _insert(tree, root->right, newPtr);
    return root;
  } // else new data >= root data 
  return root;

  //Could I just remove both return root from the if else?
}  // _insert 



/*  ===================== _retrieve ===================== 
  Searches tree for node containing requested key 
  and returns its data to the calling function.
     Pre     _retrieve passes tree, dataPtr, root 
             dataPtr is pointer to data structure 
                containing key to be located 
     Post    tree searched; data pointer returned 
     Return  Address of data in matching node 
             If not found, NULL returned 
*/
void* _retrieve (BST_TREE* tree,    void* dataPtr, NODE* root) {
//  Statements 
  if (root) {
    if (tree->compare(dataPtr, root->dataPtr) < 0)
      return _retrieve(tree, dataPtr, root->left);
    else if (tree->compare(dataPtr, root->dataPtr) > 0)
      return _retrieve(tree, dataPtr, root->right);
    else
      // Found equal key 
      return root->dataPtr;
  }
  // Data not in tree 
  return NULL;
}  // _retrieve 



/*  =================== _traverse =================== 
  Inorder tree traversal. To process a node, we use 
  the function passed when traversal was called.
     Pre   Tree has been created (may be null) 
     Post  All nodes processed 
*/
void _traverse (NODE* root,   void (*process) (void* dataPtr)) {
//  Statements 
  if  (root) {
    _traverse (root->left, process);
    process   (root->dataPtr);
    _traverse (root->right, process);
  } // if 
// return;
}  // _traverse
