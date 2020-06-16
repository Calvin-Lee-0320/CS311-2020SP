using namespace std;
#include <iostream>
#include <cmath>
//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Kyungbin Lee
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers
int binarySearch(int L[], int x, int first, int last)
{
    // Compare with the middle entry
int middle = floor((first+last)/2); // note that if first == last, there is only one element left
    if (x == L[middle]){
        cout << "comparing against an element in slot " << middle << endl;
    return middle;  // found x at location middle, so return the location
  }
  else if (x < L[middle]){
    last  = middle - 1; // go to first half
      if(last < 0 || last < first){
          return -1;//if the last slot number is less than 0 or first slot number is greater than last slot number
      }
  }//end of else if
  else if(x > L[middle]){
    first = middle + 1; // go to second half
      if (first > 9 || last < first){
          return -1; //if the first slot number over size of the arrary or last slot number is less than first slot number
      }
    }//end of else if
        
    cout << "comparing against an element in slot " << middle << endl;
    
  return binarySearch(L, x, first, last); //recursion to find the number
}


int main()
{
  int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]=7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A,e,0,9);

  if(respos == -1){ //error message
 cout << "Element not found" << endl;
  }
  else{
 cout << "Found it in position " << respos + 1 << endl;
  }
  return 0;
}
