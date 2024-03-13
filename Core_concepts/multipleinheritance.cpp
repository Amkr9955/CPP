// 2. Multiple Inheritance: Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one subclass is inherited from more than one base class.
#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"This is base class1"<<endl;
    }
};

class B{
    public:
    B(){
        cout<<"This is base class2"<<endl;
    }
};

class C: public A,public B{
    public:
    C(){
        cout<<"This is derived class of base A and B"<<endl;

    }
};
int main(){
    C c;
    return 0;
}