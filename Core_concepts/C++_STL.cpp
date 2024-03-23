// The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. 
// It is a library of container classes, algorithms, and iterators. 
// It is a generalized library and so, its components are parameterized. Working knowledge of template classes is a prerequisite for working with STL.

// The C++ Standard Template Library (STL) is a collection of algorithms, data structures, and other components that can be used to simplify the development of C++ programs. 
// The STL provides a range of containers, such as vectors, lists, and maps, as well as algorithms for searching, sorting and manipulating data.

// One of the key benefits of the STL is that it provides a way to write generic, reusable code that can be applied to different data types. 
// This means that you can write an algorithm once, and then use it with different types of data without having to write separate code for each type.

// STL has 4 components:

// 1. Algorithms
// The header algorithm defines a collection of functions specially designed to be used on a range of elements. They act on containers and provide means for various operations for the contents of the containers.

// Algorithm
//  Sorting
//  Searching
//  Important STL Algorithms
//  Useful Array algorithms
//  Partition Operations
// Numeric
//  valarray class

// 2. Containers
// Containers or container classes store objects and data. There are in total seven standards “first-class” container classes and three container adaptor classes and only seven header files that provide access to these containers or container adaptors.

// Sequence Containers: implement data structures that can be accessed in a sequential manner.
// vector
// list
// deque
// arrays
// forward_list( Introduced in C++11)
// Container Adaptors: provide a different interface for sequential containers.
// queue
// priority_queue
// stack
// Associative Containers: implement sorted data structures that can be quickly searched (O(log n) complexity).
// set
// multiset
// map
// multimap
// Unordered Associative Containers: implement unordered data structures that can be quickly searched
// unordered_set (Introduced in C++11)
// unordered_multiset (Introduced in C++11)
// unordered_map (Introduced in C++11)
// unordered_multimap (Introduced in C++11)

// 3. Functors
// The STL includes classes that overload the function call operator. 
// Instances of such classes are called function objects or functors. 
// Functors allow the working of the associated function to be customized with the help of parameters to be passed. 

// 4. Iterators
// As the name suggests, iterators are used for working on a sequence of values. 
// They are the major feature that allows generality in STL.