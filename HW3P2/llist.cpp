//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Kyungbin Lee
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h"

llist::llist() //constructor
{
  cout << "... in llist constructor..." << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist() //destructor
{
  el_t a;
  cout << ".... in llist destructor..." << endl;
  while(!isEmpty()){//until the list is not empty, delete all nodes
    deleteFront(a);
  }
}

//PURPOSE: check the list is empty or not(true or false)
//PARAMETER: no parameter
bool llist::isEmpty()
{
  if(Front == NULL && Rear == NULL && Count == 0){//if nothing on the list, return true
    return true;
  }
  return false;
} // be sure to check all 3 data members

//PURPOSE: show all elements of all nodes on the list
//PARAMETER: no parameter
void llist::displayAll()
{
  if(isEmpty()){ //special case: if the list is empty
    cout << "[empty]" << endl;
    return;
  }//end of if
  
  cout << "[ " ;
    Node *p;
    p = Front;
    while( p!= NULL){ //until p reaches to Rear
        cout << p->Elem << " "; //print the element of node
        p = p->Next; //move pointer to next
    }//end of while
    cout << "]" << endl;
}  // be sure to display horizontally in [  ] with
// blanks between elements
  
//PURPOSE: add a node to the rear of list, and add element
//PARAMETER: new element being added to the rear node of the list
void llist::addRear(el_t NewNum){
    if(isEmpty()){//special case: if the list is empty, then we make the first Node in list
        Front = new Node; //make a new node
        Front->Elem = NewNum; //put the value in it
        Front->Next = NULL; //make sure the next of last node is NULL
        Rear = Front; //since we have only one Node, Front and Rear point same thing
    }
    else{//regular case
        Node *p2 = new Node;//p2 is gonna be last node on the list
        p2->Elem = NewNum;
        //make p2 as a last node
        Rear->Next = p2;
        Rear = p2;
        Rear->Next = NULL;//make sure the next of last node is NULL
    }
    Count++; //count updated
} // comment the 2 cases

//PURPOSE: add a node to the front of list, and add element
//PARAMETER: new element being added to the front node of the list
void llist::addFront(el_t NewNum){
    if(isEmpty()){//special case: if the list is empty, then we make the first Node in list
        Front = new Node;
        Front->Elem = NewNum;
        Front->Next = NULL;
        Rear = Front;//since we have only one Node, Front and Rear point same thing
    }
    else{//regular case
        Node *T = new Node; //Node T is gonna be the first node on the list
        T->Elem = NewNum;
        //make T as the first node on the list
        T->Next = Front;
        Front = T;
    }
    Count++; //Count updated
} // comment the 2 cases

//PURPOSE: delete the front node on the list
//PARAMETER: element being deleted
void llist::deleteFront(el_t& OldNum){
    if(isEmpty()){
        throw Underflow(); //error: if the list empty, then throw exception
    }
    else if(Count == 1){ //only one on the list, empty the list
        OldNum = Front->Elem;
        delete Front;
        //make sure nothing on the list
        Front = NULL;
        Rear = NULL;
    }
    else{//more than one on the list, delete the front element
        OldNum = Front->Elem;
        Node *nextFront; //2nd node
        nextFront = Front->Next;
        //for delete 1st node, and delete it
        Front->Next = NULL;
        delete Front;
        Front = nextFront; //make nestFront as the first node on the list
    }
    Count--; //count updated
} // comment the 3 cases

//PURPOSE: delete the rear node on the list
//PARAMETER: element being deleted
void llist::deleteRear(el_t& OldNum){
    if(isEmpty()){ //error: if the list empty, then throw exception
        throw Underflow();
    }
    else if(Count == 1){//only one on the list, empty the list
        OldNum = Rear->Elem;
        delete Rear;
        Front = NULL;
        Rear = NULL;
    }
    else{//more than one on the list, delete the rear element
        OldNum = Rear->Elem;
        Node *p = Front;
        while(p->Next != Rear){//until prevRear is the node before the rear node
            p = p->Next;
        }
        //make sure that p is gonna be last node
        //make p as the last node
        p->Next = NULL;
        delete Rear;
        Rear = p;
    }
    Count--; //count updated
} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times
    for ( int K =1; K <= J-1; K++){
        temp = temp->Next;
    }
}

//PURPOSE: delete the Ith node on the list
//PARAMETER: Ith node position, element being deleted
void llist::deleteIth(int I, el_t& OldNum) {
    if(I > Count || I < 1){//exception, if I is the number over size or less than 1
        throw OutOfRange();
    }
    else if(I == 1){//special case1
        deleteFront(OldNum);
    }
    else if(I == Count){//special case2
        deleteRear(OldNum);
    }
    else{//regular case
        Node *T = Front;//T is the front node
        moveTo(I,T); //T is move to (I-1)th node
        Node *Tdelete = T->Next ;//Tdelete is Ith Node
        T->Next = T->Next->Next;
        OldNum = Tdelete->Elem;
        //make sure the T2 is last node on the list before delete
        //delete Tdelete
        Tdelete->Next = NULL;
        delete Tdelete;
        Count--;//count updated
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: insert a new node on Ith of the list
//PARAMETER: Ith node position, new element being added
void llist::insertIth(int I, el_t newNum){
    if(I>Count+1 || I <1){//exception case if I > Count+1 or less than 1
        throw OutOfRange();
    }
    else if(I == 1){//speical case 1
        addFront(newNum);
    }
    else if(I == Count+1){//special case 2
        addRear(newNum);
    }
    else{
        Node *T = Front;
        Node *T2 = new Node;//T2 is gonna be Ith Node
        T2->Elem = newNum;
        moveTo(I,T); //Node T move to (I-1)th Node
        //make sure T2 is the Ith Node
        T2->Next = T->Next;
        T->Next = T2;
        Count++; //count updated
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Copy Constructor to allow pass by value and return by value of a llist
//PARAMETER: linked list being copied
llist::llist(const llist& Original) {
    //  this->'s data members need to be initialized here first
    this->Front = NULL;
    this->Rear = NULL;
    this->Count = 0;
    
    if(&Original != this){
        Node* P = new Node;
        P= Original.Front;//P is the front node on the list
        while(P != NULL){
            this->addRear(P->Elem);
            P = P->Next;//move to next pointer
        }
    }
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with
    //  operator= above. To do this,
    //copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.

    //  Nothing to return because this is a constructor.
} // use my code

//PURPOSE: Overloading of = (returns a reference to a llist)
//PARAMETER: linked list being overloaded
llist& llist::operator=(const llist& OtherOne){
    el_t x;
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
     {
       // this-> object has to be emptied first.
       while (! this->isEmpty() )
                  this->deleteRear(x);
       // this-> object has to be built up by allocating new cells with OtherOne elements (**)
       Node* P;  // local pointer for OtherOne
       P = OtherOne.Front;
       while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
       {
          this->addRear(P->Elem);    //P’s element is added to this->
          P = P->Next;                         // Go to the next node in OtherOne
        }
     }// end of if
    return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} // use my code


