#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <string>
using namespace std;

typedef string el_t; // el_t is an alias for char for now
const int MAX_SIZE =50; // this is the max number of elements

class queue {
private:
// Data members are:
el_t el[MAX_SIZE]; // a character array called el
int count; //how many elements do we have right now?
int front; //where the front element of queue is
int rear; //where the rear element of quue is
    
public:
    queue(); //constructor to create and initialize a queue object
    ~queue(); //destructor to get rid of the queue object
    bool isEmpty(); //returns true if queue is empty, otherwise false
    bool isFull(); //returns true if queue is full, otherwise false bool isFull();
    void add(el_t elem); //if full, throws Overflow. if not full, enters an element at the rea
    void remove(el_t& elem); //if empty, throws Underflow. if not empty, removes the front element to give it back via pass by
    //reference
    void displayAll(); // display everything in the queue from front to rear // horizontally enclosed in []
    //if empty, displays [ empty ]
    void frontElem(el_t& elem); //if empty, throws Underflow if not empty, give back the front element via pass by reference
    //(but does not remove it)
    void goToBack();//if empty, throws Underflow
    //if queue has just 1 element, does nothing
    //if queue has more than 1 element, moves the front one to the rear
    int getSize();
    //returns the current number of elements to make it accessible
    // to the client caller
    
    class Overflow{}; //exception handling
    class Underflow{}; //exception handling
};
// how many elements do we have right now? // where the front element of the queue is.
// where the rear element of the queue is.

#endif 
