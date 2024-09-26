#include <iostream>
using namespace std;
/*
Polymorphism:
 - this is how we make inheritance truly useful.
 - ** once we define a function that accepts a reference or
 pointer to a "Person" object from that same class...
 - ** not only can we pass Person objects but also objects from
 other derived classes via that base class.
1) Virtual Functions.
2) Virtual Destructors.
3) Pure Virtual Functions.
4) Abstract Base Classes.
 
*/

class Person
{
private:
    string name;
    int age;
public:
    //parameter constructor:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    //getName() function:
    string getName()
    {
        return name;
    }
    //getAge() function:
    int getAge()
    {
        return age;
    }
//POLYMORPHISM:
    //void sayHi() function:
    //sayHi takes in an object of Person base class.
    //but we can also pass an object from Student child class.
    void sayHi(Person &p)
    {//pointing to an object created by Person class.
    //sayHi() func in Person class can take in a ptr to
    //object of itself????????
    //** we can pass a Student object as p...
    //** sayHi will never know p is pointing to a derived object.
    //we are using a base pointer to access a derived object.
    //p points to a Person object, it makes sense to call:
        //sayHi(personOne);
    //however, we can still call:
        //sayHi(studentOne);
    //studentOne is a derived object, and we are accessing it via base pointer/reference.
    //polymorphism in my words:
        //sayHi(studentOne) is pointing a Person object 1st and
        //then accesses a derived object bc the derived object
        //stems from the base class to begin with.
        cout << "hello " << p.getName() << endl;
    }
}; //close Person class.

class Student: public Person
{
private:
    float gpa;
public:
    Student(string n, int a, float g):Person(n, a)
    {
        gpa = g;
    }
    int getGPA()
    {
        return gpa;
    }
}; //close Student class.


int main()
{
    //1) create a simple Person object/variable:
    Person personOne("Moris", 24);
    cout << "personOne:" << endl;
    cout << personOne.getName() << ", ";
    cout << personOne.getAge() << endl;
    personOne.sayHi(personOne);
    //we have existing personOne object from Person class.
    //we call sayHi() on personOne object and pass that object.
    cout << "=================" << endl;
    
    //2) create a simple Student object/variable via Person base:
    Student studentOne("Ash", 22, 3.6);
    cout << "studentOne:" << endl;
    cout << studentOne.getName() << ", ";
    cout << studentOne.getAge() << ", ";
    cout << studentOne.getGPA() << endl;
    studentOne.sayHi(studentOne); //POLYMORPHISM:
    //accessing the studentOne derived object by a pointer //referencing the base class first.
    //although sayHi() is in the base class only...
    //the derived class inherits it.
    //we can pass both objects created from the base class.
    //and objects created from the derived clas.
    return 0;
}
