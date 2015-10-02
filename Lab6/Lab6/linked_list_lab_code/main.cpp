#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "Node.h"

using namespace std;

int main(int argc, char* argv[])
{

  if ( argc < 3 ) {
    cout << "Useage: ./list_example infile1 infile 2" << endl;
    exit(1);
  }

  /*  Area 1 */
  /*
   * use of -> operator and printing node pointer
   * under DDD
   */
  
  cout << "---------------------------" << endl;
  cout << "|         AREA 1          |" << endl;
  cout << "---------------------------" << endl;

  Node *node = new Node(1, NULL);
  Node *otherNode = new Node(2, NULL);
  Node *yetAnotherNode = new Node(3, NULL);

  node->setValue(10);
  otherNode->setValue(20);
  yetAnotherNode->setValue(30);

  node->setNext(otherNode);
  otherNode->setNext(yetAnotherNode);

  cout << "Nodes values" << endl;

  Node *cur = node;
    
  while (cur) {
    cout << cur->getValue() << endl;
    cur = cur->getNext();
  }

  delete node;
  delete otherNode;
  delete yetAnotherNode;

  /* Area 2 */
  /*
   * C++ string type use and some of the methods
   *
   * compare <=> strcmp, find_first_of <=> strchr
   * + - concatenate <=> strcpy
   * >> read operator for reading white-space delimited fields 
   *       - one per line
   */
  
  cout << "---------------------------" << endl;
  cout << "|         AREA 2          |" << endl;
  cout << "---------------------------" << endl;

  string str1 = "This is a string";
  string str2 = "another string";

  cout << "This is str1 = " << str1 << endl;
  cout << "This is str2 = " << str2 << endl;

  cout << endl;

  int compareResult = str1.compare(str2);
  cout << "Comparing str1 and str2 results in " << compareResult << endl;

  compareResult = str2.compare(str1);
  cout << "Comparing str2 and str1 gives you " << compareResult << endl;

  compareResult = str1.compare(str1);
  cout << "Comparing str1 with itself produces " << compareResult << endl;

  cout << endl;

  int positionFound = str1.find_first_of("a");
  cout << "This is the position of 'a' in str1: " << positionFound << endl;

  positionFound = str1.find_first_of("r");
  cout << "This is the position of 'r' in str1: " << positionFound << endl;

  cout << endl;

  string str3;
  str3 = str1 + " " + str2;
  cout << "This is the result for concatenating str1 and str2: \n" << str3 << endl;

  cout << endl;

  string str4;
  ifstream fin(argv[1]);

  fin >> str4;
  cout << "This is the first value of the file: " << str4 << endl;

  fin >> str4;
  cout << "This is the second value of the file: " << str4 << endl;

  fin >> str4;
  cout << "This is the third value of the file: " << str4 << endl;

  fin >> str4;
  cout << "This is the fourth value of the file: " << str4 << endl;

  /*
   * Last line has several words on it. Keep reading until the end of
   * file
   */
  while ( fin >> str4 ) {
    cout << "word read: " << str4 << endl;
  }

  cout << endl;

  fin.close();

  /* Area 3 */
  /*
   * Simple command file line reader - multiple fields per line
   */

  cout << "---------------------------" << endl;
  cout << "|         AREA 3          |" << endl;
  cout << "---------------------------" << endl;

  string command, str5;
  fin.open(argv[2]);

  while (fin >> command) {
    if (command.compare("add") == 0) {
      fin >> str5;
      cout << "Adding " << str5;
      fin >> str5;
      cout << "-" << str5 << endl;
    }
    else if (command.compare("remove") == 0) {
      fin >> str5;
      cout << "Removing " << str5 << endl;
    }
    else if (command.compare("print") == 0) {
      fin >> str5;
      cout << "Printing information on " << str5 << endl;
    }
    else {
      cout << "Error: invalid command" << endl;
    }
  }

  fin.close();

  exit(0);
}
