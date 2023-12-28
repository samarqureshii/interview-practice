// Implement a C function that takes a null-terminated string and returns a new heap-allocated null-terminated string 
// containing every other character from original string (e.g., “house” -> “hue”). 
#include <stdio.h>
char* strdup_every_other_char(const char* s) {
    //figure out how many letters in the string 

    int len = 0;
    while(s[len]!='\0'){
        len++; 
    }

    // fugure out the size for the new string
    int newSize = len / 2 + (len%2); 
    //if len%2 == 1, then there was an odd number so we need to add an extra letter since / operator rounds down

    char* newStr = (char*) malloc ((newSize+1) * sizeof(char)); //allocate string array 
    if(newStr == NULL){ //if there were no characters in the original string
        return NULL;
    }

    //now fill up newStr with every other letter from s
    int k = 0;
    for(int j = 0; j < len; j+=2){
        newStr[k] = s[j];
        k++;
    }

    //add the null termination char
    newStr[newSize] = '\0';
    
    return newStr;
    //free the memory in the main to avoid memory leaks
}
