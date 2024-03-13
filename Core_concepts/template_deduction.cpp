// Template Argument Deduction
// Template argument deduction automatically deduces the data type of the argument passed to the class or function templates. 
// This allows us to instantiate the template without explicitly specifying the data type.

// For example, consider the below function template to multiply two numbers:

// template <typename t>
// t multiply (t num1,t num2) { return num1*num2; }


// In general, when we want to use the multiply() function for integers, we have to call it like this:

// multiply<int> (25, 5);

// But we can also call it:

// multiply(23, 5);
// We don’t explicitly specify the type ie 1,3 are integers.

// The same is true for the template classes(since C++17 only). Suppose we define the template class as:

// template<typename t>
// class student{
//     private:
//        t total_marks;
//     public:
//        student(t x) : total_marks(x) {}
// };

// If we want to create an instance of this class, we can use any of the following syntax:

// student<int> stu1(23);
//     or
// student stu2(24);

// C++ Program to illustrate template arguments deduction in
// STL

// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
// 	// creating a vector<float> object without specifying
// 	// type
// 	vector v1{ 1.1, 2.0, 3.9, 4.909 };
// 	cout << "Elements of v1 : ";
// 	for (auto i : v1) {
// 		cout << i << " ";
// 	}

// 	// creating a vector<int> object without specifying type
// 	vector v2{ 1, 2, 3, 4 };
// 	cout << endl << "Elements of v2 : ";
// 	for (auto i : v2) {
// 		cout << i << " ";
// 	}
//     return 0;
// }

// Note: The above program will fail compilation in C++14 and below compiler since class template arguments deduction was added in C++17.
// The class template argument deduction was added in C++17 and has since been part of the language. 
// It allows us to create the class template instances without explicitly definition the types just like function templates.
