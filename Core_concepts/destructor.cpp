// Notes:
// 1. This is a special member function with same name as class with ~ at front.
// 2. Used to destruct the memory of object which was constructed by constructor.
// 3. Destructors get called automatically(implicit call),as constructor was.
// 4. We can call destructors explicitly but that is not good practice.
// 5.The only place where we can call destructors explicitly is after placement of new.
//6.destructors with access modifiers as private is known as Private Destructors

#include<iostream>
using namespace std;

class Base{
    int x;
    public:
    Base(){ cout<<"D constructor"<<endl;}
    Base(int a):x{a} { cout <<"p constructor"<<endl;}
    ~Base(){
        cout<<"Destructor" <<endl;
    }
};

int main(){
    Base(10);
    return 0;
}