/*	=============== _destroy ============== 
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
//	Statements 
	if (root)
	   {
	    _destroy (root->left);
	    free (root->dataPtr);
	    _destroy (root->right);
	    free (root);
	   } // if 
	return;
}	// _destroy
