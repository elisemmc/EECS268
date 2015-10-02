#include <cstdlib>
#include <queue>
using namespace std;

//swaps smallest element to put it in the front of the unsorted portion of the list
template <class T>
void radixSort(T a[], int n)
{
  int mod = 10;
  int chaff = 1;
  bool sorted = false;
  queue<T> zero;
  queue<T> one;
  queue<T> two;
  queue<T> three;
  queue<T> four;
  queue<T> five;
  queue<T> six;
  queue<T> seven;
  queue<T> eight;
  queue<T> nine;
  
  while(!sorted){ 
    for (int i=0; i < n; i++)
    {
      int div = (a[i]%mod-a[i]%chaff)/chaff;
      switch(div)
      {
      case 0:
        zero.push(a[i]);
        break;
      case 1:
        one.push(a[i]);
        break;
      case 2:
        two.push(a[i]);
        break;
      case 3:
        three.push(a[i]);
        break;
      case 4:
        four.push(a[i]);
        break;
      case 5:
        five.push(a[i]);
        break;
      case 6:
        six.push(a[i]);
        break;
      case 7:
        seven.push(a[i]);
        break;
      case 8:
        eight.push(a[i]);
        break;
      case 9:
        nine.push(a[i]);
        break;
      }
    }
    mod = mod * 10;
    chaff = chaff * 10;

    if(zero.size() == n){
      sorted = true;
    }

    int m = 0;
    while(!zero.empty()){
      a[m] = zero.front();
      zero.pop();
      m++;
    }
    while(!one.empty()){
      a[m] = one.front();
      one.pop();
      m++;
    }
    while(!two.empty()){
      a[m] = two.front();
      two.pop();
      m++;
    }
    while(!three.empty()){
      a[m] = three.front();
      three.pop();
      m++;
    }
    while(!four.empty()){
      a[m] = four.front();
      four.pop();
      m++;
    }
    while(!five.empty()){
      a[m] = five.front();
      five.pop();
      m++;
    }
    while(!six.empty()){
      a[m] = six.front();
      six.pop();
      m++;
    }
    while(!seven.empty()){
      a[m] = seven.front();
      seven.pop();
      m++;
    }
    while(!eight.empty()){
      a[m] = eight.front();
      eight.pop();
      m++;
    }
    while(!nine.empty()){
      a[m] = nine.front();
      nine.pop();
      m++;
    }
  }
}  // end quickSort





















