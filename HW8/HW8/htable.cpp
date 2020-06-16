// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Kyungbin Lee
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}

// a hash function that uses % TSIZE with three digit of course number
int htable::hash(int coursenum)
{ return (((coursenum%20000)%1000)%TSIZE);}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  int slot = hash(element.coursenumber);  // hash with the course number party
    table[slot].addRear(element);
    return slot;
  // ** Note that this means adding the element to a slist in the slot
}

// finds element using the scoursenumber and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int scoursenumber)
{
    el_t E;
 int slot = hash(scoursenumber); // hash with scoursenumber
 el_t selement;  // this is the element to look for in slist
    selement.coursenumber = scoursenumber; // initialize selement with just the scoursenumber
    E = table[slot].search2(selement); // call slist's search2 with selement which returns the found element
    return E;// return the found element from here (it could be blank)
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;
        table[i].displayAll(); // call slist's displayAll
    }
}

// delete the element to the table and returns slot#
int htable::remove(el_t element){
    int slot = hash(element.coursenumber);
    table[slot].deleteRear(element);
    return slot;
}

//function to take input data from a file
void htable::InputData(){
    el_t E;
    //Ask to user file name
    string filename;
    cout << "Enter your file name: " ;
    cin >> filename;
    
    ifstream fin;
    fin.open(filename.c_str(),ios::out); //open Input file
    
    if(fin.is_open()){
           //until all data added to transcript table from the input file
    while(fin >> E.coursenumber >> E.coursename >> E.term >> E.professorfirstname >> E.professorlastname >> E.grade >> E.unit){
        add(E); //add the course information to the transcript table
           }//end of while
           cout << "Success to load your transcript." << endl;
    }
    else{cout << "File Error" << endl;}
}

//function to output the updated content of data structure to file
void htable::OutputData(){
    //Ask to user file name
    string filename;
    cout << "Enter your file name: ";
    cin >> filename;
    
    ofstream fout(filename.c_str(),ios::out); //open the output file
    
    //until all slots(notes) in table move to output file
    for(int i =0; i < TSIZE; i++){
        Node* header = table[i].returnfront();
        while(header != NULL){
            fout << header->Elem.coursenumber << "|Course Name: " << header->Elem.coursename << "|Term: " << header->Elem.term << "|Professor: " << header->Elem.professorfirstname << " " << header->Elem.professorlastname << "|Grade: " << header->Elem.grade << "|Unit: " << header->Elem.unit;
            fout << endl;
            header = header->Next;
        }
    }
}
