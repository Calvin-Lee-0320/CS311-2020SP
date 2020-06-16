// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Kyungbin Lee
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include <iostream>
#include "slist.h"

// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{ cout << "slist constructor:" << endl;}
                                                                                                                                        
// positions always start at 1
int slist::search(el_t key){
    Node *S = Front; //set the search Node as a front
    int counter = 1;
    
    while(S != NULL){ //until get to Rear Node
        if(S->Elem == key){
            return counter; //return its position (>=1)
        }
        else{
            counter ++; //counter updated
        }
        S = S->Next;
    }
    return 0;
}
                                                        
// don't forget to throw OutOfRange for bad pos
void slist::replace(el_t element, int pos){
    Node *R = Front;
    if(pos < 1 || pos > Count){ //illegal value -> throw exception
        throw OutOfRange();
    }
    for(int i=1; i<pos; i++){// go to Ith Node, and replace it
        R = R->Next;
    }
    R->Elem = element;//replace the element of Node
}
                                                                                                    
bool slist::operator==(const slist& OtherOne)
{
    Node *L1 = Front;
    Node *L2 = OtherOne.Front;
    
    // if not the same length, return false
    // if the same lengths,
    //check each node to see if the elements are the same
    if(L1 == NULL && L2 == NULL){ //case1: both are NULL
        return true;
    }
    else if(L1 == NULL || L2 == NULL){//case2: L1,L2 sizes are different
        return false;
    }
    while (L1 != NULL && L2 != NULL){ //until either one or both end
        if(L1->Elem == L2->Elem){
            //both move to next node
            L1 = L1->Next;
            L2 = L2->Next;
        }
        else{ //if failure, then return false
            return false;
        }
    }
    if(L1 == NULL && L2 != NULL){ //if L1 is shorter than L1
        return false;
    }
    else if(L1 != NULL && L2 == NULL){ //if L2 is shorter than L1
        return false;
    }
    return true;
}
