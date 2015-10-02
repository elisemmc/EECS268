/** @file Patient.h */
#ifndef GUARD_PATIENT
#define GUARD_PATIENT

#include <string>

using namespace std;

class Patient
{
public:

  /**Constructor*/
  Patient();

  Patient(string firstname, string lastname, int age, string ailment);
  
  /**Prints off the patient info
    *@pre none
    *@post patient info is printed off*/
  void print();
  
  string firstname;
  string lastname;
  int age;
  string ailment;

  Patient* next;
  Patient* prev;

};

#endif
