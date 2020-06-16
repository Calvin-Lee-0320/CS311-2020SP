//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Kyungbin Lee
// File type: client file
//==========================================
#include "dgraph.h"
#include "stack.h"
// Be sure to include dgraph, slist and stack

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // use the algorithm (read carefully) in the HW7
  // assignment sheet
  //------------**

  //Display the graph 
  dgraph TheGraph;
  TheGraph.fillTable();
  TheGraph.displayGraph();
  slist adjacencyList;
  
  //Push A onto the stack.
  stack TheStack;
  char TheVertex = 'A';
  int TheVertNum = 1;
  TheStack.push(TheVertex);

  //While the stack is not empty 
      while(!TheStack.isEmpty())
    {
      //Remove a vertex v from the stack.
      TheStack.pop(TheVertex);
      
      //Display the vertex name.
      cout << "Removed " << TheVertex << " from stack" << endl;

      //If v is not marked yet
      if(TheGraph.isMarked(TheVertex) == 0)
        {
          //mark it 
          TheGraph.visit(TheVertNum, TheVertex);
          cout << "Visit " << TheVertex << " as " << TheVertNum+1 << endl;

          //get its adjacency list
          adjacencyList = TheGraph.findAdjacency(TheVertex);


          //if no adjacent ones...
          if(adjacencyList.isEmpty())
        {
          //...inform the user
          cout << "Deadend reached – backup" << endl;
        }
          else
        {
          //else, put adjacent ones on the stack (delete from the rear and push)
          cout << "...pushing "; adjacencyList.displayAll();
          while(!adjacencyList.isEmpty())
            {
              adjacencyList.deleteRear(TheVertex);
              TheStack.push(TheVertex);
             }
        }
          TheVertNum++; //vertex number updated
        } //end big if
      
      else
        {
          //else, inform the user
          cout << TheVertex << " has been visited already - backup" << endl;
        }//end else

      cout << "The Stack is now: " << endl;
      TheStack.displayAll();
    }
      //display the final graph
      cout << endl << "The Final Graph is: " << endl;
      TheGraph.displayGraph();
}
