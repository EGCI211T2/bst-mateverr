#include "Treenode.h"

class BST {
  
  int size; // tell how big the search tree is
  TreeNodePtr rootPtr;

  public:
    BST();
    ~BST();
    void insert_node(int);
    void print(int = 0);
    /* 0= inOrder 1=preOrder 2=postorder 3=printeverything 4=3+ print tree*/
};

// Additional functions
void inOrder(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
void printTree(TreeNodePtr,int); //The real lab
void kill(TreeNodePtr);

void BST::insert_node(int value) {
  // Finish insert_node function
  // Start with simple insertion
  
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value); // Create an empty node
                                  // Call a new node
                                  // Need to add new node to existing tree
  // If create new node
  if (new_node) {
    if (size == 0) rootPtr = new_node; 
    else {
      t = rootPtr;
      while (inserted == 0) // everytime the function is called inserted == 0
      {
        //once the location is found --> inserted=1
        //1.should it go left or right
        //2. should it be inserted, if available inserted, if not move
        //3. once inserted make insert=1

        if (t->get_value() >= value) {
          // go to the left tree
          if (t->move_left()) t=t->move_left(); // not free, just move
          // Same as if ()
          // so if the left side is not NULL, move 
          
          else { 
            // Left side is NULL, available, insert
            t->set_left(new_node);
            inserted = 1; 
            // Stop the search
          }       
        }
              
        else {
          if (t->move_right()) t=t->move_right();
          // go right --> insert right away / move your t

          else {t->set_right(new_node); inserted = 1;}
          // Stop the search                
        }
      }
    }
    ++size; // Increase the size
  }//end  new node
}

void BST::print(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    printTree(rootPtr, 0);
    cout << "Kill BST" << endl;
    kill(rootPtr);
  default:
    // printTree(rootPtr, 0);
    // cout << endl;
  }
}

BST::BST() { rootPtr=NULL; size=0; }
BST::~BST() {}

// Recursive
void inOrder(TreeNodePtr treePtr) { 
  // Go down each layer of root until the bottom
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                              
} 

void printTree(TreeNodePtr treePtr,int level = 0) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr == nullptr) return;

  level++;
  printTree(treePtr->move_right(), level);
  cout << setw(3*level) << treePtr->get_value() << endl;
  printTree(treePtr->move_left(), level);
  
} 


void postOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr == nullptr) return;
  
  postOrder(treePtr->move_left());
  postOrder(treePtr->move_right());
  cout << setw(3) << treePtr->get_value();
} 

void kill(TreeNodePtr treePtr) {// Need work
  // TreeNodePtr 
  if(treePtr) {
    kill(treePtr->move_left());
    kill(treePtr->move_right());
    delete treePtr;
       //delete everything 
  }                                          // end if
} // end function

void preOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr == nullptr) return; // no branch to traverse to

  cout << setw(3) << treePtr->get_value();
  preOrder(treePtr->move_left());
  preOrder(treePtr->move_right());                                     
} 

