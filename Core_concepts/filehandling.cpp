// File handling is used to store data permanently in a computer. Using file handling we can store our data in secondary memory (Hard disk).
// How to achieve the File Handling
// For achieving file handling we need to follow the following steps:-
//  STEP 1-Naming a file
//  STEP 2-Opening a file
//  STEP 3-Writing data into the file
//  STEP 4-Reading data from the file
//  STEP 5-Closing a file.

// Streams in C++ :-
// We give input to the executing program and the execution program gives back the output. The sequence of bytes given as input to the executing program and the sequence of bytes that comes as output from the executing program are called stream. 
// In other words, streams are nothing but the flow of data in a sequence.

// The input and output operation between the executing program and the devices like keyboard and monitor are known as “console I/O operation”. The input and output operation between the executing program and files are known as “disk I/O operation”.

// Classes for File stream operations :-
// The I/O system of C++ contains a set of classes which define the file handling methods. 
// These include ifstream, ofstream and fstream classes. These classes are derived from fstream and from the corresponding iostream class. 
// These classes, designed to manage the disk files, are declared in fstream and therefore we must include this file in any program that uses files.

#include <fstream>
#include <iostream>
#include <string>


int main()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1\n";
    outf << "This is line 2\n";

    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    std::string strInput{};
    while (inf >> strInput)
        std::cout << strInput << '\n';

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}

// Buffered output

// Output in C++ may be buffered. This means that anything that is output to a file stream may not be written to disk immediately. 
// Instead, several output operations may be batched and handled together. 
// This is done primarily for performance reasons. 
// When a buffer is written to disk, this is called flushing the buffer. 
// One way to cause the buffer to be flushed is to close the file -- the contents of the buffer will be flushed to disk, and then the file will be closed.

// Buffering is usually not a problem, but in certain circumstance it can cause complications for the unwary. 
// The main culprit in this case is when there is data in the buffer, and then program terminates immediately (either by crashing, or by calling exit()). 
// In these cases, the destructors for the file stream classes are not executed, which means the files are never closed, which means the buffers are never flushed. 
// In this case, the data in the buffer is not written to disk, and is lost forever. 
// This is why it is always a good idea to explicitly close any open files before calling exit().

// It is possible to flush the buffer manually using the ostream::flush() function or sending std::flush to the output stream. 
// Either of these methods can be useful to ensure the contents of the buffer are written to disk immediately, just in case the program crashes.