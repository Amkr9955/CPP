// Namespace provide the space where we can define or declare identifier i.e. variable,  method, classes.
// Using namespace, you can define the space or context in which identifiers are defined i.e. variable, method, classes. 
// In essence, a namespace defines a scope.
// Advantage of Namespace to avoid name collision.
// Example, you might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). 
// Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.
// A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries. 
// The best example of namespace scope is the C++ standard library (std) where all the classes, methods and templates are declared. Hence while writing a C++ program we usually include the directive using namespace std;

// Definition and Creation: Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. 
// This allows organizing the elements of programs into different logical scopes referred to by names. Namespaces provide the space where we can define or declare identifiers i.e. names of variables, methods, classes, etc.

// A namespace is a feature added in C++ and is not present in C.
// A namespace is a declarative region that provides a scope to the identifiers (names of functions, variables or other user-defined data types) inside it.
// Multiple namespace blocks with the same name are allowed. All declarations within those blocks are declared in the named scope.

#include <iostream>
using namespace std;
// first name space
namespace first_space
{
void func()
{
	cout << "Inside first_space" << endl;
}
}

// second name space
namespace second_space
{
void func()
{
	cout << "Inside second_space" << endl;
}
}
using namespace first_space;
int main ()
{
// This calls function from first name space.
func();
return 0;
}

// Output
// Inside first_space