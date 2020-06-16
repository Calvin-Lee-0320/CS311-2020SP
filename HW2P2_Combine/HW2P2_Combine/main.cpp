using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine
//Name: Kyungbin Lee
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
    int a = 0;
    int b = 0;
    while(a < A.size() && b < B.size()){//run until A elements are run out and B elements are run out
        if(A[a] < B[b]){ // put value from A into R
            R.push_back(A[a]);
            a++;
        }
        else{ // put value from B into R
            R.push_back(B[b]);
            b++;
        }
    //**
     cout << "comparison" << endl;
    //** // be careful -- R comes in as an empty vector with no slots
    } // end of while loop
    if(a < A.size()){//if the element still left in L1
        cout << "The rest of the first one goes down." << endl;
        for(int i = a; i <= A.size(); i++){
            R.push_back(A[i]);//copy leftover of A into R
        }
    }
    else{ //if the element still left in L2
        cout << "The rest of the second one goes down." << endl;
        for(int i = b; i< B.size(); i++){
            R.push_back(B[i]); //copy leftover of B into R
        }
    }
}//end of the function

int main()
{
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);}

  cout << "List2"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);}

   
    combine(L1,L2,L3);// call combine here to combine L1 and L2 into L3
    //**

  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

  return 0;
}// end of main
