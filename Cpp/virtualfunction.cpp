// a type of run time polymorphism
//a membe function declared in base class but again overriden/redifined in derived class
//dynamic in nature
//https://www.learncpp.com/cpp-tutorial/the-virtual-table/


#include <iostream>
using namespace std;

class Base {

public:
	// virtual function
	virtual void display()
	{
		cout << "Called virtual Base Class function"
			<< "\n\n";
	}

	void print()
	{
		cout << "Called Base print function"
			<< "\n\n";
	}
};

// Declaring a Child Class
class Child : public Base {

public:
	void display()
	{
		cout << "Called Child Display Function"
			<< "\n\n";
	}

	void print()
	{
		cout << "Called Child print Function"
			<< "\n\n";
	}
};

int main()
{
    Base* base;
	Child child;

	base = &child;

	// This will call the virtual function
	base->Base::display();

	// this will call the non-virtual function
	base->print();
    return 0;
}
