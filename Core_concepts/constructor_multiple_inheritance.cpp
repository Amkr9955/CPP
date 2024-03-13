// Constructor is a class member function with the same name as the class. 
// The main job of the constructor is to allocate memory for class objects. 
// Constructor is automatically called when the object is created. 

// Multiple Inheritance:

// Multiple Inheritance is a feature of C++ where a class can derive from several(two or more) base classes. The constructors of inherited classes are called in the same order in which they are inherited.
// C++ program to implement
// constructor in multiple 
// inheritance
#include<iostream>
using namespace std;
class A1
{
public:
A1()
{
	cout << "Constructor of the base class A1 \n";
}

};

class A2
{
public:
A2()
{
	cout << "Constructor of the base class A2 \n";
}

};

class S: public A1, virtual A2
{
public:
S(): A1(), A2()
{
	cout << "Constructor of the derived class S \n";
}
};

// Driver code
int main()
{
S obj;
return 0;
}

//output
// Constructor of the base class A2 
// Constructor of the base class A1 
// Constructor of the derived class S 
