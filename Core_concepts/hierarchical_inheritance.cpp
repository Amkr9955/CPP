// In Hierarchical inheritance, more than one sub-class inherits the property of a single base class. 
// There is one base class and multiple derived classes. 
// Several other classes inherit the derived classes as well. 
// Hierarchical structures thus form a tree-like structure. 
// It is similar to that, mango and apple both are fruits; both inherit the property of fruit. Fruit will be the Base class, and mango and apple are sub-classes. 


#include<iostream> 
using namespace std; 

class A //superclass A 
{ 
public: 
void show_A() { 
	cout<<"class A"<<endl; 
} 
}; 
class B : public A //subclass B 
{ 
public: 
void show_B() { 
	cout<<"class B"<<endl; 
} 
}; 

class C : public A //subclass C 
{ 
public: 
void show_C() { 
	cout<<"class C"<<endl; 
} 
}; 

int main() { 
B b; // b is object of class B 
cout<<"calling from B: "<<endl; 
b.show_B(); 
b.show_A(); 
	
C c; // c is object of class C 
cout<<"calling from C: "<<endl; 
c.show_C(); 
c.show_A(); 
return 0; 
} 

