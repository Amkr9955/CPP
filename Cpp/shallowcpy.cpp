// an object is created by simply copying the data of all variables of the original object
// This works well if none of the variables of the object are defined in the heap section of memory.
// If some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location
// This will create ambiguity and run-time errors, dangling pointer. Since both objects will reference to the same memory location, then change made by one will reflect those change in another object as well. 
// default copy constructor does shallow copy.
// copies reference to object data

#include<iostream>
using namespace std;

class shallow{
    int x;
    int y;
    int z;
    public:

    void set(int x1,int x2,int x3){
        x=x1;
        y=x2;
        z=x3;
    }
    void print(){
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
};
int main(){
   
    shallow B1, B3;
 
    
    B1.set(14, 12, 16);
    B1.print();
 
    // When copying the data of object
    // at the time of initialization
    // then copy is made through
    // COPY CONSTRUCTOR
    shallow B2 = B1;    
    B2.set(1,2,3);
    B2.print();
 
    // When copying the data of object
    // after initialization then the
    // copy is done through DEFAULT
    // ASSIGNMENT OPERATOR
    B3 = B1;           
    B3.print();

    
    return 0;
}