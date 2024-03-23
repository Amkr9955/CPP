// Extending namespaces (Using same name twice) 
// It is also possible to create two namespace blocks having the same name. 
// The second namespace block is nothing but actually the continuation of the first namespace. 
// In simpler words, we can say that both the namespaces are not different but actually the same, which are being defined in parts.

// C++ program to demonstrate namespace extension
#include <iostream>
using namespace std;

// first name space
namespace first 
{ 
int val1 = 500; 
}

// rest part of the first namespace
namespace first 
{ 
int val2 = 501; 
}

int main()
{
cout << first::val1 <<"\n";	 
cout << first::val2 <<"\n"; 
return 0;
}

// Output: 
 
// 500
// 501