# interview-practice
Interview prep/questions for firmware/embedded roles.
## General knowledge
- Be able to explain why C++ could be a problem in embedded systems (and how to deal with it)
- Be able to explain why compiler optimization can cause problems and what the fix is
- Be able to explain the difference between an RTOS and other kinds of OSes
- Be able to explain what should and what should not be in an interrupt handler
- Be able to talk about approaches to testing, unity tests, integration testing, etc
- Learn about MISRA and why it helps embedded code
## Bit manipulation 
- Use left shift when you want to multiply by a power of two, set specific bits, or construct a larger value from smaller components.
-Use logical right shift for similar reasons as left shift but in the opposite direction (like division by powers of two) and for unsigned numbers.
- Use arithmetic right shift when working with signed numbers, especially when you want to maintain the sign while performing operations akin to division.
---
- **Setting a Bit**:
    - Use the OR operator (**`|`**) to set a particular bit.
    - Example: **`num |= 1 << x;`** sets the **`x`**th bit of **`num`**.
- **Clearing a Bit**:
    - Use the AND operator (**`&`**) with NOT (**`~`**) to clear a bit.
    - Example: **`num &= ~(1 << x);`** clears the **`x`**th bit of **`num`**.
- **Toggling a Bit**:
    - Use the XOR operator (**`^`**) to toggle a bit.
    - Example: **`num ^= 1 << x;`** toggles the **`x`**th bit of **`num`**.
- **Checking a Bit**:
    - Use the AND operator to check the value of a bit.
    - Example: **`if (num & (1 << x))`** checks if the **`x`**th bit of **`num`** is set.
- **Changing the Value of a Bit to 1 or 0**:
    - Combining setting and clearing operations.
    - Example: **`num = (num & ~(1 << x)) | (val << x);`** changes the **`x`**th bit of **`num`** to **`val`** (1 or 0).
- **Extracting a Subset of Bits**:
    - Use bit shifting (**`>>`**) and masking (**`&`**).
    - Example: **`(num >> p) & ((1 << n) - 1)`** extracts **`n`** bits starting from position **`p`**.
- **Counting the Number of Set Bits**:
    - Use a loop and shift/right-shift operators, or Brian Kernighan’s Algorithm.
    - Example of simple method: **`while (num) { count += num & 1; num >>= 1; }`**
- **Least Significant Bit (LSB) and Most Significant Bit (MSB)**:
    - LSB: **`num & 1`**.
    - MSB: Depends on the size of the data type, typically involves shifting.
- **Bit Masking**:
    - Using AND, OR, XOR operations with a mask to manipulate or check specific bits.
    - Example: **`maskedNum = num & mask;`** where **`mask`** is a binary number.
- **Endianness Conversion**:
    - Sometimes, you may need to convert between little-endian and big-endian representations.
    - Example: Swapping bytes of a 16-bit, 32-bit, or 64-bit number.
- **Circular Shift or Bit Rotation**:
    - Left or right rotate bits of a number.
    - Example: **`num = (num << shift) | (num >> (sizeof(num) * CHAR_BIT - shift));`** for left rotate.
---
- `&` with bit mask to extract digits 
- `num |= << bitPosition` to set a bit
- `num &= ~(1 << bitPosition)` to clear a bit 
- `num ^= 1 << bitPosition` to toggle a bit 
- `if ((num & (1 << i)))` checks if the `i`th bit is set 
    - `(1 << i)` will give us `0001`, `0010`, `0100`, and so on for each iteration
    - We then compare it against the original number, if the result is non 0 (true), then we know that the `i`th bit is set

## Multithreading
- `lock_guard()`
- `unique_lock()` so that we can unlock and lock one thread if it is dependent on another (good for CPU efficiency)

## Common Data Structures
### Queues (FIFO)
- `empty()`	Returns whether the queue is empty. It return true if the queue is empty otherwise returns false.
- `size()`	Returns the size of the queue.
- `swap()`	Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.
- `emplace()` Insert a new element into the queue container, the new element is added to the end of the queue.
- `front()`	Returns a reference to the first element of the queue.
- `back()`	Returns a reference to the last element of the queue.
- `push(g)`	Adds the element ‘g’ at the end of the queue.
- `pop()` 	Deletes the first element of the queue.

### Stacks (LIFO)
- `empty()` – Returns whether the stack is empty – Time Complexity : O(1)  
- `size()` – Returns the size of the stack – Time Complexity : O(1) 
- `top()` – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
- `push(g)` – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
- `pop()` – Deletes the most recent entered element of the stack – Time Complexity : O(1) 
### Vector 
- `size()` returns size
- `front()` and `back()`
- `push_back()` pushes the elements into a vector from the back
- `pop_back()` used to pop or remove elements from a vector from the back

## [Problems to do](https://medium.com/@akashagrawal_33749/cracking-the-firmware-embedded-systems-engineer-interview-d73a37da95bd)
### Arrays:
- binary search
- 2 pointer search
- sliding window problem
- kadane algorithm
### Strings:
- Reverse string
### Linked List:
- Reverse Singly Linked List
- Reverse Doubly Linked List
- Merger two linked lists
- Add, Delete, Search element of Linked List
- Find Middle of List
- Find last nth element of list
- Find if there is loop in list
### Stacks and Queue:
- Implement Stack (FIFO) using Arrays
- Implement Stack using Linked List
- Implement Queue using Linked List
- Implement Queue using Arrays
- Implement Circular buffer
### Bit Manipulation:
- atoi, itoa, itob, float to bin (link), atof
- Add/Sub in binary (w/o using + operator) link
- 2s complement (-ve numbers)
- endianness swap (link)
- range of 8 bit (-128 to 127 link)
- represent float in binary (link)
### Memory:
- implement aligned malloc/free ** link
- implement malloc/free using static buffers (arrays)

## Miscellaneous
1. **Implement a Linked List**:
    - Write a simple linked list class with basic operations like insert, delete, and search. (Sometimes, they might ask for a doubly linked list instead).
2. **Reverse a String**:
    - Implement a function to reverse a string in C++ without using any built-in reverse functions.
3. **Find the Middle Element of a Linked List**:
    - Write a program to find the middle element of a singly linked list in one pass.
4. **Binary Tree Traversal**:
    - Implement in-order, pre-order, and post-order traversals of a binary tree.
5. **Check for Balanced Parentheses**:
    - Given a string containing characters '(', ')', '{', '}', '[' and ']', write a function to check if the input string has valid and balanced parentheses.
6. **Merge Two Sorted Arrays**:
    - Write a function to merge two sorted arrays into a single sorted array.
7. **Detect a Cycle in a Linked List**:
    - Implement an algorithm to detect a cycle in a linked list.
8. **Implement a Stack or Queue**:
    - Write your own stack or queue class, with methods to add, remove, and retrieve elements.
9. **Find Duplicate or Missing Elements**:
    - Given an array of integers where each element appears twice except for one, find that single one. Alternatively, find the missing number in a sequence.
10. **Sorting Algorithms**:
    - Implement a common sorting algorithm (like quicksort, mergesort, or bubblesort) and discuss its time complexity.
11. **Implement a Hash Table**:
    - Design a basic hash table without using any built-in data structures.
12. **Find the 'Kth' Largest (or Smallest) Element in an Array**:
    - Write a function to find the 'Kth' largest element in an unsorted array.
13. **Depth-First Search (DFS) and Breadth-First Search (BFS) in Graphs**:
    - Implement DFS and BFS traversals on a graph.
14. **Dynamic Memory Allocation**:
    - Demonstrate how you would manually manage dynamic memory allocation and deallocation (using **`new`** and **`delete`**).
15. **Copy Constructor and Assignment Operator**:
    - Explain and implement a copy constructor and an assignment operator for a class.
