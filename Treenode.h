class TreeNode 
{   
  int data; // node value                                  
  TreeNode *leftPtr; // pointer to left subtree                              
  TreeNode *rightPtr; // pointer to right subtree

  public:
        // 7 function for 
        TreeNode(int); 
        ~TreeNode();
        void set_left(TreeNode* t) {leftPtr = t;}
        void set_right(TreeNode* t) {rightPtr = t;}
        int get_value(){return data;}
        TreeNode* move_right(){ return rightPtr; }
        TreeNode* move_left(){ return leftPtr; }
    //void search_tree(TreeNode * crn ,int x );
       

}; // end structure treeNode 
        
typedef TreeNode * TreeNodePtr; 
// synonym for TreeNode*


TreeNode::TreeNode(int x)
{
   data = x;
   leftPtr = NULL;
   rightPtr = NULL;
}

TreeNode::~TreeNode() // Destructor to delete the node
{
  cout<<"Deleting "<< data<<endl;
}
