
#include <iostream>
using namespace std;

class overload {
private:
	int count;

public:
	overload()
		: count(4)
	{
	}

	void operator++() { count = count + 1; }
	void Display() { cout << "Count: " << count; }
};

int main()
{
	overload i;
	// this calls "function void operator ++()" function
	++i;
	i.Display();
	return 0;
}
// This function is called when the ++ operator operates on the object of the overload class (object i in this case).
//  In the program, void operator ++ () operator function is defined (inside overload class). 
//  This function increments the value of count by 1 for i object.
// important:functional overloading does not work in inheritance but it works in JAVA
