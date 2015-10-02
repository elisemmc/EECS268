#include <cstdlib>
using namespace std;

//swaps smallest element to put it in the front of the unsorted portion of the list
template <class T>
void selectionSort(T a[], int n)
{
  T min, tmp;
  int i, j;
  for (i=0; i < (n-1); i++)
  {
    min=i;
    for(j=i+1; j<n; j++)
    {  
	    if (a[j] < a[min]) //compare to find smallest number in the list
	    {
        min = i;
	    }
      if (min != i)
      {
	      tmp = a[i];
	      a[i] = a[min];
	      a[min] = tmp;
      }
    }
  }
}  // end selectionSort
