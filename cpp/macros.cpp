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

void main(){
    cout << "Hello world!";
}