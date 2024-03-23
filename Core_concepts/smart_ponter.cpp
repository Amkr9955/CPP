//1.smart pointer is a class which wraps a raw pointer, to manage the life time of a pointer
//2.the most fundamental job of smart pointer is to remove the chances of memory leak
//3.it makes sure that the object is deleted if it is not reference any more

//Types:

//1.unique_ptr:Allows only one owner of the underlying pointer
//2.shared_ptr:Allows multiple owners of the same pointer (Reference count is maintained)
//3.weak_ptr:it is special type of shared_ptr which doesn't count the reference

#include<iostream>
using namespace std;

class MyInt{
    public:
        explicit MyInt(int *p=nullptr){
            data =p;
        }
        ~MyInt(){
            delete data;
        }
        int& operator * () { return *data;}
        private:
            int *data;
};

int main(){
    int *p=new int(10);
    MyInt myint=MyInt(p);
    cout<< *myint<<endl;
    return 0;
}