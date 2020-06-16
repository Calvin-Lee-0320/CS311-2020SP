//============================================
// HW#: Final Project
// Name: Kyungbin Lee
// File type: final client file
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.
// Note that the second constructor of el_t can be used to
// create Course Number|Course Name|Professor name|Grade|Unit to add to the table. e.g. el_t X(22462|CS311|Rika Yoshii|IP|3);
int main()
{ /*
 Loop:
   Interactively add about course number, course name, professor name, grade and unit to the table,
     making sure some of them  collide. (function add)
     You can create el_t containing a course number, course name, professor name, grade and unit using a constructor.
 DisplayTable.
 Loop:
  Interactively look up names using cousre number. (function find)
    Cout the Number|Course Name|Professor name|Grade|Unit if found else (blank element was returned)
    an error message. */
    htable theTable;
    int coursenumber,courseunit ;
    string name,grade,term,profFirstname,profLastname;
    int end = 1;
    int choice;
    int bigend = 1;
    
    //Show the menu
    while(bigend != 0){//until user want to exit the program
        end = 1;
    cout << "\nWhat is your option?" << endl;
        cout << "1.Add the course" << endl;
        cout << "2.Search the course" << endl;
        cout << "3.Show your transcript" << endl;
        cout << "4.Load your transcript" << endl;
        cout << "5.Delete the course" << endl;
        cout << "6.Save your transcript" << endl;
        cout << "Enter any number to exit(except 1~6)" << endl;
        cout << "Please Enter: ";
    cin >> choice;
    
    //1.Add the course
    if(choice ==1){
    while(end != 0){//until user want to stop add the course
        cout << "\nEnter a class number: ";
        cin >> coursenumber;
        cout << "Enter a unit of course: ";
        cin >> courseunit;
        cout << "Enter a class name: ";
        cin >> name;
        cout << "Enter a term of class: ";
        cin >> term;
        cout << "Enter a grade of class: ";
        cin >> grade;
        cout << "Enter a the professor first name: ";
        cin >> profFirstname;
        cout << "Enter a the professor last name: ";
        cin >> profLastname;
        
        el_t element(coursenumber,name,term,grade,profFirstname,profLastname,courseunit);
        theTable.add(element); //add the course information to the transcript table
        
        cout << "Enter 0 to stop adding courses, or enter 1 to continue: ";
        cin >> end;
    }
    }//end of #1
    
    //2.Search the course
    else if(choice ==2){
        while(end != 0){//until user want to stop search the course
        cout << "Enter the course number to search: ";
        cin >> coursenumber;
        
        el_t E = theTable.find(coursenumber);
        el_t blank;
        
        if(E == blank){cout << coursenumber << " not found." << endl;}// if the course does not exist
        else{cout << "Found " << coursenumber << ": " << E << endl;}//else: success to search the course
        cout << "Enter 0 to stop find courses, or enter 1 to continue: ";
        cin >> end;
    }
    }//end of #2
        
    //3.Show your transcript
    else if(choice == 3){
        theTable.displayTable();//show the transcript table
    }// end of #3
        
    //4.Load your transcript
    else if(choice == 4){
        theTable.InputData();
    }// end of #4
    
    //5.Delete the class
    else if(choice == 5){
        while(end != 0){//until user want to stop delete the course
        cout << "Enter the class number to delete: ";
        cin >> coursenumber;
        
        el_t E = theTable.find(coursenumber);
        el_t blank;
        
        if(E == blank){cout << "Course is not found" << endl;} //if the course does not exist
        else{theTable.remove(E); cout << "Success to delete the course in your transcript." << endl;} //else: success to delete the course
            cout << "Enter 0 to stop delete courses, or enter 1 to continue: ";
            cin >> end;
    }
    }//end of #5
        
    //6.Save your transcript
    else if(choice ==6){
        theTable.OutputData();
    }//end of #6
        
    //Exit(the number except 1~6)
    else{bigend = 0;}
        //ask to user exit program or go back to menu
        
        cout << "\n0.Exit program\n1.Go back to menu\nEnter 0 or 1: ";
        cin >> bigend;
    }//end of big while loop
}

