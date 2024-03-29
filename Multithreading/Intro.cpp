//introduction to threading in c++(c++11)
// 0. In every application there is a default thread which is main(), in side this we create other threads.
// 1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
//    For example:
//    (a) The browser has multiple tabs that can be different threads. 
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

//if we create multiple threads at the same time it doesn't gaurantee which will start first

#include<iostream>
#include<thread>
#include<chrono>  //<chrono> provides three main types of clocks: system_clock, steady_clock, and high_resolution_clock
#include<algorithm>

using namespace std;
using namespace std::chrono;
typedef long long int ull;

void findEven(ull start, ull end, ull* EvenSum) {
	for (ull i = start; i <= end; ++i){
		if (!(i & 1)){
			*(EvenSum) += i;
		}
	}
}
 
void findOdd(ull start, ull end, ull* OddSum) {
	for (ull i = start; i <= end; ++i){
		if (i & 1){
			(*OddSum) += i;
		}
	}
}

int main() {
 
	ull start = 0, end = 1900000000;
 
	ull OddSum = 0;
	ull EvenSum = 0;
 
    auto startTime = high_resolution_clock::now(); 
 
	// // WITH THREAD
    std::thread t1(findEven, start, end, &(EvenSum));
    std::thread t2(findOdd, start, end, &(OddSum));
 
	t1.join(); //for joining the thread //here both thread are running in parallel
	t2.join();
 
	// // WITHOUT THREAD
	// findEven(start,end, &EvenSum);
	// findOdd(start, end, &OddSum);
    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);
 
	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;
 
	cout << "Sec: " << duration.count()/1000000 << endl;
 
	return 0;
}

// g++ -std=c++11 -pthread Intro.cpp //to create output
//output:
// OddSum : 902500000000000000
// EvenSum : 902500000950000000
// Sec: 17