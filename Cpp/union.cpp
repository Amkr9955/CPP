// user defined data type like structures and classes
// in union,all members share the biggest same memory location
// example for int ,short,char a 4 byte will be allocated and all three will point to this
// used to achieve polymorphism

// Possible Usage
// when we need only one value out of many that time we will use it
// get the actual data in parts

#include<iostream>
using namespace std;

union Square{
    int width;
    int height;
    
};

int getArea(int width1,int height1){
        return width1*height1;
}

int main(){
    Square sqr;
    sqr.width=10;
    cout << getArea(sqr.width,sqr.height)<<endl;
    return 0;
}