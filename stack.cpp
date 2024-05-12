#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;


template <class Type>
stackType<Type>::stackType() {
    TopOfStack = nullptr;           //initializes top of stack to null so it's empty
}

template <class Type>
void stackType<Type>::push(const Type& NewItem) {   //pushes item onto stack
    Node<Type> *NewNode = new Node<Type>;           //new node set to value of new item
    NewNode->Value = NewItem;
    NewNode->next = TopOfStack;                     //sets next to current item at top of stack
    TopOfStack = NewNode;                           //updates top of stack to new node

}

template <class Type>
Type stackType<Type>::top() const {     //gets top of stack
    assert(TopOfStack != 0);            //checks if stack is not empty
    return TopOfStack->Value;
}


template <class Type>                   //removes top item in stack
void stackType<Type>::pop() {
    Node<Type> *temp;                   //temporary pointer
    if (!isEmptyStack())                //checks if stack isn't empty
    {
        temp = TopOfStack;              //sets top of stack to temporary pointer
        TopOfStack = TopOfStack->next;  //updates top of stack pointer to next
    }
    else
        cout << "Hmm....stack is empty already.." << endl;
}

template <class Type>                           //checks if stack is full
bool stackType<Type>::isFullStack() const {
    return(TopOfStack == nullptr);              //if stack is full, returns true
}

template <class Type>                           //checks if stack is empty
bool stackType<Type>::isEmptyStack() const {
    return(TopOfStack == 0);                    //if stack is empty, returns true
}

template class stackType<char>;         //stackType class for char, int, and float
template class stackType<float>;
template class stackType<int>;
