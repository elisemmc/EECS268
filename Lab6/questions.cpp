#include <iostream>
using namespace std;

int main(){
  int* x = new int(7);
  int y = *x;
  int* z = x;
  (*x)++;
  int* a = 0;
  cout<< "x:" << x;
  cout<< "&x" << &x;
  cout<< "*x" << *x;
  cout<< "y" << y;
  cout<< "*z"<<*z;
  cout<< "*a"<< *a;
  return 1;
}
