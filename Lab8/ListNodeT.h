#include <cstddef>
template <typename T> class List;

//This is the ListNode, items in ListT are of this type
template <typename T>
class ListNode
{
private:
	ListNode(): next(NULL){}
	ListNode(const T & nodeItem, ListNode *ptr):item(nodeItem), next(ptr){}

	//The item the node holds
	T item;

	//A pointer to the next node
	ListNode *next;

	friend class List<T>;
};

