//dummy functions & pure virtual functions:
#include <iostream>
using namespace std;

class Shape
{
private:
    string name;
public:
    Shape(string n)
    {
        name = n;
    }
    virtual double getArea() = 0; //dummy/abstract function
    //never meant to be used.
    //why would we need an abstract shape w/ 0 area?
    //we need to do virtual double getArea() = 0;
    //to make it a "pure virtual" functions.
    //this means the base version of the function will
    //never be called, so no logic in the body.
    //we will not be able to create instances of the Base
    //class after, so all derived classes must redefine
    //all pure virtual functions.
    //note: if you define at lease one "pure virtual
    //function" in a base class, then that base class is
    //called a "ABC(Abstract Base Class)". if a derived
    //class does not provide code for all pure virtual
    //functions, that child class becomes an ABC.
    //note: you cant create a variable/object w/ ABC, but
    //you can use it for polymorphism.
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
    //overriding getArea from base.
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
    //overriding getArea from base.
    virtual double getArea()
    {
        return (3.14 * radius * radius);
    }
}; //close Circle child class.

int main()
{
    //Shape shapeOne("shapeOne");
    //error bc Shape is ABC.
    
    return 0;
}
