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
#include "htable.h"
#include <fstream>

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ return (key%TSIZE);}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  int slot = hash(element.courseNumber);  // hash with the Course Number part
    table[slot].addRear(element);
    return slot;
  // ** Note that this means adding the element to a slist in the slot
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{
    el_t E;
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
    selement.courseNumber = skey; // initialize selement with just the skey
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

void htable::Findcourse(htable mytranscript){
    int key; //course #
    
    cout << "Enter the course number want to search: " ;
    cin >> key;
    el_t S = mytranscript.find(key);
    el_t blank;
    
    if(S == blank)
        cout << key << "is not found." << endl;
    else
        cout << "Found " << key << ": " << S << endl;
    }

void htable::Loadinfo(htable mytranscript){
    ifstream fin;
    fin.open("Input.txt");
    
    el_t htable;
    
    while(fin){
        fin >> htable.courseNumber;
        fin >> htable.term;
        fin >> htable.courseName;
        fin >> htable.grade;
        fin >> htable.unit;
        fin >> htable.profName;
        
        mytranscript.add(htable); //add the information
    }
    fin.close(); // close the file
    cout << "Transcript is loaded" << endl;
}

void htable::addcourse(htable myT){
    int CNumber;
    string CName;
    string MT;
    string MG;
    double MU;
    string profN;
    
        cout << "Enter a course number to add the transcript: ";
        cin >> CNumber;
        cin.ignore();
        cout << "Enter a term of course to add the transcript: ";
        getline(cin,MT);
        cout << "Enter a course name to add the transcript: ";
        getline(cin,CName);
        cout << "Enter a grade to add the table: ";
        getline(cin,MG);
        cout <<"Enter a unit number to add the table: ";
        cin >> MU;
        cin.ignore();
        cout << "Enter a professor name to add the table: ";
        getline(cin,profN);
    
    el_t element(MT,CName,MG,MU,profN,CNumber);
        myT.add(element); //add the course into table
    cout << "Success to add the course in your transcript." << endl;
}

void htable::deletecourse(htable mytranscript){
    int CNumber;
    
        cout << "Enter the course number to delete: " ;
        cin >> CNumber;
        
        el_t E = mytranscript.find(CNumber);
        el_t blank;
        
        if(E == blank) {cout << "Course is not found." << endl;}
        else{
            mytranscript.remove(E);
            cout << "Success to delete the course in your transcript." << endl;
        }
}

void htable::saveInfo(htable mytranscript){
    ofstream fout("Output.txt");
    
    el_t htable;
    string TcourseName;
    string Tterm;
    string Tgrade;
    int TcourseNumber;
    double Tunit;
    string TprofName;
    
    for (int i=0; i<TSIZE; i++){
        fout << i << ":" ;
    }//end of for loop
    fout.close();
    cout << "Transcript is stored" << endl;
}

int htable::remove(el_t element){
    int slot = hash(element.courseNumber);
    table[slot].deleteRear(element);
    return slot;
}
