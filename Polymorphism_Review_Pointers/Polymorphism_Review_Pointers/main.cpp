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
    virtual double getArea()
    {
        return 0;
    }
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
    //1) Using Square ptr to access Square object.
    Square squareOne("squareOne", 6); //Square object/variable.
    Square *p; //ptr to point a Square object.
    p = &squareOne;
    cout << "address of squareOne: " << &squareOne << endl; //0x7ff7bfeff1f0
    cout << "address of squareOne:" << p << endl; //0x7ff7bfeff1f0
    cout << p->getArea() << endl;
    
    //2) Because a Square is a type of Shape, we can point
    //a Shape pointer to a Square variable.
    //in general we can point a superclass
    //pointer to a subclass variable.
    //would Square technically be a Shape data type since
    //it is derived from it.
    
    //3) Use a Shape pointer to point to a Circle and get
    //its area:
    Circle circleOne("circleOne", 3.6); //Circle object.
    Shape *shapePtr = &circleOne; //shape pointing to Circle object.
    cout << "address of circleOne: " << &circleOne << endl;
    //0x7ff7bfeff198
    cout << "address of circleOne: " << shapePtr << endl;
    //0x7ff7bfeff198
    cout << "area of circleOne: " << shapePtr->getArea() << endl; //40.6944
    
    //4) cannot have a Square ptr pointing to a Shape
    //cant go backwards?
    //Shape shapeOne("shapeOne"); //error
    //Circle *z = &shapeOne; //error
    
    circleOne.printPricesSq(circleOne); //$132.257
    //normally printPricesSq(Shape) takes in an object.
    circleOne.printPricesSq(*shapePtr); //$132.257
    //but can also take in a pointer to that object.
    
    return 0;
}
