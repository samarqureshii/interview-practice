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
