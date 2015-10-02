
template <typename T>
PriorityQueue<T>::PriorityQueue()
{  
}

template <typename T>
void PriorityQueue<T>::peek(T& item)
{ 
  this->retrieve(1, item);
}

template <typename T>
void PriorityQueue<T>::enqueue(T item)
{
  T holder;
  int length = this->getLength();
  if (length == 0){
    this->insert(1,item);
    return;
  }
  else{
    for(int i=1; i<= length; i++){
      this->retrieve(i, holder);
      if(item > holder){
        this->insert((i), item);
        return;
      }
    }
  }
  this->insert((this->getLength()+1), item);
  return;
}

template <typename T>
void PriorityQueue<T>::dequeue()
{  
  this->remove(1);
}

template <typename T>
void PriorityQueue<T>::dequeue(T& item)
{  
  this->retrieve(1,item);
  this->dequeue();
}

template <typename T>
int PriorityQueue<T>::getSize()
{  
  int length = this->getLength();
  return length;
}

template <typename T>
void PriorityQueue<T>::get(int index, T& dataItem)
{
  this->retrieve(index, dataItem);
}
