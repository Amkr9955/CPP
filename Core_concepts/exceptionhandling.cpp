// In C++, exceptions are runtime anomalies or abnormal conditions that a program encounters during its execution. 
// The process of handling these exceptions is called exception handling.
// Using the exception handling mechanism, the control from one part of the program where the exception occurred can be transferred to another part of the code.
// So basically using exception handling in C++, we can handle the exceptions so that our program keeps running.

//Types of exceptions in c++
// Synchronous: Exceptions that happen when something goes wrong because of a mistake in the input data or when the program is not equipped to handle the current type of data it’s working with, such as dividing a number by zero.
// Asynchronous: Exceptions that are beyond the program’s control, such as disc failure, keyboard interrupts, etc.

// C++ provides an inbuilt feature for Exception Handling

// 1. try in C++
// The try keyword represents a block of code that may throw an exception placed inside the try block. It’s followed by one or more catch blocks. If an exception occurs, try block throws that exception.

// 2. catch in C++
// The catch statement represents a block of code that is executed when a particular exception is thrown from the try block. The code to handle the exception is written inside the catch block.

// 3. throw in C++
// An exception in C++ can be thrown using the throw keyword. When a program encounters a throw statement, then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.

// C++ program to demonstate the use of try,catch and throw
// in exception handling.

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{

	// try block
	try {
		int numerator = 10;
		int denominator = 0;
		int res;

		// check if denominator is 0 then throw runtime
		// error.
		if (denominator == 0) {
			throw runtime_error(
				"Division by zero not allowed!");
		}

		// calculate result if no exception occurs
		res = numerator / denominator;
		//[printing result after division
		cout << "Result after division: " << res << endl;
	}
	// catch block to catch the thrown exception
	catch (const exception& e) {
		// print the exception
		cout << "Exception " << e.what() << endl;
	}

	return 0;
}


// Limitations of Exception Handling in C++
// The exception handling in C++ also have few limitations:

// Exceptions may break the structure or flow of the code as multiple invisible exit points are created in the code which makes the code hard to read and debug.
// If exception handling is not done properly can lead to resource leaks as well.
// It’s hard to learn how to write Exception code that is safe.
// There is no C++ standard on how to use exception handling, hence many variations in exception-handling practices exist.