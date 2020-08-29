# Stack Class with recursion and Linked List

A stack is an abstract data type that defines a set of behaviors (push, pop, top).
They can be implemented many different ways.  For this assignment we will be
creating a templated Stack class that uses a singly-linked list as the underlying
data structure.

You will need to implement the stack class using the starter code provided.  You
will also need to implement the parenthesesMatch function which uses your stack
class to verify if the string has the correct set of matching parentheses.

## Goals:
The purpose of this project is to gain a firm understanding of the stack data
structure and continue working with c++ classes, templates, and dynamic memory.
The assignment also asks you to implement a output method that uses recursion to
output the stack

## Requirements:
Code construction can be divided into two primary tasks:

### 1. **Stack class**

This class creates and manages the stack data structure using template syntax.
Your stack should be implemented as a singly-linked list.  You will not receive
credit for other forms of implementation.

At a minimum you must implement the following public methods:

+ Stack(); initializes the stack to an empty state.
+ Stack(const Stack& other); creates a deep-copy of the other stack.
+ Stack<Type>& operator=(const Stack<Type>& other); creates a deep-copy of the other stack and cleans up any previously used memory.
+ ~Stack(); cleans up any previously used memory.
+ int size() const; returns the current number of items in the stack.
+ bool empty() const; returns true if the stack is currently empty (i.e. the size is 0)
+ Type top() const; returns the item on top of the stack.  The item is not removed from the stack.  Throws a logic_error exception if the stack is empty
+ void push(const Type&); pushes the item onto the top of the stack.
+ void pop(); Removes an item from the top of the stack. If the stack is empty, this method has no effect.
+ void pop(int n); Removes n items from the top of the stack. If there are not n items in the stack it removes as many as possible until the stack is empty.
+ Type topPop(); pops and returns the item on top of the stack.  Throws a logic_error exception if the stack is empty
+ void clear(); deletes the entire stack and resets it to an empty state.
+ friend std::ostream& operator<< <>(std::ostream&, const Stack<Type>& stack); Outputs the items in the stack formated as item1->item2->...->itemn.  For example, if the stack is 1,2,3,4 with the 4 on top of the stack, this method outputs 1->2->3->4.  Note that this method prints in order from the bottom of the stack to the top of the stack. It is recommended that you use recursion to accomplish this.  See the notes below.


When implementing the stack it is recommended that you use the head of the list
as the top of the stack.  This makes the pop method more effecient.  If you do
not implement the top of the stack as the head of the list, you will not receive
full credit for this assignment.

To print the stack from bottom to top it is recommended that you use recursion
to do so.  This is not strictly required but is strongly recommended.  Printing
a stack recursively from bottom to top works like this.

1. Print the rest of the stack recursively
2. Print the current node of the stack.


### 2. **ParenthesesMatch function**

This function should take any string and determine if the parentheses match.
Matching paretheses means that for every opening parenthesis there is a
matching closing parenthesis later in the string.  An easy way to verify this
is to push the opening parenthesis onto a stack each time you encounter one while
scanning the string.  Similarly, each time a closing parentheses is encountered,
pop the opening parenthesis from the stack.  If ever there is not one to pop off
the stack, or if you reach the end of the string and the stack is not empty, you
do not have matching parentheses.

