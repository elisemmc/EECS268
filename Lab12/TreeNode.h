// *********************************************************
// Header file TreeNode.h for the ADT binary search tree.
// Same as TreeNode556.h and TreeNodeBST.h in Chapter 10
// *********************************************************
#ifndef TREENODE_H
#define TREENODE_H

#include "KeyedItem.h"

typedef KeyedItem TreeItemType;

class TreeNode        // a node in the tree 
{
public:
   TreeNode() { }
   TreeNode(const TreeItemType& nodeItem, 
            TreeNode *left = NULL, TreeNode *right = NULL)
      :item(nodeItem), leftChildPtr(left),
      rightChildPtr(right) { }

   TreeItemType item;            // a data item in the tree
   // pointers to children
   TreeNode *leftChildPtr, *rightChildPtr;

   // friend class - can access private parts
   friend class BST;
   friend class BSTTester;
};  // end class

#endif
