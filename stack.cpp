/*
 * 	Name: Lukas Friedrich
 * 	Coding 03
 * 	Integer stack class with methods to interact with the ADT
 */

// each cpp includes ONLY it's header directly!
#include "stack.h"

    Stack::Stack(){
        this->top = -1;
    }

    bool Stack::push(int idVal, const string& val){
        if (idVal < 0 || val == ""){
            throw 1;
        }
        bool pushed = false;
        //check you're under the top
        if (this->top < STACK_SIZE-1){
            Data* tempData = new Data;
            tempData->id = idVal;
            tempData->information = val;
            stack[++top] = tempData;
            pushed = true;
        }
        return pushed;
    }

    //Pop copys the top Data to slate then removes it from the stack
    bool Stack::pop(Data& slate){
        bool popped = false;
        if (!isEmpty()){
            //populate blank slate
            slate.id = stack[top]->id;
            slate.information = stack[top]->information;
            //free up mem from popped position
            delete stack[top];
            top--;
            popped = true;
        }
        else{
            slate.id = -1;
            slate.information = "";
        }
        return popped;
    }

    //Peek copys the top Data to the passed param, slate
    bool Stack::peek(Data& slate){
        bool peeked = false;
        if (!isEmpty()){
            //populate blank slate with top Data
            slate.id = stack[top]->id;
            slate.information = stack[top]->information;
            peeked = true;
        }
        else{
            slate.id = -1;
            slate.information = "";
        }
        return peeked;
    }

    bool Stack::isEmpty(){
        return (top < 0);
    }

    void Stack::dumpStack() {
    std::cout << "dumping whole stack..." << std::endl;
    if (!isEmpty()) {
        for (int i = top; i >= 0; i--) {
            std::cout << "ID: " << stack[i]->id  << "Info: " << stack[i]->information << std::endl;
        }
    } else {
        std::cout << "\tstack is empty" << std::endl;
    }
    std::cout << std::endl;
}