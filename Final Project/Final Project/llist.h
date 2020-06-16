//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS

// =======================================================
// HW#: HW3P1 llist
// Your name: Kyungbin Lee
// Compiler:  g++
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
#include "elem.h"

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //check the list is empty or not(true or false)
  bool isEmpty();
    
  //show all elements of all nodes on the list
  void displayAll();

  //add a node to the front of list, and add element
  void addFront(el_t);
    
  //add a node to the rear of list, and add element
  void addRear(el_t);

  //delete the front node on the list
  void deleteFront(el_t&);
    
  //delete the rear node on the list
  void deleteRear(el_t&);
    
  //delete the Ith node on the list
  void deleteIth(int, el_t&);  // calls moveTo

  //insert a new node on Ith of the list
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&);

};

