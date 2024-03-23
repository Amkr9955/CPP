// The source code written by programmers is first stored in a file, 
// let the name be “program.c“. 
// This file is then processed by preprocessors and an expanded source code file is generated named “program.i”. 
// This expanded file is compiled by the compiler and an object code file is generated named “program.obj”. 
// Finally, the linker links this object code file to the object code of the library functions to generate the executable file “program.exe”. 

// Preprocessor Directives in C
// Preprocessor programs provide preprocessor directives that tell the compiler to preprocess the source code before compiling. 
// All of these preprocessor directives begin with a ‘#’ (hash) symbol. 
// The ‘#’ symbol indicates that whatever statement starts with a ‘#’ will go to the preprocessor program to get executed. 
// We can place these preprocessor directives anywhere in our program.
// Remember that the # symbol only provides a path to the preprocessor, and a command such as include is processed by the preprocessor program.

// Preprocessor Directives	
// Description

// #define
// Used to define a macro

// #undef
// Used to undefine a macro

// #include
// Used to include a file in the source code program

// #ifdef
// Used to include a section of code if a certain macro is defined by #define

// #ifndef
// Used to include a section of code if a certain macro is not defined by #define

// #if
// Check for the specified condition

// #else
// Alternate code that executes when #if fails

// #endif
// Used to mark the end of #if, #ifdef, and #ifndef

// There are 4 Main Types of Preprocessor Directives:  

// Macros
// File Inclusion
// Conditional Compilation
// Other directives

// C Program to illustrate the macro
// 1. File Inclusion
// This type of preprocessor directive tells the compiler to include a file in the source code program. 
// The #include preprocessor directive is used to include the header files in the C program.
#include <stdio.h>

// 2. Other Directives 
// Apart from the above directives, there are two more directives that are not commonly used. These are:



// #pragma Directive:This directive is a special purpose directive and is used to turn on or off some features. These types of directives are compiler-specific, i.e., 
// they vary from compiler to compiler.
// Some of the #pragma directives are discussed below: 

// #pragma startup: These directives help us to specify the functions that are needed to run before program startup (before the control passes to main()).
// #pragma exit: These directives help us to specify the functions that are needed to run just before the program exit (just before the control returns from main()).
void func1();
void func2();
 
// specifying funct1 to execute at start
#pragma startup func1
// specifying funct2 to execute before end
#pragma exit func2
 
void func1() { printf("Inside func1()\n"); }
 
void func2() { printf("Inside func2()\n"); }

// #undef Directive:The #undef directive is used to undefine an existing macro.
// defining MIN_VALUE
 #define MIN_VALUE 10
 

// 3. Macros(standard and user header files)
// In C, Macros are pieces of code in a program that is given some name. 
// Whenever this name is encountered by the compiler, the compiler replaces the name with the actual piece of code. 
// The ‘#define’ directive is used to define a macro.
// macro definition
#define LIMIT 5
 // macro with parameter
#define AREA(l, b) (l * b)

// 4. Conditional Compilation
// Conditional Compilation in C directives is a type of directive that helps to compile a specific portion of the program or to skip the compilation of some specific part of the program based on some conditions. 
// There are the following preprocessor directives that are used to insert conditional code:
// defining PI
#define PI 3.14159



int main()
{   
    void func1();
    void func2();
    printf("Inside main()\n");

    for (int i = 0; i < LIMIT; i++) {
        printf("%d \n", i);
    }
 
    
    int l1 = 10, l2 = 5, area;
 
    area = AREA(l1, l2);
 
    printf("Area of rectangle is: %d", area);

       
#ifdef PI
    printf("PI is defined\n");
   
#elif defined(SQUARE)
    printf("Square is defined\n");
#else
    #error "Neither PI nor SQUARE is defined"
#endif
   
#ifndef SQUARE
    printf("Square is not defined"); 
#else
    cout << "Square is defined" << endl;
#endif
 
 printf("Min value is: %d\n",MIN_VALUE);
   
//undefining max value   
#undef MIN_VALUE
   
// again redefining MIN_VALUE  
#define MIN_VALUE 20
 
    printf("Min value after undef and again redefining it: %d\n", MIN_VALUE);


    return 0;
}
// since gcc doesn't support pragma startup and exit alternate code could be used

   
// #include <stdio.h>
 
// void func1();
// void func2();
 
// void __attribute__((constructor)) func1();
// void __attribute__((destructor)) func2();
 
// void func1()
// {
//     printf("Inside func1()\n");
// }
 
// void func2()
// {
//     printf("Inside func2()\n");
// }
 
// int main()
// {
//     printf("Inside main()\n");
 
//     return 0;
// }

// #pragma warn Directive
// This directive is used to hide the warning message which is displayed during compilation. We can hide the warnings as shown below: 

// #pragma warn -rvl: This directive hides those warnings which are raised when a function that is supposed to return a value does not return a value.
// #pragma warn -par: This directive hides those warnings which are raised when a function does not use the parameters passed to it.
// #pragma warn -rch: This directive hides those warnings which are raised when a code is unreachable. For example, any code written after the return statement in a function is unreachable.