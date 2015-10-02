/** @file Triangle.h */
/** Definition of a class of triangles. */
class Triangle
{
  public:
    /**Default constructor: Creates a Triangle and initializes
     * its side lengths and angles to a default value.
     *precondition: none
     *postcondition: triangle of side lengths 1,1,1 exists. */
    Triangle();

    /** Constructor: Creates a Triangle of given side lengths.
     *precondition: side1, side2, and side3 are the desired side lengths.
     *postcondition: Triangle with side lengths side1, side2, and side3 exists. */
    Triangle(double iside1, double iside2, double iside3);

    /** Sets (alters) the side lengths of existing triangle.
     *precondition: newSide1, newSide2, newSide3 are the desired side lengths.
     *postcondition: the side lengths of triangle are changed ot newside1, newside2, newside3.*/
    void setSides(double newside1, double newside2, double newside3);
    
    /** Returns side1 of the triangle.
     *precondition: none.
     *postcondition: none.
     *return double side1*/
    double getSide1() const;

    /** Returns side2 of the triangle.
     *precondition: none.
     *postcondition: none.
     *return double side1*/
    double getSide2() const;

    /** Returns side3 of the triangle.
     *precondition: none.
     *postcondition: none.
     *return double side1*/
    double getSide3() const;
    
    /** Determines the Triangle area.
     *precondition: none.
     *postcondition: none.
     *return the radius. */
    double getArea();

    /** Determines if the triangle is a right triangle.
     *precondition: none.
     *postcondition: none.
     *return true if triangle is a right triangle.*/
    bool rightTriangle();

    /** Determines if the triangle is an equilateral triangle.
     *precondition: none.
     *postcondition: none.
     *return true if triangle is an equilateral triangle.*/
    bool equilateralTriangle();

    /** Determines if the triangle is an isosceles triangle.
     *precondition: none.
     *postcondition: none.
     *return true if triangle is an isosceles triangle.*/
    bool isoscelesTriangle();

  private:
    /**Triangles side lengths.*/
    double side1;
    double side2;
    double side3;
};  //end Triangle
//End of header file.

