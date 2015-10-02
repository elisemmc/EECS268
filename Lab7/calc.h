/** calc.h */

#include <string>

using namespace std;

class calc
{
private:

  double matrix[26];

public:

  /*constructor*/
  calc();
  
  /*pre:infix is a string that is an infix expression
    post: returns a string of the postfix version of the infix expression*/
  string inPost(string infix);

  /*pre:char var and double value
    post: char var will be assigned value*/
  void setVar(char var, double value); 

  /*pre:given postfix expression
    post: returns value of postfix expression*/
  double eval(string post);

  bool bad;

}; 

