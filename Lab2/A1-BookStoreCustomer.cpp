/*
 * Elise McEllhiney
 * 2298962
 * 8/29/2012
 * EECS 268 Lab 2
 *
 * Program to diffentiate C++ programming from Java.
 * (See A1BookStoreCustomer.java for comparison).
 * In C++,
 * 1. Variables and methods can be declared/defined outside of class.
 * 2. C++ forbids initialization of non-static data members in class.
 * 3. Difference in input/output.
 * 4. "string" used for character strings (Vs. "String" in Java).
 * 5. Use of pointers in common in C/C++. Java uses references (like pointers
 *    with different syntax and more restricted).
 * 6. Explicit memory management. See use of "delete" in C++.
 * 7. Constructors for arrays called at different times. C++ constructor is
 *    called when array is allocated. In Java we need two "new" statements,
 *    once for allocating the array of "object references" and then for
 *    allocating each object element in the array.
 * 8. Can define explict destructor called on "delete". No destructor in Java
 *    as memory in implicitly deallocated (finalize() comes closest).
 */
#include "A1-BookStoreCustomer.h"

/*
 * Constructor - Initialize the data elements of this class object
 */
BookStoreCustomer::BookStoreCustomer()
{
  NumberOfCourses = 0;
  CustomerBookName = NULL;
  CustomerBookQty = 0;
  cout << "Constructor reached\n";
}

/*
 * Destructor - De-allocate the dynamic arrays in this object
 */
BookStoreCustomer::~BookStoreCustomer()
{
  delete[] CustomerBookName;
  delete[] CustomerBookQty;
  cout << "Destructor reached\n";
}

/*
 * readInput - Read the input regarding customer book purchases and construct
 * objects, initialize them to user-input values
 */
void BookStoreCustomer::readInput()
{
  int numCust, numCourse;
  string bNames;
  int bQty;

  // Wait for user to enter the book purchase details of each customer
  	
  //******************Your code goes here*************************

  cout << "Enter number of different courses: ";
  cin >> numCourse;
  NumberOfCourses = numCourse;

  // Number of different courses cannot be greater than the total number of
  // courses offered
  
  if (numCourse > NBOOKS){
    cout << "Error: Customer courses > total courses offered\n";
    exit(1);
  }

  //*******************Your code goes here*************************
  // Allocate storage for holding book-name and price
  
  CustomerBookName = new string[numCourse];
  CustomerBookQty = new int[numCourse];
  
  cout << "Enter the Books Name List: ";
  for(int j=0 ; j<NumberOfCourses ; j++){
    cin >> bNames;
    CustomerBookName[j] = bNames;
  }
  
  cout << "Enter the Quantity List in the same order as the Book List: ";
  for(int j=0 ; j<numCourse ; j++){
    cin >> bQty;
    CustomerBookQty[j] = bQty;
  }  
	
  //*******************Your code goes here*************************  

}


/*
 * getCustomerSale - print statistics on customer sale to console
 */
double BookStoreCustomer::getCustomerSale()
{
  int total = 0;
  int index;
  // Add the book price for each book
  //*******************Your code goes here*************************
  
  for(int i=0 ; i<NumberOfCourses ; i++){ 
 
   // find the index of the current course

    for(index=0 ; index<=(NBOOKS) ; index++){
      if(index != 5){
	if(CustomerBookName[i] == BookNameCatalog[index]){
          total += CustomerBookQty[i] * BookPriceCatalog[index];
          break;
        }
      }
      if(index == NBOOKS){
      	cout << "Book " << CustomerBookName[i] << " Not Found\n";
      	//continue;
      }
    }
  }

    //*******************Your code goes here*************************  

  return total;
}


/*
 * Main function
 */

int main()
{
  int numCust;
  double total;
  BookStoreCustomer *customers;
  
  // Wait for user to enter the number of customers
  //*******************Your code goes here*************************
  
  cout << "Enter number of Customers: ";
  cin >> numCust;
  customers = new BookStoreCustomer[numCust];

  // get customer data on number of books purchased
  //*******************Your code goes here*************************  
  
  for(int i=0 ; i<numCust ; i++){
    cout << "Enter data for Buyer " << (i+1) << "\n";
    customers[i].readInput();
  }
	
  cout << "\n\n";
  cout << "*********************";
  cout << "*** Sales Summary ***";
  cout << "*********************";
  cout << "\n";
  
  // get the sales summary per customer
  //*******************Your code goes here*************************
  
  for(int i=0 ; i<numCust ; i++){
    total = customers[i].getCustomerSale();
    cout << "The cost for Customer " << (i+1) << " is: " << total << "\n";
  }
  // delete customer array
  delete[] customers;

  return 0;
}
