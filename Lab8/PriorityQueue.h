#include "ListT.h"
using namespace std;

//template <typename T>
template <typename T>
class PriorityQueue : private List<T>
{

public:
  //constructor
	PriorityQueue();
	//add item to priority queue
	void enqueue(T item);
	//remove the item with the highest priority from the list
	void dequeue();
	//remove the item with the highest priority and assign its value to T& item
	void dequeue(T& item);
	//look at the item with highest priority and assign its value to T& item
	void peek(T& item);
	//return the size of the priority queue
	int getSize();
  //gets node
  void get(int index, T& dataItem);
	
	//overloaded assignment operartor, performs deep copy of rhs
	PriorityQueue<T>& operator =(PriorityQueue<T>& rhs);
};


//overloaded output operator
template <typename T>
ostream& operator <<(ostream &os, PriorityQueue<T>& rhs)
{
  T item;
  int length = rhs.getSize();
  for(int i=1; i <= length ; i++){
    rhs.get(i, item);
    os << i << ": " << item << "\n";
  }
  return os;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator =(PriorityQueue<T>& rhs)
{
  T item;
  int length = rhs.getSize();
  for(int i=1; i<=length; i++){
    rhs.dequeue(item);
    this->enqueue(item);
  }
  return *this;
}

#include "PriorityQueue.cpp"
