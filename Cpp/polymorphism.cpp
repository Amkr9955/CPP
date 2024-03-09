//different forms or output of same piece of code or operator
//2 types : compile time and run time
#include <bits/stdc++.h>
 
using namespace std;
// compile time has :
// function overloading -same function with different arguments to generate different output

class Geeks {
public:
    // Function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }
 
    // Function with same name but
    // 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }
 
    // Function with same name and
    // 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y
             << endl;
    }

};

// operator overloading -like '+' operator which in case of strings concate and for int adds the value

class Complex {
private:
    int real, imag;
 
public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
 
    // This is automatically called
    // when '+' is used with between
    // two Complex objects
    Complex operator+(Complex const& obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};
 

//run time-function Overriding:occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
// Runtime Polymorphism cannot be achieved by data members in C++.
class Animal {
public:
    string color = "Black";
};
 
// inheriting Animal class.
class Dog : public Animal {
public:
    string color = "Grey";
};//Dog.color would be black
// parent class reference will always refer to the data member of the parent class.

int main()
{

    return 0;
}