// Encapsulation in C++ is defined as the wrapping up of data and information in a single unit. 
// In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.

// Two Important  property of Encapsulation 

// Data Protection: Encapsulation protects the internal state of an object by keeping its data members private. Access to and modification of these data members 
// is restricted to the class’s public methods, ensuring controlled and secure data manipulation.
// Information Hiding: Encapsulation hides the internal implementation details of a class from external code. Only the public interface of the class is accessible, providing abstraction and 
// simplifying the usage of the class while allowing the internal implementation to be modified without impacting external code.

// Features of Encapsulation
// Below are the features of encapsulation:

// We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class. 
// The function which we are making inside the class must use only member variables, only then it is called encapsulation.
// If we don’t make a function inside the class which is using the member variable of the class then we don’t call it encapsulation.
// Encapsulation improves readability, maintainability, and security by grouping data and methods together.
// It helps to control the modification of our data members.

#include<iostream>
using namespace std;

class Encapsulation{
    
    private: 
    int x;                       //data hidden
    
    public:

    void set(int a){
        x=a;
    }

    int get(){
        return x;
    }

};

int main(){
    Encapsulation en;
    en.set(10);
    cout<<en.get()<<endl;
    return 0;
}