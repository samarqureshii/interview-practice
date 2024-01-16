//seconds in a year macro
#define SECONDS_PER_YEAR (60UL * 60UL * 24UL * 365UL)
//UL bc of overflow in a 16 bit machine 

//standard MIN macro
#define MIN(A,B) (A<=B ? (A) : (B))

//standard max macro 
#define MAX(a,b) (a>=b ? (a) : (b))

using namespace std;
#include <string>
#include <iostream>

void macros(){
    cout << "Hello world!" << endl;
}


//You are tasked with creating a macro in C or C++ that swaps the values of two variables. The macro should be generic enough to handle different data types.

#define SWAP(a,b,type) do{ \
type temp = a;
a =b \
b = temp\
\
} while(0)
