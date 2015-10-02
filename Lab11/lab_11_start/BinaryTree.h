#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//The typedef TreeItemType determines the data type help by the BinaryTree's TreeNodes
typedef char TreeItemType;

//ADT Binary Tree Class */
class BinaryTree
{

public:
	BinaryTree(string inorder, string preorder);//TODO:Implement Me!!!

	BinaryTree();

//binary tree operations
	bool isEmpty() const;

//set the root data
	void setRootData(const TreeItemType& newItem);

//print the tree using preorder
	void printPreorderRoutine();//TODO:Implement Me!!!

///print the tree using inorder
	void printInorderRoutine();//TODO:Implement Me!!!

//print the tree using postorder
	void printPostorderRoutine();//TODO:Implement Me!!!

protected:

//TreeNode is the data type that makes up the nodes of the tree
	struct TreeNode
	{
		TreeItemType	item;
		TreeNode*		leftChildPtr;
		TreeNode*		rightChildPtr;
		TreeNode(): leftChildPtr(NULL), rightChildPtr(NULL) {}
	};

	//This is the recursive function that you should implement to reconstruct the tree
   	void reconstruct(TreeNode *treePtr, string inorder, string preorder);	//TODO:Implement Me!!!

private:

	/*Pointer to the root of the tree*/
	TreeNode *root;
}; //end of BinaryTree class def.

