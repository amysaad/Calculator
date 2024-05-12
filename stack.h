#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H
#include <iostream>

template <class Type>
struct Node {
    Node<Type> *next;                 //pointer to next node in stack
    Type Value;                       //node value
};

template <class Type>
class stackType {
    Node<Type> *TopOfStack;          //pointer to top of stack

public:
    stackType();                     //constructor
    bool isFullStack() const;        //checks if stack is full
    bool isEmptyStack() const;       //checks if stack is empty
    void push(const Type& newItem);  //pushes item onto stack
    Type top() const;                //gets top of stack
    void pop();                      //removes top item in stack
};


#endif //CALCULATOR_STACK_H