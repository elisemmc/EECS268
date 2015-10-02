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
	root = new TreeNode();
	reconstruct(root, inorder, preorder);
}

/*-----------------------------------------------------------------------------
TODO:BinaryTree reconstruct
This is the recursive function you can use to build the tree, call it from the
constructor above.
-----------------------------------------------------------------------------*/
void BinaryTree::reconstruct(TreeNode* treePtr, string inorder, string preorder)
{
string lin, lpre, rin, rpre;
treePtr->item = preorder[0];
char compare = preorder[0];
if(inorder.length()>1){
  bool hit = false;
  char iter;
  for(int i=0; i<inorder.length(); i++){
    iter = inorder[i];
    if(iter == compare){
      hit = true;
    }
    else if(hit == true){
      rin = rin + inorder[i];
    }
    if(hit == false){
      lin = lin + inorder[i];
    }
  }
  for(int j=1; j<(inorder.length()); j++){
    if(j<=lin.length())
      lpre += preorder[j];
    else
      rpre += preorder[j];
  }

  treePtr->leftChildPtr = new TreeNode();
  reconstruct(treePtr->leftChildPtr, lin, lpre);
  treePtr->rightChildPtr = new TreeNode();
  reconstruct(treePtr->rightChildPtr, rin, rpre);
}
}

/*-----------------------------------------------------------------------------
TODO:Prints the tree using PreOrder Traversal
-----------------------------------------------------------------------------*/
void BinaryTree::printPreorderRoutine()
{
  //TODO: Implement Me!
  printpre(root);
}

void BinaryTree::printpre(TreeNode* node){
  cout<< node->item;
  if(node->leftChildPtr!=NULL)
    printpre(node->leftChildPtr);
  if(node->rightChildPtr!=NULL)
    printpre(node->rightChildPtr);
}

/*-----------------------------------------------------------------------------
TODO:Prints the tree using InOrder Traversal
-----------------------------------------------------------------------------*/
void BinaryTree::printInorderRoutine()
{
		//TODO: Implement Me!
  printin(root);
}

void BinaryTree::printin(TreeNode* node){
  if(node->leftChildPtr!=NULL)
    printin(node->leftChildPtr);
  cout<< node->item;
  if(node->rightChildPtr!=NULL)
    printin(node->rightChildPtr);
}

/*-----------------------------------------------------------------------------
TODO:Prints the tree using PostOrder Traversal
-----------------------------------------------------------------------------*/
void BinaryTree::printPostorderRoutine()
{
		//TODO: Implement Me!
  printpost(root);
}

void BinaryTree::printpost(TreeNode* node){
  if(node->leftChildPtr!=NULL)
    printpost(node->leftChildPtr);
  if(node->rightChildPtr!=NULL)
    printpost(node->rightChildPtr);
  cout<< node->item;
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







