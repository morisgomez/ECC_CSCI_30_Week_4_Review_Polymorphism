//virtual deconstructors:
#include <iostream>
using namespace std;

class Shape
{
private:
    string name;
public:
    //constructor for Shape class.
    Shape(string n)
    {
        name = n;
    }
    //virtual deconstructor
    virtual ~Shape()
    //w/o 'vritual,' only base constructor called.
    //if we delete a child data type, we need to call both
    //base and child deconstrucor for proper deletion.
    {
        cout << "Calling Shape parent deconstructor" << endl;
    }
    //dummy/abstract/pure virtual function:
    virtual double getArea() = 0;
    
    //function conducting polymorphism.
    void printPricesSq(Shape &k)
    {
        cout << "cost is: $" << k.getArea() * 3.25 << endl;
    }
}; //close Shape class.

class Square: public Shape
{
private:
    int side;
public:
    //square constructor:
    Square(string x, int s):Shape(x)
    {
        side = s;
    }
    //Square deconstructor:
    ~Square()
    {
        cout << "Calling Square child deconstructor" << endl;
    }
    //overriding getArea() function from base.
    virtual double getArea()
    {
        return side * side;
    }
}; //close Square child class.

class Circle: public Shape
{
private:
    float radius;
public:
    //circle constructor:
    Circle(string x, float r):Shape(x)
    {
        radius = r;
    }
    //Circle deconstructor:
    ~Circle()
    {
        cout << "Calling Circle child deconstructor" << endl;
    }
    //overriding getArea from base.
    virtual double getArea()
    {
        return (3.14 * radius * radius);
    }
}; //close Circle child class.

int main()
{
    //pointer pointing to a Circle variable.
    Circle *cirOnePtr = new Circle("circleOne", 2);
    cout << cirOnePtr << endl; //0x6000028844e0
    cout << cirOnePtr->getArea() << endl; //12.56
    cirOnePtr->printPricesSq(*cirOnePtr); //cost is: $40.82
    
    //making shapePtr point to a Circle Pointer. //legal.
    Shape *shapePtr = cirOnePtr;
    
    delete shapePtr; //calling virtual deconstructor.
    //prints:
    //"Calling Circle child deconstructor"
    //& "Calling Shape parent deconstructor"
    //deletes pointer or data?
    //we can delete that Circle via the Shape ptr bc we
    //can access a child variable via a base class.
    //summary: made a child ptr, then delete that child
    //ptr via a parent ptr.
    //having the 'virtual' in base destructor allows for
    //proper destruction of data bc both base and child
    //destructors are called.
    return 0;
}
