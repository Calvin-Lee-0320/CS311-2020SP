// CS311 Yoshii - Hash Table header DO NOT CHANGE!!!
// ------------------------------------------------

#include "slist.h"


const int TSIZE = 41;  // 41 slots ; a prime number

class htable : public llist
{
 private:
 
slist table[TSIZE]; // each node of slist is el_t
                          // as defined in elem.h
 int hash(int);  // private hash function

 public:
  htable();
  ~htable();

  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(int); // finds an element based on key and returns it
  void displayTable(); // displays the table with slot#s
  int remove(el_t); //delete an element to the table and returns slot#
    void InputData(); //function to take input data from a file
    void OutputData(); //funcrion to output the updated content of data structure to file
};

