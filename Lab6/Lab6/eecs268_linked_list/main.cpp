#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Hospital.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;

enum Command {
  HIRE_DOCTOR,
  FIRE_DOCTOR,
  PRINT_DOCTOR,
  ADD_PATIENT,
  REMOVE_PATIENT,
  PRINT_PATIENT,
  PRINT_HOSPITAL,
  INVALID
};

Command identifyNextCommand(const string& cmdStr)
{
  Command command;

  if (cmdStr.compare("hire") == 0) {
    command = HIRE_DOCTOR;
  } else if (cmdStr.compare("fire") == 0) {
    command = FIRE_DOCTOR;
  } else if (cmdStr.compare("print-doctor") == 0) {
    command = PRINT_DOCTOR;
  } else if (cmdStr.compare("add-patient") == 0) {
    command = ADD_PATIENT;
  } else if (cmdStr.compare("remove-patient") == 0) {
    command = REMOVE_PATIENT;
  } else if (cmdStr.compare("print-patient") == 0) {
    command = PRINT_PATIENT;
  } else if (cmdStr.compare("print-hospital") == 0) {
    command = PRINT_HOSPITAL;
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
  string doctorFirstname, doctorLastname;
  string patientFirstname, patientLastname, ailment;
  int age;
  Patient *patient;
    
  ifstream fin(argv[1]);
		
  Hospital *hospital = new Hospital("KU Hospital");
  Command command;


  while (fin >> cmdStr) {
    command = identifyNextCommand(cmdStr); 
        
    switch (command) {
    case HIRE_DOCTOR:
      //use fin to grab the doctorFirstname and doctorLastname and feed them into the hireDoctor function
      {fin >> doctorFirstname >> doctorLastname;
      hospital -> hireDoctor(doctorFirstname, doctorLastname);
      }
      break;
    case FIRE_DOCTOR:
      //use fin to grab the inputs for fireDoctor
      {fin >> doctorFirstname >> doctorLastname;
      hospital -> fireDoctor(doctorFirstname, doctorLastname);
      }
      break;
    case PRINT_DOCTOR:
      //create a Doctor* object using searchDoctor to construct it then use that object's rint member function
      {fin >> doctorFirstname >> doctorLastname;
      Doctor* doctor = hospital -> searchDoctor(doctorFirstname, doctorLastname);
      if (doctor == NULL){
        cout << "\nDoctor " << doctorFirstname << " " << doctorLastname << " not found.\n";
        cout << "Unable to print doctor.\n";
        break;
      }
      doctor -> print();
      cout << "----\n";
      }
       break;
    case ADD_PATIENT:
      //grab the inputs needed to construct a Patient object and add it using the Hospital addPatient
      {fin >> doctorFirstname >> doctorLastname >> patientFirstname >> patientLastname >> age >> ailment;
      Patient* patient;
      patient = new Patient(patientFirstname, patientLastname, age, ailment);
      hospital -> addPatient(doctorFirstname, doctorLastname, patient);
      }
      break;
    case REMOVE_PATIENT:
      //using the given variables, delete the patient through the Hospital deletePatient member function
      {fin >> doctorFirstname >> doctorLastname >> patientFirstname >> patientLastname;
      hospital -> removePatient(doctorFirstname, doctorLastname, patientFirstname, patientLastname);
      }
      break;
    case PRINT_PATIENT:
      //search for a given patient using the searchPatient member function and then tell that object to print using it's print member function
      {fin >> doctorFirstname >> doctorLastname >> patientFirstname >> patientLastname;
      patient = hospital -> searchPatient(doctorFirstname, doctorLastname, patientFirstname, patientLastname);
      if (patient == NULL){
        cout << "\nPatient " << patientFirstname << " " << patientLastname << " not found.\n";
        cout << "Unable to print patient.\n";
        break;
      }
      cout << "\n";
      patient -> print();
      cout << "----\n";
      }
      break;
    case PRINT_HOSPITAL:
      //use the Hostpital print member function
      {hospital -> print();
      cout << "----\n";
      }
      break;
    case INVALID:
      {cout << "Error: invalid command" << endl;
      }
      break;
    }
  }

  delete hospital;
  fin.close();

  exit(0);
}
