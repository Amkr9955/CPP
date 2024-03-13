// C malloc() method

// The “malloc” or “memory allocation” method in C is used to dynamically 
// allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. 
// It doesn’t Initialize memory at execution time so that it has initialized each block with the default garbage value initially. 
// ptr = (int*) malloc(100 * sizeof(int));
// Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.
//  If space is insufficient, allocation fails and returns a NULL pointer.

// C calloc() method
// “calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory of the specified type.
// it is very much similar to malloc() but has two different points and these are:
// It initializes each block with a default value ‘0’.
// It has two parameters or arguments as compare to malloc().
// ptr = (cast-type*)calloc(n, element-size);
// here, n is the no. of elements and element-size is the size of each element.

// C free() method
// “free” method in C is used to dynamically de-allocate the memory. The memory allocated using functions malloc() and calloc() is not de-allocated on their own. 
// Hence the free() method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.
// free(ptr);

//C realloc() method
// “realloc” or “re-allocation” method in C is used to dynamically change the memory allocation of a previously allocated memory. 
// In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory.
//  re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.
// ptr = realloc(ptr, newSize);
// where ptr is reallocated with new size 'newSize'.
// If space is insufficient, allocation fails and returns a NULL pointer.