#include "ListNodeT.h"
#include "ListException.h"
#include "ListIndexOutOfRangeException.h"

template <typename T>
class List
{
public:
	//constructor
	List();

	//copy constructor
	List(const List<T> & aList);

	//deconstructor
	virtual ~List();

	//checks if the list is empty, true = empty, false = not empty
	virtual bool isEmpty() const;

	//returns the length of the list
	virtual int getLength() const;

	//insert a new item into the list
	virtual void insert(int index, const T& newItem)
		throw(ListIndexOutOfRangeException, ListException);

	//remove an item from the list
	virtual void remove(int index)
		throw(ListIndexOutOfRangeException, ListException);

	//retrieve an item from the list
	virtual void retrieve(int index, T& dataItem) const
		throw(ListIndexOutOfRangeException);

protected:
	void setSize(int newSize);			//set the size of the list
	ListNode<T> *getHead() const;		//return the headptr of the list
	void setHead(ListNode<T> *newHead);	//set the headptr to a new node
	T getNodeItem(ListNode<T> *ptr);	//return the node item
	ListNode<T> *getNextNode(ListNode<T> *ptr) const;	//return the next node

private:
	
	int size;								//keeps track of the size of the list
	void destroy();							//deletes all of the nodes in the list
	ListNode<T> *head;						//headptr of the list
	ListNode<T> *find(int position) const;	//find pointer
};
#include "ListT.cpp"
