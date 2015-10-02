#include <cstddef>  // definition of NULL
#include <new>      // for bad_alloc
#include <string>
#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"      // header file
using namespace std;


/* Default Constructor */
BinaryTree::BinaryTree() : root(NULL)
{

}  // end default constructor

/*-----------------------------------------------------------------------------
TODO:BinaryTree Constructor
-----------------------------------------------------------------------------*/
BinaryTree::BinaryTree(string inorder, string preorder)
{
	//TODO: Implement Me!
}

/*-----------------------------------------------------------------------------
TODO:BinaryTree reconstruct
This is the recursive function you can use to build the tree, call it from the
constructor above.
-----------------------------------------------------------------------------*/
void BinaryTree::reconstruct(TreeNode *treePtr, string inorder, string preorder)
{
		//TODO: Implement Me!
}

/*-----------------------------------------------------------------------------
TODO:Prints the tree using PreOrder Traversal
-----------------------------------------------------------------------------*/
void BinaryTree::printPreorderRoutine()
{
		//TODO: Implement Me!
}

/*-----------------------------------------------------------------------------
TODO:Prints the tree using InOrder Traversal
-----------------------------------------------------------------------------*/
void BinaryTree::printInorderRoutine()
{
		//TODO: Implement Me!
}

/*-----------------------------------------------------------------------------
TODO:Prints the tree using PostOrder Traversal
-----------------------------------------------------------------------------*/
void BinaryTree::printPostorderRoutine()
{
		//TODO: Implement Me!
}

/*Indicates if the tree is empty or not */
bool BinaryTree::isEmpty() const
{
   return (root == NULL);
}  // end isEmpty

/*Used to set the data at the root of the tree */
void BinaryTree::setRootData(const TreeItemType& newItem)
{
   	if (!isEmpty())
		root->item = newItem;
	else
	{
		root = new TreeNode();
	}
}  // end setRootData







