/** @file Triangle.cpp */

#include <iostream>
#include <math.h>
#include "triangle.h" //header file

using namespace std;

Triangle::Triangle() : side1(1), side2(1), side3(1)
{
} //end default constructor

Triangle::Triangle(double iside1, double iside2, double iside3)
{
  if(iside1>0 && iside2>0 && iside3>0 && (iside1+iside2)>iside3 && 
    (iside2+iside3)>iside1 && (iside1+iside3)>iside2){
    
    side1 = iside1;
    side2 = iside2;
    side3 = iside3;
  }

  else{
    side1 = 1;
    side2 = 1;
    side3 = 1;
  }
}//end constructor

void Triangle::setSides(double newside1, double newside2, double newside3)
{
  if(newside1>0 && newside2>0 && newside3>0 && (newside1+newside2)>newside3 && 
    (newside2+newside3)>newside1 && (newside1+newside3)>newside2){
    
    side1 = newside1;
    side2 = newside2;
    side3 = newside3;
  }
  else{
    side1 = 1;
    side2 = 1;
    side3 = 1;
  }
}//end setSides

double Triangle::getSide1() const
{
  return side1;
}//end getSide1

double Triangle::getSide2() const
{
  return side2;
}//end getSide2

double Triangle::getSide3() const
{
  return side3;
}//end getSide2

double Triangle::getArea()
{
  double s = (side1+side2+side3)/2;
  return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}//end getArea

bool Triangle::rightTriangle()
{
  if((side1*side1)+(side2*side2) == (side3*side3)){
    return true;
  }
  else if((side2*side2)+(side3*side3) == (side1*side1)){
    return true;
  }
  else if((side3*side3)+(side1*side1) == (side2*side2)){
    return true;
  }
  else{
    return false;
  }
}//end rightTriangle

bool Triangle::equilateralTriangle()
{
  if(side1 == side2 && side2 == side3){
    return true;
  }
  else{
    return false;
  }
}//end equilateralTriangle()

bool Triangle::isoscelesTriangle()
{
  if(side1==side2 || side1==side3 || side2==side3){
    return true;
  }
  else{
    return false;
  }
}//end isoscelesTriangle()
