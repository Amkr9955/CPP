//1.This pointer is used to hold the address of current object(
// using which we have called particular member function)
//2.this pointer is const pointer
//3.this pointer is passed as a hidden argument to non-static member function
//4.compiler automatically changes all data member access with this pointer
//5.it is not passed in static data member function

#include<iostream>
using namespace std;

class Base{
    int x;

    public:
    Base(){}
    Base(int a){x=a;}    //turns into this->x=a;

    int get(){
        return this->x;
        }
    void set(int a){this->x=a;}
};

int main(){
    Base b1;
    Base b2(10);
    cout<<b2.get()<<endl;
    b2.set(20);
    cout<<b2.get()<<endl;


    return 0;
}