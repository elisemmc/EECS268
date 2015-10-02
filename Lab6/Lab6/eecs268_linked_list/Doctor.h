/** @file Doctor.h */
#ifndef GUARD_DOCTOR
#define GUARD_DOCTOR

#include "Patient.h"
#include <string>

class Doctor
{

typedef Patient* NodeItemType;

public:

  Doctor();
  
  Doctor(string first, string last);

  /**Inserts a patient into the doctor's patient list
    *@pre none
    *@post patient is added to the doctor's list alphabetically.*/
  void addPatient (NodeItemType Patient);

  /**Deletes a patient from a doctor's list
    *@pre patient exists
    *@post specified patient is deleted from the linked list.*/
  void deletePatient(string firstname, string lastname);

  void deleteAllPatients();

  /**Searches the patient list for the specified patient
    *@pre patient exists
    *@post if patient exists the patient pointer is returned.*/
  Patient* searchPatient(string firstname, string lastname);

  /**Prints off the list of patients for the doctor
    *@pre none
    *@post prints off the list of patients*/
  void print();

  string firstname;
  string lastname;
  
  Patient* head, *tail;
  Doctor* nextDoc;
  Doctor* prevDoc;
};

#endif
