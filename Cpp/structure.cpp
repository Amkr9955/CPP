//by default members are public
//Structure members cannot be initialized with declaration unlike class
//The reason for error is simple, when a datatype is declared, no memory is allocated for it. Memory is allocated only when variables are created.
//But is considered correct in C++11 and above. 

// Like other primitive data types, we can create an array of structures. 
//self referntial structures are one which uses pointers of same struct type 
// fro example linked list and tree,etc

#include <iostream>
using namespace std;

struct Point {
	int x, y;
};




int main()
{
	// Create an array of structures
	struct Point arr[10];

	// Access array members
	arr[0].x = 10;
	arr[0].y = 20;

	cout << arr[0].x << " " << arr[0].y<<endl;
	struct Point p1 = { 1, 2 };

	// p2 is a pointer to structure p1
	struct Point* p2 = &p1;
	cout << p2->x << " " << p2->y;
	

	return 0;
}

// What is a structure pointer? 
// Like primitive types, we can have pointer to a structure. 
// If we have a pointer to structure, members are accessed using arrow ( -> ) operator instead of the dot (.) operator.

