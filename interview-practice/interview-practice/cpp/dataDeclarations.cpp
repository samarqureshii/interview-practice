#include <iostream>
#include <string>

void dataDeclarations(){
//    (a) An integer
    int a;
//
//    (b) A pointer to an integer
    int *a_p;
//
//    (c) A pointer to a pointer to an integer
    int **a_pp;
//
//    (d) An array of ten integers
    int arr [10];
//
//    (e) An array of ten pointers to integers
    int* arr_p[10];
//
//    (f) A pointer to an array of ten integers
    int (*arr_p)[10];
//
//    (g) A pointer to a function that takes an integer as an argument and returns an integer
    int (*a)(int);
//
//    (h) An array of ten pointers to functions that take an integer argument and return an integer.
    int (*a[10]) (int);
}
