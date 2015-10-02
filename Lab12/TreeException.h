// ********************************************************
// Header file TreeException.h for the ADT binary tree.
// ********************************************************
#ifndef TREEEEXCEPTION_H
#define TREEEEXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class TreeException: public logic_error
{
public:
   TreeException(const string & message = "")
                        : logic_error(message.c_str())
   { }
};  // end TreeException

#endif
