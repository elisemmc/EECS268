/**calc.cpp*/

#include <iostream>
#include <string>
#include <stack>

#include "calc.h"

using namespace std;

calc::calc(){}

string calc::inPost(string infix){
  stack<char> p_exp;
  stack<char> op;
  string backwards, postfix;
  char temp;
  int operation;
  bad = false;
  for(int i=0; i < infix.length(); i++){
    if(infix[i]=='(')
      operation = 1;
    else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
      operation = 2;
    else if(infix[i]==')')
      operation = 3;
    else
      operation = 4;
        
    switch (operation){     
    case 1:
      op.push('(');
      break;
    case 2:
      if (op.empty() == true){
         //just go to the push fuction at the end
      }
      else if(infix[i]=='+'||infix[i]=='-'){
        while(op.top()=='*'||op.top()=='/'||op.top()=='+'||op.top()=='-'){
          temp = op.top();
          p_exp.push(temp);
          op.pop();
          if (op.empty()){
            break;
          }
        }
      }    
      else if(infix[i]=='*'||infix[i]=='/'){
        while(op.top()=='*'||op.top()=='/'){
          temp = op.top();
          p_exp.push(temp);
          op.pop();
          if (op.empty()){
            break;
          }
        }
      } 
      op.push(infix[i]);        
      break;
    case 3 :
      while(op.top()!='('){
        temp = op.top();
        op.pop();
        p_exp.push(temp);
        if (op.empty()){
          cout << "\nUnbalanced parenthesis\n";
          bad = true;
          break;
        }  
      }
      if (!op.empty()){  
        op.pop();
      }     
      break;
    default:
      p_exp.push(infix[i]);
      break;
    }//end switch
  }//end for
  
  while(!op.empty()){
    temp = op.top();
    p_exp.push(temp);
    op.pop();
  }  
  while(!p_exp.empty()){
    temp = p_exp.top();
    if (temp == '('){
      cout << "\nUnbalanced parenthesis\n";
      bad = true;
    }
    p_exp.pop();
    backwards += temp;
  }//end while

  for(int i=0; i<backwards.length(); i++){
    p_exp.push(backwards[i]);
  }
  while(!p_exp.empty()){
    postfix += p_exp.top();
    p_exp.pop();
  }

  return postfix;
}//end inPost

void calc::setVar(char x, double value){
  matrix[x-'a']= value;//allocates area in the matrix based on number char is assigned
}//end setVar

double calc::eval(string postfix){
  stack<double> wrath;
  double op1, op2, sloth;

  for(int i=0; i<postfix.length(); i++){
    switch (postfix[i]){
    case('+'):
      op2=wrath.top();
      wrath.pop();
      op1=wrath.top();
      wrath.pop();
      sloth = op1+op2;
      wrath.push(sloth);
      break;
    case('-'):
      op2=wrath.top();
      wrath.pop();
      op1=wrath.top();
      wrath.pop();
      sloth = op1-op2;
      wrath.push(sloth);
      break;
    case('*'):
      op2=wrath.top();
      wrath.pop();
      op1=wrath.top();
      wrath.pop();
      sloth = op1*op2;
      wrath.push(sloth);
      break;
    case('/'):
      op2=wrath.top();
      wrath.pop();
      op1=wrath.top();
      wrath.pop();
      sloth = op1/op2;
      wrath.push(sloth);
      break;
    default:
      wrath.push(matrix[postfix[i]-'a']);
      break;
    }//end switch
  }//end for
  sloth = wrath.top();
  wrath.pop();
  if(!wrath.empty()){
    bad = true;
  }
  return sloth;
}//end eval
    
    
  
  
  
  



















        
         
