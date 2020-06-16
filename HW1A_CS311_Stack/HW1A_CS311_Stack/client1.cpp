//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Kyungbin Lee
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"
using namespace std;
//Purpose of the program: To calculate the data which is stack structure in stack
//Algorithm: Put the expression in stack, when operends such as +,-,*, and / are the one of integers evaluate the top and the right before top value
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression

  cout << "type a postfix expression: " ;
  cin >> expression;

  int i = 0;  // character position within expression
  char item=0;  // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop
  while (expression[i] != '\0')
    {
     try
       {
           item = expression[i]; //current char
           
           if(isdigit(item)){ //if the char value is a number
               postfixstack.push(item-48);//push stack
            postfixstack.displayAll(); //print out the current values in stack
           }
           else if((item == '+') || (item == '-')|| (item == '*') || (item == '/')){ //if the char value is '+' or '-' or '*' or '/'
               
               char result;
               char a;
               char b;
               postfixstack.pop(a);
               postfixstack.pop(b);
               
               box1 = (int)a; //typecast, move char value to integer
               box2 = (int)b; //typecast, move char value to integer
               
               if(item =='+'){ //if the char is '+'
                   result = box1 + box2;
                   postfixstack.push(result); //put the result in stack
                   postfixstack.displayAll();
               }
               else if(item == '-'){ //if the char is '-'
                   result = box1 - box2;
                   postfixstack.push(result);
                   postfixstack.displayAll();
               }
               else if(item == '*'){ //if the char is '*'
                   result = box1 * box2;
                   postfixstack.push(result); //put the result in stack
                   postfixstack.displayAll();
               }
               else if(item == '/'){ //if the char is '/'
                  result = box1 / box2;
                  postfixstack.push(result); // put the result in stack
                  postfixstack.displayAll();
               }
           }
           else{ // if the char is an invalid value
               throw "Invalid Value" ;
           }
         // ** do all the steps in the algorithm given in Notes-1
       } // this closes try
        // Catch exceptions and report problems and quit the program now (exit(1)).
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow){
          cerr << "Expression is too long" << endl;
          exit(1); //if Overflow, end the program
      }
      catch (stack::Underflow){
          cerr << "Too few operands" << endl;
          exit(1); //if Underflow, end the program
      }
      catch (char const* errormsg){ // for invalid item case{
          cerr << errormsg << endl;
          exit(1); //if there is an invalid, end the program
      }
        i++;// go back to the loop after incrementing i
    }// end of while
    
 // After the loop successfully completes:
 // Pop the result and show it.
    char finalresult=0;
    cout << "The result is" << endl;
    postfixstack.pop(finalresult);
    cout << (int)finalresult << endl; //print the result
    
 // If anything is left on the stack, an incomplete expression
 // was found so inform the user.
    if(!postfixstack.isEmpty()){ //if there is the value left in stack
    cout << "Incomplete expression" << endl; //show the error
    }
    return 0;
}// end of the program

