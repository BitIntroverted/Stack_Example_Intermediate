/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;

    //declare blank data struct
    Data blankStruct;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */

    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pop() on empty stack 
    if(stack.peek(blankStruct)){
        cout << "peeked: " << blankStruct.information << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }    
    if(stack.pop(blankStruct)){
        cout << "popped: " << blankStruct.information << endl;
    } else {
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/
    
    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    // testing filling the stack and overflow
    cout << "Filling stack..." << endl;
    for (int i = 0; i < number_test_cases; i++) {
        string str = data[i];
        try{
            if (stack.push(ids[i], str)) {
                cout << "pushed: " << str << endl;
            } else {
                cout << "overflow error: " << str << " not pushed" << endl;
            }
        } catch (int x) {
            cout << "Exception " << x << ": requires positive ID and non-empty string" << endl;
        }
    }
    cout << endl;

    // testing isEmpty() on full stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pop() on full stack
    if(stack.peek(blankStruct)){
        cout << "peeked: " << blankStruct.information << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    
    if(stack.pop(blankStruct)){
        cout << "popped: " << blankStruct.information << endl;
    } else {
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;

    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    
    // this is a programmer debug routine used for
    // testing and is not part of normal stack methods
    stack.dumpStack();

    /************************************************
    ******** EMPTYING AND EMPTY TESTS ***************
    ************************************************/

    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing popping and peeking whole stack
    for (int i = 0; i < number_test_cases; i++) {
        if(stack.peek(blankStruct)){
            cout << "peeked: " << blankStruct.information  << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        if(stack.pop(blankStruct)){
            cout << "popped: " << blankStruct.information << endl;
        } else {
            cout << "pop underflow error: stack is empty" << endl;
        }
    }
    cout << endl;
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();

    //tested blank stacks at beginning
    
    /************************************************
    ******** RANDOM TESTS ***************************
    ************************************************/
    
    cout << "Random testing..." << endl;
    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< int(STACK_SIZE / 2); i++) {
        try{
            string str = data[i];
            if (stack.push(ids[i], str)) {
                cout << "pushed: " << str << endl;
            } else {
                cout << "overflow error: " << str << " not pushed" << endl;
            }
        } catch (int x) {
            cout << "Exception " << x << ": requires positive ID and non-empty string" << endl;
        }
    }
    cout << endl;

    /*
     * the following will test random operations. push() and pop()
     * are called twice as often as peek and isempty because they
     * change the stack and should be tested more rigorously.
     */
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < number_test_cases; i++) {
        switch (choice) {
            case 1:
            case 2:
                // push
                try{
                    string str = data[i];
                    if (stack.push(ids[i], str)) {
                        cout << "pushed: " << str << endl;
                    } else {
                        cout << "overflow error: " << str << " not pushed" << endl;
                    }
                } catch (int x) {
                    cout << "Exception " << x << ": requires positive ID and non-empty string" << endl;
                }
                break;
            case 3:
            case 4:
                // pop
                if(stack.pop(blankStruct)){
                        cout << "popped: " << blankStruct.information << endl;
                    } else {
                        cout << "pop underflow error: stack is empty" << endl;
                    }
                break;
            case 5:
                // peek
                if(stack.peek(blankStruct)){
                    cout << "peeked: " << blankStruct.information  << endl;
                } else {
                    cout << "peek underflow error: stack is empty" << endl;
                }
                break;
            case 6:
                // isempty
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;

    }
    cout << endl;

    stack.dumpStack();
    
   cout << "Testing complete." << endl;
   return 0;
}
