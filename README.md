# Algorithms and Data Structures

* The purpose of this repository is to maintain basic notes and examples to prepare for programming interviews.
* Special thanks to [hackerank](https://www.hackerrank.com/) and [codeWithHarry](https://www.codewithharry.com/) for providing amazing material and questions that helped for preparation.

## Tips to solve Algo problems in interviews

* Pay attention to details. Every hint in the question is useful to determine an optimal solution.
* Come up with an example which should have marginally higher number of elements and avoid special cases.
* Start with brute force solution and then start optimizing it.
* Complete the optimizations.
* Walk through your algorithm - Take a moment to understand what you have designed and have a very clear picture of what will you be coding.
  * What variables and data structures to use ?
  * How, why and when do they change ?
  * What is the structure of the code ?
* Whiteboard
  * Write straight
  * Use board space wisely
  * Coding style matters
    * Consistent braces
    * consistent variable naming
    * consistent spaces
    * descriptive variables
  * Push conceptual chunks of code into another function. Eg: Instead of defining a string compare code on the whiteboard just mention `compareStrings`
* Code with above things in mind.
* Test
  * Use small test cases
  * Edge cases
  * In the end, big test cases
  * Forget algorithm and consider only input and output.
* Don't panic when there is a bug, just take a moment and think about the place of origination.

## Data structure and programming languages

| Data Structure | Python | C++         |
| -------------- | ------ | ----------- |
| Array          | List   | Native array|
| Hash table     | dict   | std::map    |
| Linked List    | NA     | Linked list |

## Generic

* Tips to build logic for a given problem.
  * **Divide and Conquer:** Break a problem into multiple subparts and then try to solve the small sub-problems.
  * **Write a well commented code:** Choosing appropriate variable names and commenting the code can help to build the logic comprehensively.
  * **Learn DS and algos:** Practice as many algorithms possible so that you can use the same techniques, ideas and approaches for solving a given new problem. Sort, recursions, trees, stacks, queues.. etc
  * **Learn programming paradigms:** Important
  * **See others code:** Check open library codes. Eg: python libraries etc..
* Data structures : Way to store data in main memory (RAM) for efficient usage. Example are arrays, linked lists, stack, queue, etc...
* Algorithm : Sequence of steps to solve a given problem. Example: Sorting, searching etc..

## Memory Layout
  ```
    |       Heap          |
    |   Dynamic memory    |
    |_____________________|
    |        Stack        |
    | Memory for functions|
    | and its variables   |
    |_____________________|
    |                     |
    |   Static + Global   |
    |       variables     |
    |_____________________|
    |                     |
    |    Code segment     |
    |_____________________|
  ```
* Memory leak can happen in heap memory if it is not freed after usage.

## Time complexity and Asymptotic notations
* There are three notations namely Big o, Big Omega and Big Theta.

### Big Oh
* A function f(n) is said to be O(gn) if and only if there exists a constant c and a constant n0 such that
    `0 =< f(n) =< c*g(n) ; for every n >= n0`
    ```
    (in below example, g(n) will always be greater than f(n) with the help of the constant c which is equal to n)
    Eg: 0 =< n^3 + 1 =< n*n^3;
        for n = 2;
        0 =< 8 =< 2*8
    ```
* O(1) i.e n^0 means an algorithm runs in constant time.
* O(n^1) = O(n) is called linear time complexity.
* Mathematical definition of `Big O` says that O(n) is also O(n^2) is also O(n^3).
* Industrial definition of Big O is called `order of` and recommends to use minimum of the above three notations.

### Big Omega

* Its similar to Big O only that f(n) >= c * g(n); that means c*g(n) defines a lower bound for f(n). In simple words f(n) is always greater than c * g(n).
  `0 =< c*g(n) =< f(n) ; for every n >= n0`

### Big Theta

* If Big O and Big Omega do not provide good picture about the time complexity of a given algorithm then Big theta will give it.
* f(n) is Big theta of g(n) if and only if f(n) is both Big Oh and Big Omega of g(n).
  * `0 =< f(n) =< c1*g(n) ; for every n >= n0` - Oh
  * `0 =< c2*g(n) =< f(n) ; for every n >= n0` - omega
  * `c2*g(n) =< f(n) =< c1*g(n) ; for every n >= n0` - theta

### Methods to calculate time complexity

* Break the code into fragments.
* Drop the non dominant terms. Anything you represent as O(n^2+n) can be written as O(n^2).
* Drop the constant term. Anything you might think is O(3n) is O(n).

## Best, Worst and Expected case analysis of an algorithm

Eg - [1,2,3,4,5] - Search for an element using an Algo.

* Best Case
  * If in the above search the element is always at position 1 then a dumb algorithm that searches every instance will only need one comparison to report if an element is present or not.
  * The least time taken to run an algorithm. O(1) -> Tn = k;
* Worst Case
  * If the element is in the last position then it will take O(n) time to search the entire array.
  * The highest time taken to run an algorithm.
* Expected or average Case
  ```
  Average case = ( sum of all possible run times ) / ( number of possibilities )
  ```

## Space complexity

* Space is equally important along with time and a developer should also think about space when writing a program.
* Example, a recursive function's space complexity is O(n) because it recurse itself `n` times and allocates space in stack while running the program.

## Abstract Data types

### Array
* Basic methods in array are insert, delete, add, resize.
* Abstraction means hiding the details. In leh man words one does not need to know how a function is implemented they just need to know the usage of it.
* The memory of an static array cannot be increased as the compiler assigns a chunk of data in the stack for a declared array.
* Resizing of an array is possible by requesting for a new array with increased size and copying all the variables from the previous array.
* An element in an array can be accessed in O(1).
* Traversal:visiting every element in the array. O(n)
* Insertion: O(n)
* Deletion: O(n)

### Linear Search

* It goes index by index that is searching the entire array linearly.
* O(n)
* Best case is O(1).

### Binary search

* It can be applied only on a sorted array.
* Divides the array into halves until the required element is found.
* Time complexity is O(log n) because we are halving the array.
* Best case is O(1).
* See example eg_search.cpp for implementation.

### Linked List

* It is a better implementation of array. It is a structure with value and a pointer to the next element in the list. Thereby creating a chain of element which can be easily modified.
* Insertion at the beginning takes O(1).
* Insertion at the end takes O(n).
* Deletion at the end O(n).
* Insert with the node address given - O(1).

### Circular linked lists

* It is a simple singly linked list whose last node just points to the head node again.

### Stacks

* It is a linear data structure and follows LIFO.
* Functions are also normally stacked during execution.
* Another application is for parenthesis matching.
* It is an abstract data type.
* It can be implemented using array or linked list.
* operations on stacks:
  * push
  * pop
  * peek(index)
  * isEmpty() / isFull()
