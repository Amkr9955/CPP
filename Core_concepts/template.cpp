// A template is a simple yet very powerful tool in C++. 
// The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. 
// For example, a software company may need to sort() for different data types. 
// Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter. 

// C++ adds two new keywords to support templates: ‘template’ and ‘type name’. 
// The second keyword can always be replaced by the keyword ‘class’.

//syntax
// template <class T>
// <return-type> <function-name> (  <parameters of type T> )
// {
//                  //function body
// }
// Where
// template   ------    keyword
// class T     ------    template type parameter enclosed within a pair of angle brackets(< >) called generic dt.

#include<iostream>
using namespace std;

template<typename T>T myMax(T x,T y)
{
    return (x>y)? x:y;
}

int main(){
    cout<<myMax<int>(1,2)<<endl;
    cout<<myMax<char>('a','d')<<endl;
    return 0;
}