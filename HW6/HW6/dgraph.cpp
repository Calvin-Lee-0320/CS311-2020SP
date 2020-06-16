//CS311 Yoshii dgraph.cpp
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Kyungbin Lee
// File Type: cpp file
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
    for(int i =0; i<SIZE; i++){
        Gtable[i].vertexName = ' ';
        Gtable[i].visit = 0;
    }
    countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
    
    if(!fin) return;
    
    char x;
    char xchar;
    int OD;
    while(fin >> x){
        fin >> Gtable[countUsed].outDegree;
        
        for(int i = 0; i < Gtable[countUsed].outDegree; i++){
            fin >> x;
            xchar = (char)x;
            Gtable[countUsed].adjacentOnes.addRear(xchar);
        }//end of for loop
        countUsed ++;
    }//end of while loop
    fin.close();
    }
  // the rest is in HW6-help

void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows
    for(int i = 0; i < countUsed; i++){
        cout << Gtable[i].vertexName << " ";
        cout << Gtable[i].outDegree << " ";
        Gtable[i].adjacentOnes.displayAll();
        cout << endl;
    }
}

int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
    int intV = int(V) - 65; // change V to integer
    if(intV >= 0 && intV < countUsed){
        return Gtable[intV].outDegree;
    }
        throw BadVertex(); //throw the exception
}

slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
    int intV = int(V) - 65; // change V t
    if(intV >= 0 && intV < countUsed){
        return Gtable[intV].adjacentOnes;
    }
        throw BadVertex(); //throw the exception
}

