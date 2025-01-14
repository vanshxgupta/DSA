
class Nodevalue{
    public:

    int minnode,maxnode,maxsize;
    Nodevalue(int minnode,int maxnode,int maxsize){
        this->minnode=minnode;
        this->maxnode=maxnode;
        this->maxsize=maxsize;
    }
};

Nodevalue largestBSTsolve(TreeNode * root){
   //an empty tree is a BST of size 0
   if(!root){
       return Nodevalue(INT_MAX,INT_MIN,0);
   }

    //using postorder traversal

   //Get values from left and right subtree of current tree;
    auto left=largestBSTsolve(root->left);
    auto right=largestBSTsolve(root->right);

    //validity ki condtion puttin kro 
    if(root->data>left.maxnode && root->data<right.minnode){
        return Nodevalue(min(root->data,left.minnode),max(root->data,right.maxnode),left.maxsize+right.maxsize+1);
    }

    return Nodevalue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
 
}

int largestBST(TreeNode*root){
    return largestBSTsolve(root).maxsize;
}