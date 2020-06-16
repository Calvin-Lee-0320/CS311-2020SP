//========================================
//HW#: Final Project
//Name: Kyungbin Lee
//File Type: final client file
//=========================================

#include "htable.h"
using namespace std;

int main(){
    
    htable mytranscript;
    int end = 1;
    int key; // key == class Number
    int choice; //choose the number in menu
    
    while(end != 0){
        do{
            cout << endl;
            cout << "Choose the option entering the number" << endl;
            cout << "1. Load your transcript" << endl;
            cout << "2. Search the Course" << endl;
            cout << "3. Show your transcript" << endl;
            cout << "4. Add a new class" << endl;
            cout << "5. Delete a class" << endl;
            cout << "6. Save the information into the file" << endl;
            cout << "7. End the program" << endl;
            cout << "Enter  number: " ;
            cin >> choice;
        }while(choice < 1 || choice > 7);
    
    switch(choice){
        case 1:
            mytranscript.Loadinfo(mytranscript);
            break;
        case 2:
            mytranscript.Findcourse(mytranscript);
            break;
        case 3:
            mytranscript.displayTable();
            break;
        case 4:
            mytranscript.addcourse(mytranscript);
            break;
        case 5:
            mytranscript.deletecourse(mytranscript);
            break;
        case 6:
            mytranscript.saveInfo(mytranscript);
            break;
        case 7:
            end = 0;
            break;
        default:
            cout << "Invalid option";
            break;
    }//end of the switch
      }//end of the while
    
    return 0;
}

/*
 Menu
 1. Load the data file
 2. Search the "class" using class #
 3. See the data on the screen(table)
 4. Add a new class
 5. Delete a class
 6. Save the data into the file
 7. Exit
 */
