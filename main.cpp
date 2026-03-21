#include <iostream>
#include <iomanip>
using namespace std;
#include "BST.h"

int main(int argc, char **argv) 
{
  unsigned int i; // counter to loop from 1-10
  BST b;

  for (i = 1; i < argc; ++i) 
  {
       b.insert_node (atoi(argv[i])); // insert node according to amount of argc
       cout << argv[i] << " inserted" << endl;
  } // end for

  // cout << "inOrder" << endl;

  // need to finish preOrder and postOrder function

  b.print(3);
  // the line above runs
  // now ma


  //b.searchtree(11);
 
} // end main
