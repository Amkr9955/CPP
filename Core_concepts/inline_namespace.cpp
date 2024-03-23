// In C++, namespaces can be nested, and the resolution of namespace variables is hierarchical. An inline namespace is a namespace that uses the optional keyword inline in its original-namespace definition. 
// This allows the identifiers of the nested inline namespace to behave as if they are the identifier of the parent/enclosing namespace.

// C++ program to demonstrate working of 
// inline namespaces inside inline namespaces 

#include <iostream> 
using namespace std; 

namespace ns1 { 
inline namespace ns2 { 
	inline namespace ns3 { 
		int var = 10; 
	} 
} // namespace ns2 
} // namespace ns1 

int main() 
{ 
	cout << ns1::var; 
	return 0; 
}


// output
// 10

// Advantages of using inline namespaces
// 1. Avoid verbose: Consider the above code, if you want to print “var”, you write: 

// cout << ns1::ns2::ns3::var;
// 2. This looks good only if the namespace’s names are short as in the above example. But by using inline with namespaces there is no need to type the entire namespace as given above or use the “using” directive.

// 3. Support of Library: The inline namespace mechanism is intended to support library evolution by providing a mechanism that supports a form of versioning.  