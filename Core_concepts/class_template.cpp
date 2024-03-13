// Class Templates 
// Class templates like function templates, class templates are useful when a class defines something that is independent of the data type. 
// Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 

#include<iostream>
using namespace std;

//class 
template<typename T> class Array{

 private:
 T* ptr;
 int size;

 public:
 Array(T arr[],int s);
 void print();
};

template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
 
template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}
 
// Can there be more than one argument for templates? 
// Yes, like normal parameters, we can pass more than one data type as arguments to templates. 

// Can we specify a default value for template arguments? 
// Yes, like normal parameters, we can specify default arguments to templates.

// What happens when there is a static member in a template class/function? 
// Each instance of a template contains its own static variable.

int main(){
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}