#include <iostream>
#include <stack>
#include <sstream>


using namespace std;

//Write a C++ Program to reverse the words in a sentence (use a stack or LIFO structure)
string reverseWords(string sentence){
    //store each word in an array
    stack<string> words; //we will push each word onto the stack
    string reversed = " "; //this is the reversed string we will return after reverse concatenation
    istringstream iss(sentence); //create a string stream called iss
    string word;
    
    //extract words from the stream and push them onto the stack
    while(iss >> word){
        words.push(word);
    }
    
    //and now pop them all out and reverse concatenate
    while(!words.empty()){
        reversed += words.top();
        words.pop();
        reversed += " "; //add a space in between the words
        //could also add an if above so that we only add spaces between the words if the stack is not empty
    }
    
    return reversed;
}

//Find the first non-recurring character in string. i.e. input "abbcdcaea" would return "d"
char firstNonRecurring(string str){
    unordered_map<char, int> charCount; //maps characters to integers
    
    for(char ch:str){ //iterate through all the characters in the string
        charCount[ch]++;
        if(charCount[ch] == 1){ //has a frequency of 1
            return charCount[ch];
        }
    }
    
    return '\0';
}

//Create a custom malloc and free function using linked lists

//Swap the values of two pointers without a temp variable

//Write a function that determines if a given variable is a power of 2 or not

// Function that takes a 2d array of a "sudoku board", and checks to make sure it is a possible board
 
// Find the smallest and largest number in an array of large elements.

//Write code to initialize a driver peripheral given a register map

//Write code to turn a timer with a 32 bit timer into a 64 bit timer

//Write a debouncing algorithm for a button

//Write code to manipulate raw memory locations and bits

//Write code to print out code using printf within an ISR. Assume that an RTOS is available


