#include "stack.h"
#include <iostream>


using namespace std;

stack::stack(){
    top = -1; //indicate empty stack
}

stack::~stack(){
    //Destructor
}

bool stack::isEmpty(){
    if(top ==-1){
        return true;
    }
    else{
        return false;
    }
}

bool stack::isFull(){
    if(top == MAX-1){
        return true;
    }
    else{
        return false;
    }
}

void stack::push(el_t elem){
    if(isFull()){
        throw Overflow();
    }
    else{
        top++;
        el[top] = elem; 
    }
}

void stack::pop(el_t& elem){
    if(isEmpty()){
        throw Underflow();
    }
    else{
        elem = el[top];
        top--;
    }
}

void stack::topElem(el_t& elem){
    if(isEmpty()){
        throw Underflow();
    }
    else{
        elem = el[top];
    }
}

void stack::clearIt(){
    while(!isEmpty()){
        el_t x;
        pop(x);
    }
}

void stack::displayAll(){
    if(isEmpty()){
        cout << "[empty]" << endl;
    }
        else{
            cout << "Stack" << endl;
            for(int i=top; i >=0; i--){
                cout << (int)el[i] << endl;
            }
            cout << "--------------------"<< endl;
        }
    }

