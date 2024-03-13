//Consider a function that takes only one argument. 
// However, while calling this function we have a lot more information that we would like to pass to this function, but we cannot as it accepts only one parameter.
//  What can be done?
// Functors are objects that can be treated as though they are a function or function pointer.

// A C++ program uses transform() in STL to add 
// 1 to all elements of arr[]
#include <bits/stdc++.h>
using namespace std;

int increment(int x) { return (x+1); }

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	// Apply increment to all elements of
	// arr[] and store the modified elements
	// back in arr[]
	transform(arr, arr+n, arr, increment);

	for (int i=0; i<n; i++)
		cout << arr[i] <<" ";

	return 0;
}
