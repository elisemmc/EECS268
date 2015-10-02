/**Doctor.cpp*/

#include <iostream>
#include <fstream>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Hospital.h"

using namespace std;

typedef Patient* NodeItemType;

Doctor::Doctor(string first, string last){
  firstname = first;
  lastname = last;
  head = NULL;
  tail = NULL;  
}

void Doctor::addPatient (Patient* p_node){
  Patient* iter;
  iter = head;
  if (iter == NULL){
    head = p_node;
    tail = p_node;
    p_node -> next = NULL;
    p_node -> prev = NULL;
  }

  else{   
    while(iter != NULL){
      int compare = (p_node -> lastname).compare(iter -> lastname);
      if(iter -> next == NULL){
        if(compare >= 0){
          p_node -> next = NULL;
          p_node -> prev = iter;
          iter -> next = p_node;
          tail = p_node;
          return;
        }
        if(compare < 0){
          p_node -> prev = iter -> prev;
          p_node -> next = iter;
          iter -> prev = p_node;
          head = p_node;
          return;
        }
      }
      else if(compare <= 0){
        if(iter -> prev = NULL){
          p_node -> next = iter;
          p_node -> prev = NULL;
          iter -> prev = p_node;
          head = p_node;
          return;
        }
        else{
          Patient* before;
          before = iter -> prev;
          p_node -> prev = iter -> prev;
          p_node -> next = iter;
          iter -> prev = p_node;
          before -> next = p_node;
        }
      }
      iter = iter -> next;
    }
  }
}

Patient* Doctor::searchPatient(string first, string last){
  Patient* iter;
  iter = head;
  if( head -> firstname == first && head -> lastname == last){
    return head;
  }
  else{ 
    while (NULL != iter){
      if( iter -> firstname == first && iter -> lastname == last){
        return iter;
      }
      iter = iter -> next;
    }  
    return NULL;
  }
}

void Doctor::deletePatient(string first, string last){
  Patient* temp;
  temp = searchPatient(first, last); 
  if (temp==NULL){
    cout << "Patient " << first << " " << last << " not found for doctor " 
         << firstname << " " << lastname << ".\n";
    cout << "Unable to delete patient.\n";
  }
  else if (temp == head){
    if(temp -> next == NULL){
      head = NULL;
      delete temp;
    }
    else{
      Patient* tempn;
      tempn = temp -> next;
      head = tempn;
      tempn -> prev = NULL;
      delete temp;
    }
  }
  else if (temp == tail){
    Patient* tempp;
    tempp = temp -> prev;
    tail = tempp;
    tempp -> next = NULL;
    delete temp;
  }  
  else{
    Patient* tempp;
    tempp = temp -> prev;
    Patient* tempn;
    tempn = temp -> next;
    tempp -> next = temp -> next;
    tempn -> prev = temp -> prev;
    delete temp;
  }
}

void Doctor::deleteAllPatients(){
  while(head != NULL){
    deletePatient(head->firstname, head->lastname);
  }
}
    

void Doctor::print(){
  Patient* iter;
  iter = head;
  cout << "\nDoctor: " << firstname << " " << lastname << "\n";
  cout << "List of patients:\n";
  while(iter != NULL){
    iter->print();
    iter = iter -> next;
  }
}
  


































  
