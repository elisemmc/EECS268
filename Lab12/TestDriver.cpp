#include <iostream>
#include <cassert>
#include <cmath>
#include "BST.h"
using namespace std;

class BSTTester
{
 public:
  bool leftTreeProperty(TreeNode* t, KeyedItem k)
  {
    return t == NULL ||
           ( t->item.getKey() < k.getKey() &&
            leftTreeProperty(t->leftChildPtr, t->item.getKey()) &&
            rightTreeProperty(t->rightChildPtr, t->item.getKey()));
  }

  bool rightTreeProperty(TreeNode *t, KeyedItem k)
  {
    return t == NULL ||
           ( t->item.getKey() > k.getKey() &&
            leftTreeProperty(t->leftChildPtr, t->item.getKey()) &&
            rightTreeProperty(t->rightChildPtr, t->item.getKey()));
  }

  bool bstProperty(TreeNode* t)
  {
    return t == NULL ||
           (leftTreeProperty(t->leftChildPtr, t->item.getKey()) &&
            rightTreeProperty(t->rightChildPtr, t->item.getKey()));
  }

  bool minHeightProperty(const TreeNode* t)
  {
    if(t == NULL)
      return true;

    BST left, right;
    left.root = t->leftChildPtr; //shallow I know, but I'm not planning
                                 //on using left for anything but height()
    right.root = t->rightChildPtr; //dido

    bool returnValue = 1 >= abs(left.height() - right.height()) &&
                       minHeightProperty(t->leftChildPtr) &&
                       minHeightProperty(t->rightChildPtr);

    left.root = right.root = NULL; //no it's not a memory leak, it
                                   //just ensures when left and right
                                   //are deallocated that the subtrees
                                   //of t are not deallocated
    return returnValue;
  }

  void testMinimizeHeight()
  //requires that equals and height are implemented correctly
  {
    BST t;
    //empty tree has min height
    assert(minHeightProperty(t.root));

    //single node has min height
    t.searchTreeInsert(string("3"));
    assert(minHeightProperty(t.root));

    //still min height...left child's length is greater by 1
    t.searchTreeInsert(string("2"));
    assert(minHeightProperty(t.root));

    //still min height...lengths are equal
    t.searchTreeInsert(string("4"));
    assert(minHeightProperty(t.root));

    //still min height...right child's length is greater by 1
    t.searchTreeInsert(string("5"));
    assert(minHeightProperty(t.root));

    //still min height...lengths are equal
    t.searchTreeInsert(string("1"));
    assert(minHeightProperty(t.root));

    //t is balanced but doesn't have min height
    //since right child is not balanced
    t.searchTreeInsert(string("6"));
    assert(!minHeightProperty(t.root));

    //unbalanced and not min height
    t.searchTreeInsert(string("9"));
    t.searchTreeInsert(string("7"));
    t.searchTreeInsert(string("8"));

    BST orig(t);

    t.minimizeHeight();

	 assert(orig.size() == t.size());

	 TreeItemType* a = new TreeItemType[orig.size()];
	 TreeItemType* b = new TreeItemType[t.size()];

    //t should retain the same size and elements
	 assert(orig.size() == t.size());

	 //get the elements of the tree in a sorted list	 
	 orig.sort(a);
	 t.sort(b);
	 
	 //verify the trees are (element-wise)equal
	 for(int i = 0; i < orig.size(); i++)
    	assert(a[i].getKey()==b[i].getKey());

	 //free arrays
	 delete[] a;
	 delete[] b;

    //ensure t is still a bst
    assert(bstProperty(t.root));

    //ensure t has min height
    assert(minHeightProperty(t.root));
  }

  void testEquals()
  {
    BST t1, t2;
    assert(t1==t2 && t2==t1);

    t1.searchTreeInsert(string("5"));
    assert(!(t1==t2) && !(t2==t1));

    t2.searchTreeInsert(string("5"));
    assert(t1==t2 && t2==t1);

    t2.searchTreeInsert(string("3"));
    assert(!(t1==t2) && !(t2==t1));

    t2.searchTreeInsert(string("4"));
    t1.searchTreeInsert(string("4"));
    t1.searchTreeInsert(string("3"));
    //trees with the same elements, but different
    //structure 
    assert(!(t1==t2) && !(t2==t1));
  }

  void testHeight()
  {
    BST t;
    assert(t.height() == -1);

    t.searchTreeInsert(string("5"));
    assert(t.height() == 0);

    t.searchTreeInsert(string("4"));
    assert(t.height() == 1);

    t.searchTreeInsert(string("7"));
    assert(t.height() == 1);

    t.searchTreeInsert(string("9"));
    assert(t.height() == 2);

    t.searchTreeInsert(string("8"));
    assert(t.height() == 3);

    t.searchTreeInsert(string("6"));
    assert(t.height() == 3);

    t.searchTreeInsert(string("3"));
    assert(t.height() == 3);

    t.searchTreeInsert(string("0"));
    assert(t.height() == 3);

    t.searchTreeInsert(string("2"));
    assert(t.height() == 4);
  }

  void testSize()
  {
    BST t;
    assert(t.size() == 0);

    t.searchTreeInsert(string("5"));
    assert(t.size() == 1);

    t.searchTreeInsert(string("4"));
    assert(t.size() == 2);

    t.searchTreeInsert(string("7"));
    assert(t.size() == 3);

    t.searchTreeInsert(string("8"));
    assert(t.size() == 4);

    t.searchTreeInsert(string("9"));
    assert(t.size() == 5);

    t.searchTreeInsert(string("6"));
    assert(t.size() == 6);

    t.searchTreeInsert(string("3"));
    assert(t.size() == 7);

    t.searchTreeInsert(string("0"));
    assert(t.size() == 8);

    t.searchTreeInsert(string("2"));
    assert(t.size() == 9);
  }

  void testSort()
  {
    BST t;
    t.searchTreeInsert(string("5"));
    t.searchTreeInsert(string("3"));
    t.searchTreeInsert(string("4"));
    t.searchTreeInsert(string("1"));
    t.searchTreeInsert(string("2"));
    t.searchTreeInsert(string("0"));
    t.searchTreeInsert(string("8"));
    t.searchTreeInsert(string("9"));
    t.searchTreeInsert(string("7"));
    t.searchTreeInsert(string("6"));

    TreeItemType a[10];
    t.sort(a);
    assert(a[0].getKey() == "0");
    assert(a[1].getKey() == "1");
    assert(a[2].getKey() == "2");
    assert(a[3].getKey() == "3");
    assert(a[4].getKey() == "4");
    assert(a[5].getKey() == "5");
    assert(a[6].getKey() == "6");
    assert(a[7].getKey() == "7");
    assert(a[8].getKey() == "8");
    assert(a[9].getKey() == "9");
  }

  void testFull()
  {
    BST t;
	t.searchTreeInsert(string("5"));
	assert(t.checkFull() == true);

	t.searchTreeInsert(string("3"));
	assert(t.checkFull() == false);

	t.searchTreeInsert(string("7"));
	assert(t.checkFull() == true);

	t.searchTreeInsert(string("8"));
	t.searchTreeInsert(string("6"));
	assert(t.checkFull() == true);

	t.searchTreeInsert(string("1"));
	t.searchTreeInsert(string("4"));
	assert(t.checkFull() == true);

	t.searchTreeInsert(string("2"));
	assert(t.checkFull() == false);
  }

}; //end BSTTester class

int main()
{
  BSTTester test;

  test.testSize();
  test.testHeight();
  test.testEquals();
  test.testSort();
  test.testMinimizeHeight();
  test.testFull();

  return 0;
}

