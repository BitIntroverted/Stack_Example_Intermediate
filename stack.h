/*
 *  Name: Lukas Friedrich
 *  Coding 04
 *  Stack (of pointers) class for Data struct 
 */

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#include <iostream>
using std::cout;
using std::endl;
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    Stack(); //constructor

    bool push(int, const string&);
    bool pop(Data&);
    bool peek(Data&);
    bool isEmpty();
    void dumpStack();

    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H