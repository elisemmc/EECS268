#include <cstddef>
#include <new>

using namespace std;

//ListT Constructor
template <typename T>
List<T>::List(): size(0), head(NULL)
{
}

//ListT Deconstructor
template <typename T>
List<T>::~List()
{
	destroy();
}

//cycles through and removes all node from the list
template <typename T>
void List<T>::destroy()
{
	if(head != NULL)
	{
    ListNode<T> *temp;
		temp = head;
		head = head->next;
		delete temp;
		destroy();
    }
  	head = NULL;
}

//checks if the list is empty, returns true if empty, returns false if not empty
template <typename T>
bool List<T>::isEmpty() const
{
	if(getLength() == 0)
		return true;
	else
		return false;
}

//returns the length of the list
template <typename T>
int List<T>::getLength() const
{
	return size;
}

//inserts a new node into the list at a given index
template <typename T>
void List<T>::insert(int index, const T & newItem)
  throw(ListIndexOutOfRangeException, ListException)
{

	int newLength = getLength()+1;
  
	if(index < 1 || index > newLength)
    	throw ListIndexOutOfRangeException("ListException:  insert out of range");
  	else
    {
    	try
		{
	  		ListNode<T> * newPtr = new ListNode<T>;
	  		size = newLength;
	  		newPtr->item = newItem;
	  
	  		if(index == 1)
	    	{
	      		newPtr->next = head;
	      		head = newPtr;
	    	}
	  		else
	    	{
	      		ListNode<T> * prev = find(index-1);
	      		newPtr->next = prev->next;
	      		prev->next = newPtr;
	    	}
		}
		catch (bad_alloc e)
		{
	  		throw ListException("ListException:  insert cannot allocate memory");
		}
    }
}

//removes the node at a given index in the list
template <typename T>
  void List<T>::remove(int index) throw(ListIndexOutOfRangeException, ListException)
{
	ListNode<T> *cur;
	
	if(index < 1 || index > getLength())
    	throw ListIndexOutOfRangeException("ListIndexOutOfRangeException:  remove index out of range");
  	else
    {
    	if(index == 1){
			cur = head;
			head = head->next;
      	}
      	else{
			ListNode<T> *prev = find(index-1);
			cur = prev->next;
			prev->next = cur-> next;
      	}
      	cur->next = NULL;
      	delete cur;
		size--;
      	cur = NULL;
	}
}

//retrieve the node at a certain index in the list, does not remove a node
template <typename T>
void List<T>::retrieve(int index, T& dataItem) const throw(ListIndexOutOfRangeException)
{
	if(index < 1 || index > getLength())
		throw ListIndexOutOfRangeException("ListException:  insert out of range");
  	else{
    	ListNode<T> *temp = find(index);
    	dataItem = temp->item;
  	}
}

//finds the node at the given index, returns the pointer to that node
template <typename T>
ListNode<T>* List<T>::find(int index) const
{
	if(index < 1 || index > getLength())
    	return NULL;
  	else
    {
    	ListNode<T> *cur = head;
      	for (int skip = 1; skip < index; ++skip)
			cur = cur->next;
      	return cur;
    }
}

