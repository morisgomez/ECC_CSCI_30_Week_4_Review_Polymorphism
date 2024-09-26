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
    //virtual= will define new version of func in //derived class
    //also called "specialization/overriding"
    virtual double getArea()
    {
        return 0;
        //0 for now bc subshapes have distinct areas.
    }
    void printPricesSq(Shape &k)
    //only aware of functions in base class, so thinks every object
    //passed is a base object.
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
    //1) create Shape object:
    Shape shapeOne("abstract");
    cout << shapeOne.getArea() << endl;
    
    //2) create Square object:
    Square squareOne("squareOne", 3);
    cout << squareOne.getArea() << endl; //9
    //not poly^: using specialization.
    cout << squareOne.Shape::getArea() << endl; //0
    //not poly^: using specialization but accessing the //getArea base function via child class.
    
    //3) create Circle object:
    Circle circleOne("circleOne", 6);
    cout << circleOne.getArea() << endl;
    
    //4) polymorphism:
    squareOne.printPricesSq(squareOne); //using getArea() of Square.
    circleOne.printPricesSq(circleOne); //using getArea() of Circle.
    //note..printPricesSq() is only in base function. it is not
    //specialized in any of the child classes either.
    //we pass a child object from main, but the function only takes
    //in ptr to objects of the base class. However, we still
    //access the derived class object's specialized getArea()
    //function from the base's printprice.
    shapeOne.printPricesSq(shapeOne); //0
    //above uses the getArea() function of the base class.
    
    return 0;
}
//Summary:
//INHERITANCE:
//1. We publicly derive classes from a common base class.
//2. e.g sub class Square from base class Shape.

//3. derived classes inherit a common set of functions from our //base class: e.g getArea()
//4. each derived class may redefine any function which is defined
//in the base class. the derived class will have its own
//specialized version of that function.

//POLYMORPHISM:
//1. I may use a Base pointer/reference to access any variable/object that is of a
//type that is derived from our Base class.

//When to use virtual keyword?:
//1. use it in the base any time you expect to redefine a function in a child.
//2. use it in the child classes any time you redefine a function (not req'd though).
//3. use it for the destructor in your base class.
//4. you cannot have a virtual constructor.

