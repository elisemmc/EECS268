// *********************************************************
// Header file BST.h for the ADT binary search tree.
// Assumption: A tree contains at most one item with a given
//             search key at any time.
// *********************************************************
#ifndef BST_H
#define BST_H

#include "TreeException.h"
#include "TreeNode.h"
#include <sstream> //for stringstream
using namespace std;

//typedef for the visit function signature
typedef void (*FunctionType)(TreeItemType& anItem);

class BST
{
public:


// constructors and destructor:
   BST();
   BST(const BST& tree);
   ~BST();

   // overloaded operators:
   BST& operator=(const BST& rhs);
   bool operator==(const BST& rhs);

// binary search tree operations:
// Precondition for all methods: No two items in a binary 
// search tree have the same search key.

   bool isEmpty() const;
   // Determines whether a binary search tree is empty.
   // Postcondition: Returns true if the tree is empty; 
   // otherwise returns false.

   void searchTreeInsert(const TreeItemType& newItem);
   // Inserts an item into a binary search tree.
   // Precondition: The item to be inserted into the tree 
   // is newItem.
   // Postcondition: newItem is in its proper order in the 
   // tree.

   void searchTreeDelete(KeyType searchKey)
                                    throw(TreeException);
   // Deletes an item with a given search key from a binary
   // search tree.
   // Precondition: searchKey is the search key of the item 
   // to be deleted.
   // Postcondition: If the item whose search key equals
   // searchKey existed in the tree, the item is deleted. 
   // Otherwise, the tree is unchanged and TreeException 
   // is thrown.

   void searchTreeRetrieve(KeyType searchKey, 
                               TreeItemType& treeItem) const
                               throw(TreeException);
   // Retrieves an item with a given search key from a 
   // binary search tree.
   // Precondition: searchKey is the search key of the item 
   // to be retrieved.
   // Postcondition: If the retrieval was successful,
   // treeItem contains the retrieved item.
   // If no such item exists, throws TreeException.

   void preorderTraverse(FunctionType visit);
   // Traverses a binary search tree in preorder, 
   // calling function visit() once for each item.
   // Precondition: The function represented by visit() 
   // exists outside of the class implementation.
   // Postcondition: visit's action occurred once for each
   // item in the tree.
   // Note: visit() can alter the tree.

   void inorderTraverse(FunctionType visit);
   // Traverses a binary search tree in sorted order, 
   // calling function visit() once for each item.

   void postorderTraverse(FunctionType visit);
   // Traverses a binary search tree in postorder, 
   // calling function visit() once for each item.


// ***************************************************************
// Below are the new public methods you must implement
// to solve the project 5 requirements.  You must implement the
// public methods using the exact same signature.
// ***************************************************************

   void minimizeHeight();
   // Postcondition: The tree is rebalanced to provide minimum height.

   void deleteMax(TreeItemType&) throw(TreeException);
   // Postcondition: If the tree is not empty the maximum element is
   //                returned and removed from the tree. Otherwise, a
   //                TreeException is thrown and the tree is unchanged. 

   void deleteMin(TreeItemType&) throw(TreeException);
   // Postcondition: If the tree is not empty the minimum element is
   //                returned and removed from the tree. Otherwise, a
   //                TreeException is thrown and the tree is unchanged. 

   int height() const;
   // Postcondition: Returns the height of the tree. Height of an empty
   //                tree is -1.  The height of a tree with one node is zero.

   int size() const;
   // Postcondition: Returns the number of items in the tree. 

   void sort(TreeItemType a[]) const;
   // Precondition: The input array has size() capacity.
   // Postcondition: The bst is stored in the array in ascending order.

   bool checkFull() const;
   //Precondition: Returns true if the tree is full
   //   		   Returns false if the tree isn't full

private:

   bool Full(TreeNode* treePtr) const;

   bool same(TreeNode* r, TreeNode* t);

   void insertItem(TreeNode *& treePtr, 
                   const TreeItemType& newItem)
                   throw(TreeException);
   // Recursively inserts an item into a binary search tree. 
   // Precondition: treePtr points to a binary search tree, 
   // newItem is the item to be inserted.
   // Postcondition: Same as searchTreeInsert.

   void deleteItem(TreeNode *& treePtr, KeyType searchKey)
                                    throw(TreeException);
   // Recursively deletes an item from a binary search tree. 
   // Precondition: treePtr points to a binary search tree, 
   // searchKey is the search key of the item to be deleted.
   // Postcondition: Same as searchTreeDelete.

   void deleteNodeItem(TreeNode *& nodePtr);
   // Deletes the item in the root of a given tree.
   // Precondition: nodePtr points to the root of a
   // binary search tree; nodePtr != NULL.
   // Postcondition: The item in the root of the given
   // tree is deleted.

   void processLeftmost(TreeNode *& nodePtr, 
                        TreeItemType& treeItem);
   // Retrieves and deletes the leftmost descendant of a
   // given node.
   // Precondition: nodePtr points to a node in a binary
   // search tree; nodePtr != NULL.
   // Postcondition: treeItem contains the item in the
   // leftmost descendant of the node to which nodePtr
   // points. The leftmost descendant of nodePtr is
   // deleted.

   void retrieveItem(TreeNode *treePtr, KeyType searchKey,
                     TreeItemType& treeItem) const
                     throw(TreeException);
   // Recursively retrieves an item from a binary search 
   // tree. 
   // Precondition: treePtr points to a binary search tree, 
   // searchKey is the search key of the item to be 
   // retrieved.
   // Postcondition: Same as searchTreeRetrieve.

   void copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const;
   // Copies the tree rooted at treePtr into a tree rooted 
   // at newTreePtr. Throws TreeException if a copy of the 
   // tree cannot be allocated.

   void destroyTree(TreeNode *& treePtr);
   // Deallocates memory for a tree.
   // The next two functions retrieve and set the value 
   // of the private data member root.

   void preorder(TreeNode *treePtr, FunctionType visit);
   void inorder(TreeNode *treePtr, FunctionType visit);
   void postorder(TreeNode *treePtr, FunctionType visit);

   TreeNode *rootPtr() const;
   void setRootPtr(TreeNode *newRoot);


   // The next two functions retrieve and set the values 
   // of the left and right child pointers of a tree node.
   void getChildPtrs(TreeNode *nodePtr, 
                     TreeNode *& leftChildPtr,
                     TreeNode *& rightChildPtr) const;
   void setChildPtrs(TreeNode *nodePtr, 
                     TreeNode *leftChildPtr,
                     TreeNode *rightChildPtr);

   TreeNode *root;  // pointer to root of tree

   friend class BSTTester;

// ***************************************************************
// Below are new private methods that I used
// to solve the project 5 requirements.
// You do not have to use the exact same private, helper method
// signatures.  In fact, you can write your own if you choose.
// ***************************************************************

   int size(TreeNode* t) const;
   // returns the number of nodes in t

   int nodesOnMaxPathToLeaf(TreeNode* t) const;
   // returns the number of nodes on the path
   // from t to the furthest leaf

   int sortHelper(TreeItemType a[], int& i, TreeNode* t) const;
   // traverses t and stores the data in array a in
   // ascending order starting at index i, returns the
   // the last index of the sorted data

   void buildHelper(TreeItemType a[],int first, int last);
   // Builds a minimum-height bst from n sorted values in a.
   
};  // end class

#endif
