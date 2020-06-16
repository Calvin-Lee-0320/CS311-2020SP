// CS311 Yoshii
// HW6 Client file
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client
// Name: Kyungbin Lee
// File type:  client cpp  (tester)
// ================================================


#include <iostream>
#include "dgraph.h"
using namespace std;

int main()
{
 /* 0.Declare table object
  1.fillTable()
  2.displayGraph()
  while (the user does not want to stop)
    a.the user will specify which vertex
    b.findOutDegree of the vertex and display the result
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception to display error mesg but do not exit
*/
    int run = 2;
    bool error = false;
    char vertex ;
    int degree;
    slist L;
    dgraph G;
    
    G.fillTable(); //1.fillTable()
    G.displayGraph(); //2.displayGraph()
    
    while(run > 1 && run <= 3){
        //a.the user will specify which vertex
        cout << endl;
        cout << "Enter vertex: ";
        cin >> vertex;
        
        //b.findOutDegree of the vertex and display the result
        //b.findAdjacency of the vertex and display the result (see Hint)
        try{
            if(run == 2){//find degree of vertex
                degree = G.findOutDegree(vertex);
            }
            else if(run == 3){//find adjacent of vertex
                L = G.findAdjacency(vertex);
                }
        }
        //c.catch exception to display error mesg but do not exit
        catch(dgraph::BadVertex){
            cerr << "Error: The vertex does not exist!" << endl;
            error = true;
        }
        //no error
        if(error == false){
            if(run == 2){
                cout << "The degree is: " << degree << endl;
            }
            else if(run == 3){
                cout << "The adjacents are: ";
                L.displayAll();
            }
            cout << endl;
        }
        
        do{
            cout << "OPTIONS:" << endl;
            cout << "1.Quit" << endl;
            cout << "2.Another vertex for degree" << endl;
            cout << "3.Anoter vertex for adjacent" << endl;
            cout << "Enter the number: ";
            cin >> run;
            error = 0;
        }while(run < 1 || run > 3);
    }
    return 0;
}
    

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/

