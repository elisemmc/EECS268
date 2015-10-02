/*
 * A1-BookStoreCustomer.h - Header file that contains the class definitions
 * and function prototypes for the BookStoreCustomer project
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

const int NBOOKS = 5;
string BookNameCatalog[NBOOKS] = {"Math", "Phsx", "Chem", "Geo", "Hist"};
int BookPriceCatalog[] = {100, 85, 70, 65, 60};

class BookStoreCustomer{
private:
  int NumberOfCourses;
  string *CustomerBookName;
  int *CustomerBookQty;

public:
  // Constructors and destructors
  BookStoreCustomer();
  ~BookStoreCustomer();
  void readInput();
  double getCustomerSale();
};
