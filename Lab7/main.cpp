#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "calc.h"

using namespace std;

enum Command {
  EXP,
  MAP,
  INVALID 
};

Command identifyNextCommand(const string& cmdStr)
{
  Command command;

  if (cmdStr.compare("exp") == 0) {
    command = EXP;
  } else if (cmdStr.compare("map") == 0) {
    command = MAP;
  } else {
    command = INVALID;
  }

  return command;
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
      cerr << "Usage error: ./main input.txt" << endl;
      exit(1);
  }

  string cmdStr;
  string infix, postfix;
  char var;
  double value, evaluation;
  calc *calc1 = new calc();
  
  infix = "(a+b)*c-d";
      
  ifstream fin(argv[1]);
		
  Command command;

  while (fin >> cmdStr) {
    command = identifyNextCommand(cmdStr); 
        
    switch (command) {
    case EXP:
      //use fin to grab the infix function
      {fin >> infix;
      postfix = calc1->inPost(infix);
      }
      break;
    case MAP:
      //use fin to grab the name of the variable and the value
      {fin >> var >> value;
      calc1->setVar(var, value);
      }
      break;
    case INVALID:
      {cout << "Error: invalid command" << endl;
      }
      break;
    }
  }

  if(calc1 -> bad == false){
    postfix= calc1-> inPost(infix);
    evaluation = calc1->eval(postfix);
    
    if(calc1 -> bad == false){//bad may change in the eval command therefore if statement is repeated
      cout << "\nInfix: " << infix << "\n";
      cout << "Postfix: " << postfix << "\n";
      cout << "Evaluation: " << evaluation << "\n\n";
    }
  }
  if(calc1 -> bad == true){
    cout << "ERROR: improper function.\n";
  }
  delete calc1;

  fin.close();
  exit(0);
}

