// Data abstraction is one of the most essential and important features of object-oriented programming
// in C++. Abstraction means displaying only essential information and hiding the details. Data
// abstraction refers to providing only essential information about the data to the outside world, hiding
// the background details or implementation. 

// Types of Abstraction:
// Data abstraction – This type only shows the required information about the data and hides the unnecessary data.
// Control Abstraction – This type only shows the required information about the implementation and hides unnecessary information.

//abstraction using class and access specifiers
//another example is abstraction using header files like math.h-pow()

// Advantages of Data Abstraction
// Helps the user to avoid writing the low-level code
// Avoids code duplication and increases reusability.
// Can change the internal implementation of the class independently without affecting the user.
// Helps to increase the security of an application or program as only important details are provided to the user.
// It reduces the complexity as well as the redundancy of the code, therefore increasing the readability.


// working of Abstraction
#include <iostream>
using namespace std;

class implementAbstraction {
private:
	int a, b;

public:
	void set(int x, int y)
	{
		a = x;
		b = y;
	}

	void display()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
};

int main()
{
	implementAbstraction obj;
	obj.set(10, 20);
	obj.display();
	return 0;
}

