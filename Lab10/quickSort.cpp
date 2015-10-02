#include <cstdlib>
using namespace std;

//reiteratively sorts list into smaller lists until list is in order
template <class T>
void quickSort(T a[], int n)
{
  qksort(a, 0, n-1);
}  // end quickSort

template<class T>
int partition(T a[], int l, int r, int pivot)
{
  T pval = a[pivot];
  T tmp = a[r];
  a[r] = a[pivot];
  a[pivot] = tmp;
  int storeIndex = l;
  for(int i = l; i<(r-1); i++){
    if (a[i] < pval){
      tmp = a[i];
      a[i] = a[storeIndex];
      a[storeIndex] = tmp;
      storeIndex++;
    }
  }
  tmp = a[r];
  a[r] = a[storeIndex];
  a[storeIndex] = tmp;
  return storeIndex;
}

template<class T>
void qksort(T a[], int l, int r)
{
  T tmp;
  int pivot = (l + (r-l)/2);
  if(l<r){
    pivot = partition(a, l, r, pivot);
    if(pivot!=r)
      qksort(a, pivot+1, r);
    if(pivot!=l)
      qksort(a, l, pivot-1);
  }
}


      
  


/*template <class T>
void qksort(T a[], int f, int l)
{
  T tmp, pivot;
  tmp = a[f];
  a[f] = a[(l/2)]; //pivot = a[l/2]
  a[(l/2)]= tmp;
  int l2 = l;

  pivot = a[f];

  while (f != l2){
    if(pivot > a[f])
    {    
      tmp = a[f];
      a[f] = pivot;
      a[f-1] = tmp;
      f++;
    }
    else if(pivot <= a[f])
    {    
      tmp = a[f];
      a[f] = a[l2];
      a[l2] = tmp;
      l2--;
    }
  }
  if(pivot > a[f])
  {    
    tmp = a[f];
    a[f] = pivot;
    a[f-1] = tmp;
  }
  else
    f--;
  if(f==0)
    return;
  else if(f==l)
    return;
  else{
    qksort(a, 0, (f-1));
    qksort(a, (f+1) , l);
  }
}  // end sort
*/

