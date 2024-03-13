// The capability of a class to derive properties and characteristics from another class is called Inheritance
// Sub Class: The class that inherits properties from another class is called Subclass or Derived Class. 
// Super Class: The class whose properties are inherited by a subclass is called Base Class or Superclass

// Example:

// 1. class ABC : private XYZ              //private derivation
//             {                }
// 2. class ABC : public XYZ              //public derivation
//             {               }
// 3. class ABC : protected XYZ              //protected derivation
//             {              }
// 4. class ABC: XYZ                            //private derivation by default
// {            }

// o When a base class is privately inherited by the derived class, public members of the base class becomes the private members of the derived class and therefore,
//  the public members of the base class can only be accessed by the member functions of the derived class. They are inaccessible to the objects of the derived class.
// o On the other hand, when the base class is publicly inherited by the derived class, public members of the base class also become the public members of the derived class.
//  Therefore, the public members of the base class are accessible by the objects of the derived class as well as by the member functions of the derived class.

// Modes of Inheritance: There are 3 modes of inheritance.

// Public Mode: If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.
// Protected Mode: If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become protected in the derived class.
// Private Mode: If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become Private in the derived class.

#include<iostream>
using namespace std;

class Person{
    int id;
    char name[100];
    
    public:
    void set_p(){
        cout<<"Enter id"<<" ";
        cin>>id;
        cout<<endl;
        cout<<"Enter the name"<<" ";
        cin>>name;
        cout<<endl;
    }
    void print_p(){
        cout<<"ID:"<<id<<endl<<"Name:"<<name<<endl;
    }

};

class Student: private Person{ 
    char course[50];
    int fee;
 
public:
    void set_s()
    {
        set_p();
        cout << endl<<"Enter the Course Name:";
        cin >> course;
        cout << endl<<"Enter the Course Fee:";
        cin >> fee;
    }
 
    void print_s()
    {
        print_p();
        cout <<endl<<"Course: "<< course << "\nFee: " << fee << endl;
    }
};

int main(){
    Student s;
    s.set_s();
    s.print_s();
    return 0;
}