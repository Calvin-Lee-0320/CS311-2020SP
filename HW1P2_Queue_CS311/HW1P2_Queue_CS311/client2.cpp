//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program
//The string output should match my hw1queueDemo.out

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Kyungbin,Lee
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"
using namespace std;
//Purpose of the program: Make combinations using "A", "B", "C" and get them until max size of the queue
//Algorithm: Remove the front value of the queue, print the value which is removed, and then make a new combination of character using the add function. If the number of characters get to the max size which is 50, throw overflow to end the program.
int main()
{   queue Q;
    string s;
    
    Q.add("A");
    Q.add("B");
    Q.add("C");// ** "A", "B", "C" in the queue
    
    while(1){ //** while loop -- indefinitely
      try
        {
            Q.remove(s); //bring front element to string s
            cout << s << endl; //print the value front element
            
            Q.add(s + "A"); //front element + "A"
            Q.add(s + "B"); //front element + "B"
            Q.add(s + "C");//front element + "C"
            
        }
        catch(queue::Overflow){
            cerr << "Cannot be add" << endl;
            exit(1); //if Overflow, end the program
        } //** }
        catch(queue::Underflow){
            cerr << "Too few characters" << endl;
            exit(1); //if Underflow, end the program
        }
    }// end of loop
    return 0;
}

