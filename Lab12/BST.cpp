// *********************************************************
// Implementation file BST.cpp.
// *********************************************************
// *********************************************************
// 
// *********************************************************

#include "BST.h"     // header file
#include <cstddef>   // definition of NULL

BST::BST() : root(NULL)
{
}  // end default constructor

BST::BST(const BST& tree)
{
   copyTree(tree.root, root);
}  // end copy constructor

BST::~BST()
{
   destroyTree(root);
}  // end destructor

BST& BST::operator=(const BST& rhs)
{
   if (this != &rhs)
   {  destroyTree(root);  // deallocate left-hand side
      copyTree(rhs.root, root);  // copy right-hand side
   }  // end if
   return *this;
}  // end operator=

bool BST::isEmpty() const
{
   return (root == NULL);
}  // end searchTreeIsEmpty

void BST::searchTreeInsert(const TreeItemType& newItem)
{
   insertItem(root, newItem);
}  // end searchTreeInsert

void BST::searchTreeDelete(KeyType searchKey)
                                 throw(TreeException)
{
   deleteItem(root, searchKey);
}  // end searchTreeDelete

void BST::searchTreeRetrieve(KeyType searchKey,
                             TreeItemType& treeItem) const                                        
                             throw(TreeException)
{
   // if retrieveItem throws a TreeException, it is 
   // ignored here and passed on to the point in the code 
   // where searchTreeRetrieve was called
   retrieveItem(root, searchKey, treeItem);
}  // end searchTreeRetrieve

void BST::preorderTraverse(FunctionType visit)
{
   preorder(root, visit);
}  // end preorderTraverse

void BST::inorderTraverse(FunctionType visit)
{
   inorder(root, visit);
}  // end inorderTraverse

void BST::postorderTraverse(FunctionType visit)
{
   postorder(root, visit);
}  // end postorderTraverse

void BST::insertItem(TreeNode *& treePtr,
                     const TreeItemType& newItem)
                     throw(TreeException)

{
   if (treePtr == NULL)
   {  // position of insertion found; insert after leaf

      // create a new node
      treePtr = new TreeNode(newItem, NULL, NULL);
   }
   // else search for the insertion position
   else if (newItem.getKey() < treePtr->item.getKey())
      // search the left subtree
      insertItem(treePtr->leftChildPtr, newItem);

   else if(newItem.getKey() > treePtr->item.getKey())
      // search the right subtree
      insertItem(treePtr->rightChildPtr, newItem);
   else
     throw TreeException("Attempted to insert duplicate key.");
}  // end insertItem

void BST::deleteItem(TreeNode *& treePtr,
                                  KeyType searchKey)
                                  throw(TreeException)
// Calls: deleteNodeItem.
{
   if (treePtr == NULL)
      throw TreeException("TreeException: delete failed");  // empty tree

   else if (searchKey == treePtr->item.getKey())
      // item is in the root of some subtree
      deleteNodeItem(treePtr);  // delete the item

   // else search for the item
   else if (searchKey < treePtr->item.getKey())
      // search the left subtree
      deleteItem(treePtr->leftChildPtr, searchKey);

   else  // search the right subtree
      deleteItem(treePtr->rightChildPtr, searchKey);
}  // end deleteItem

void BST::deleteNodeItem(TreeNode *& nodePtr)
// Algorithm note: There are four cases to consider:
//   1. The root is a leaf.
//   2. The root has no left child.
//   3. The root has no right child.
//   4. The root has two children.
// Calls: processLeftmost.
{
   TreeNode     *delPtr;
   TreeItemType replacementItem;

   // test for a leaf
   if ( (nodePtr->leftChildPtr == NULL) &&
        (nodePtr->rightChildPtr == NULL) )
   {  delete nodePtr;
      nodePtr = NULL;
   }  // end if leaf
   // test for no left child
   else if (nodePtr->leftChildPtr == NULL)
   {  delPtr = nodePtr;
      nodePtr = nodePtr->rightChildPtr;
      delPtr->rightChildPtr = NULL;
      delete delPtr;
   }  // end if no left child

   // test for no right child
   else if (nodePtr->rightChildPtr == NULL)
   {  delPtr = nodePtr;
      nodePtr = nodePtr->leftChildPtr;
      delPtr->leftChildPtr = NULL;
      delete delPtr;
   }  // end if no right child

   // there are two children:
   // retrieve and delete the inorder successor
   else
   {  processLeftmost(nodePtr->rightChildPtr, 
                      replacementItem);
      nodePtr->item = replacementItem;
   }  // end if two children
}  // end deleteNodeItem

void BST::processLeftmost(TreeNode *& nodePtr, TreeItemType& treeItem)
{
   if (nodePtr->leftChildPtr == NULL)
   {  treeItem = nodePtr->item;
      TreeNode *delPtr = nodePtr;
      nodePtr = nodePtr->rightChildPtr;
      delPtr->rightChildPtr = NULL;  // defense
      delete delPtr;
   }

   else 
      processLeftmost(nodePtr->leftChildPtr, treeItem);
}  // end processLeftmost

void BST::retrieveItem(TreeNode *treePtr, 
                                    KeyType searchKey,
                                    TreeItemType& treeItem) const
                                    throw(TreeException)
{
   if (treePtr == NULL)
      throw TreeException("TreeException: searchKey not found"); 

   else if (searchKey == treePtr->item.getKey())
      // item is in the root of some subtree
      treeItem = treePtr->item;

   else if (searchKey < treePtr->item.getKey())
   // search the left subtree
      retrieveItem(treePtr->leftChildPtr, 
                   searchKey, treeItem);

   else  // search the right subtree
      retrieveItem(treePtr->rightChildPtr,
                          searchKey, treeItem);
}  // end retrieveItem

void BST::copyTree(TreeNode *treePtr, 
                          TreeNode *& newTreePtr) const
{
   // preorder traversal
   if (treePtr != NULL)
   {  // copy node
      newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
      copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
      copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
   }  
   else
      newTreePtr = NULL;  // copy empty tree
}  // end copyTree

void BST::destroyTree(TreeNode *& treePtr)
{
   // postorder traversal
   if (treePtr != NULL)
   {  destroyTree(treePtr->leftChildPtr);
      destroyTree(treePtr->rightChildPtr);
      delete treePtr;
      treePtr = NULL;
   }  // end if
}  // end destroyTree

void BST::preorder(TreeNode *treePtr, 
                          FunctionType visit)
{
   if (treePtr != NULL)
   {  visit(treePtr->item);
      preorder(treePtr->leftChildPtr, visit);
      preorder(treePtr->rightChildPtr, visit);
   } // end if
}  // end preorder

void BST::inorder(TreeNode *treePtr, 
                         FunctionType visit)
{
   if (treePtr != NULL)
   {  inorder(treePtr->leftChildPtr, visit);
      visit(treePtr->item);
      inorder(treePtr->rightChildPtr, visit);
   } // end if
}  // end inorder

void BST::postorder(TreeNode *treePtr, 
                           FunctionType visit)
{
   if (treePtr != NULL)
   {  postorder(treePtr->leftChildPtr, visit);
      postorder(treePtr->rightChildPtr, visit);
      visit(treePtr->item);
   } // end if
}  // end postorder

TreeNode *BST::rootPtr() const
{
   return root;
}  // end rootPtr

void BST::setRootPtr(TreeNode *newRoot)
{
   root = newRoot;
}  // end setRoot

void BST::getChildPtrs(TreeNode *nodePtr, 
                              TreeNode *& leftPtr, 
                              TreeNode *& rightPtr) const
{
   leftPtr = nodePtr->leftChildPtr;
   rightPtr = nodePtr->rightChildPtr;
}  // end getChildPtrs

void BST::setChildPtrs(TreeNode *nodePtr, 
                              TreeNode *leftPtr, 
                              TreeNode *rightPtr)
{
   nodePtr->leftChildPtr = leftPtr;
   nodePtr->rightChildPtr = rightPtr;
}  // end setChildPtrs


// ***************************************************************
// Below are the new methods (public and private) that I used
// to solve the project requirements.  You must implement the
// public methods using the exact same signature.  In contrast,
// you do not have to use the exact same private, helper method
// signatures.  In fact, you can write your own if you choose.
// ***************************************************************


//finds the distance to the farthest leaf
int BST::nodesOnMaxPathToLeaf(TreeNode* t) const
{
//TODO:
  if(t==NULL){
    return 0;
  } 
  else if(t->leftChildPtr==NULL && t->rightChildPtr==NULL){
    return 1;
  }
  else{
    if(nodesOnMaxPathToLeaf(t->leftChildPtr)>nodesOnMaxPathToLeaf(t->rightChildPtr)){
      return nodesOnMaxPathToLeaf(t->leftChildPtr)+1;
    }
    else{
      return nodesOnMaxPathToLeaf(t->rightChildPtr)+1;
    }
  }
}

//calls nodesOnMaxPathToLeaf finds the height of the tree
int BST::height() const
{
//TODO: Must Implement
  return nodesOnMaxPathToLeaf(root)-1;
}

//traverse list inorder and add elements to the array 
int BST::sortHelper(TreeItemType a[], int& i, TreeNode* t) const
{
//TODO:
  if(t==NULL){
    return 0;
  }
  else{
    sortHelper(a, i, t->leftChildPtr);
    a[i]=t->item;
    i++;
    sortHelper(a, i, t->rightChildPtr);
    return 1;
  }
}

//calls sortHelper
void BST::sort(TreeItemType a[]) const
{
//TODO: Must Implement
  int i = 0;
  sortHelper(a, i, root); 
}

//tests if the tree is full or not
bool BST::checkFull() const
{
//TODO: Must Implement
  return Full(root);
}

bool BST::Full(TreeNode* t) const
{
  if(t==NULL){
    return true;
  }
  else if(t->leftChildPtr==NULL && t->rightChildPtr==NULL){
    return true;
  }
  else if(t->leftChildPtr==NULL || t->rightChildPtr==NULL){
    return false;
  }
  else if(Full(t->leftChildPtr)==true && Full(t->rightChildPtr)==true){
    return true;
  }
  else{
    return false;
  }
}

//inserts root and the children of the root
void BST::buildHelper(TreeItemType a[],int first, int last)
{
//TODO:
  if(first==last){
    insertItem(root,a[first]);
  }
  else{  
    int mid = (first+last)/2;
    insertItem(root, a[mid]);
    if(mid!=first){
      buildHelper(a, first, mid-1);
    }
    if(mid!=last){
      buildHelper(a, mid+1, last);
    }
  }
}

//calls buildHelper, minimizes the height of the BST
void BST::minimizeHeight()
{
//TODO: Must Implement
  int s = size();
  TreeItemType a[s];
  sort(a);
  destroyTree(root);
  buildHelper(a , 0, s - 1); 
}

//finds the size of each subtree of t recursively
int BST::size(TreeNode* t) const
{
//TODO:
  if(t==NULL){
    return 0;
  }
  else{
    return (size(t->leftChildPtr)+size(t->rightChildPtr)+1);
  }
}

//if the BST is empty the size = 0 otherwise, call size(TreeNode *t)
int BST::size() const
{
//TODO: Must Implement
  size(root);   
}

bool BST::same(TreeNode* r, TreeNode* t)
{
  if(r==NULL||t==NULL){
    if(t==NULL&&r==NULL){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    if(r->leftChildPtr==NULL&&r->rightChildPtr==NULL){
      if(t->leftChildPtr==NULL&&t->rightChildPtr==NULL){
        return true;
      }  
    }
    if(r->leftChildPtr!=NULL){
      if(t->leftChildPtr==NULL){
        return false;
      }
      else{
        return same(r->leftChildPtr, t->leftChildPtr);
      }
    }
    if(r->rightChildPtr!=NULL){
      if(t->rightChildPtr==NULL){
        return false;
      }
      else{
        return same(r->rightChildPtr, t->rightChildPtr);
      }
    }
  }
}

bool BST::operator==(const BST& rhs)
{
//TODO: Must Implement
  return same(root, rhs.root);
}  // end operator==

// End of implementation file.





















