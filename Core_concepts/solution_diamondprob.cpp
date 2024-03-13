// In the diamond problem program, constructor of ‘Person’ is called two times. Destructor of ‘Person’ will also be called two times when object ‘ta1’ is destructed. 
// So object ‘ta1’ has two copies of all members of ‘Person’, this causes ambiguities. The solution to this problem is ‘virtual’ keyword. 
// We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class.

#include<iostream>
using namespace std;
class Person {
public:
	Person(int x) { cout << "Person::Person(int ) called" << endl; }
	Person()	 { cout << "Person::Person() called" << endl; }
};

class Faculty : virtual public Person {
public:
	Faculty(int x):Person(x) {
	cout<<"Faculty::Faculty(int ) called"<< endl;
	}
};

class Student : virtual public Person {
public:
	Student(int x):Person(x) {
		cout<<"Student::Student(int ) called"<< endl;
	}
};

class TA : public Faculty, public Student {
public:
	TA(int x):Student(x), Faculty(x) {
		cout<<"TA::TA(int ) called"<< endl;
	}
};

int main() {
	TA ta1(30);
}
//output
// Person::Person() called
// Faculty::Faculty(int ) called
// Student::Student(int ) called
// TA::TA(int ) called

// In the above program, constructor of ‘Person’ is called once. 
// One important thing to note in the above output is, the default constructor of ‘Person’ is called. 
// When we use ‘virtual’ keyword, the default constructor of grandparent class is called by default even if the parent classes explicitly call parameterized constructor.

// How to call the parameterized constructor of the ‘Person’ class?
// The constructor has to be called in ‘TA’ class.

// class TA : public Faculty, public Student  {
// public:
//     TA(int x):Student(x), Faculty(x), Person(x)   {
//         cout<<"TA::TA(int ) called"<< endl;
//     }
// };

// In general, it is not allowed to call the grandparent’s constructor directly, it has to be called through parent class. It is allowed only when ‘virtual’ keyword is used.