#include <iostream>
#include "triangle.h"

using namespace std;
class Triangle;

int main()
{
  Triangle Default = Triangle(); //sides are 1,1,1
  Triangle myTriangle = Triangle(3.0,4.0,5.0);  //sides are 3,4,5
  
  cout << "\n\nThe side lengths of Default are " << Default.getSide1() << ", " << Default.getSide2() << ", " << Default.getSide3();
  cout << "\nThe area of Default is " << Default.getArea();
  if (Default.rightTriangle() == true){
    cout << "\nmyTriangle is a right triangle.";
  }
  if (Default.equilateralTriangle() == true){
    cout << "\nmyTriangle is an equilateral triangle.";
  }
  if (Default.isoscelesTriangle() == true){
    cout << "\nmyTriangle is an isosceles triangle.";
  }
  if (Default.equilateralTriangle() == true && Default.isoscelesTriangle() == true){
    cout << "\nI assume that equilateral triangles still count as isosceles triangles.";
  }
  cout << "\n\nThe side lengths of myTriangle are " << myTriangle.getSide1() << ", " << myTriangle.getSide2() << ", " << myTriangle.getSide3();
  cout << "\nThe area of myTriangle is " << myTriangle.getArea();
  if (myTriangle.rightTriangle() == true){
    cout << "\nmyTriangle is a right triangle.";
  }
  if (myTriangle.equilateralTriangle() == true){
    cout << "\nmyTriangle is an equilateral triangle.";
  }
  if (myTriangle.isoscelesTriangle() == true){
    cout << "\nmyTriangle is an isosceles triangle.";
  }
  if (myTriangle.equilateralTriangle() == true && myTriangle.isoscelesTriangle() == true){
    cout << "\nI assume that equilateral triangles still count as isosceles triangles.";
  }

  myTriangle.setSides(2,2,3);
  cout << "\n\nThe side lengths of myTriangle are now " << myTriangle.getSide1() << ", " << myTriangle.getSide2() << ", " << myTriangle.getSide3();
  cout << "\nThe area of myTriangle is " << myTriangle.getArea();
  if (myTriangle.rightTriangle() == true){
    cout << "\nmyTriangle is a right triangle.";
  }
  if (myTriangle.equilateralTriangle() == true){
    cout << "\nmyTriangle is an equilateral triangle.";
  }
  if (myTriangle.isoscelesTriangle() == true){
    cout << "\nmyTriangle is an isosceles triangle.";
  }
  if (myTriangle.equilateralTriangle() == true && myTriangle.isoscelesTriangle() == true){
    cout << "\nI assume that equilateral triangles still count as isosceles triangles.";
  }
  cout << "\n";
  return 0;
}//end main

