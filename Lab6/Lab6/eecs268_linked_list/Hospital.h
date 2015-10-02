/** @file Hospital.h */

#include <iostream>
#include <fstream>
#include <string>

#include "Doctor.h"

using namespace std;

class Hospital
{
public:

  Hospital();

  Hospital(string name);

  /**Adds a doctor onto the list.
    *@pre text file has "hire doctor_first doctor_last" as a line.
    *@post a doctor with doctor_first doctor_last is added at the end of the doctor list. */
  void hireDoctor(string doctor_first, string doctor_last);

  /**Removes a doctor from the list.
    *@pre text file has "fire doctor_first doctor_last" as a line and a doctor with that name exists.
    *@post the doctor with name doctor_first doctor_last is removed from the list along 
    * with all patients.*/
  void fireDoctor(string doctor_first, string doctor_last);

  /**Searches for a specified doctor
    *@pre specified doctor exists
    *@post if doctor exists, returns the doctor pointer. */
  Doctor* searchDoctor(string doctor_first, string doctor_last);

  /**Adds a patient onto a doctor's patient list.
    *@pre text file has "add-patient doctor_first doctor_last patient_object" as a line
    *@post a patient with specified name and condition will be added onto the specified 
    * doctors list in alphabetical placement.*/
  void addPatient(string doctor_first, string doctor_last, Patient* patient_object);

  /**Deletes a patient from a doctor's patient list.
    *@pre patient of specified name exists on specified doctors list and a text line of
    * "add-patient doctor_first doctor_last patient_first patient_last" is listed on the file.
    *@post specified patient is removed from the specified doctor's list. */
  void removePatient(string doctor_first, string doctor_last, string patient_first, string patient_last);

  /**Searches the list for a patient of specified name
    *@pre the specified patient exists under the specified doctor.
    *@post returns the patient object for specified patient. */
  Patient* searchPatient(string doctor_first, string doctor_last, string patient_first, string patient_last);

  /**Prints out the entire list of patients for the hospital
    *@pre the text file has line "print"
    *@post the entire list of patients is printed */
  void print();
    
private:
  Doctor* head, *tail;

  Doctor* prevDoc;
  Doctor* nextDoc;

  string name;
};
  
