
void inorder(TreeNode<int>*root,vector<int>&inorderval){
    if(root==NULL){
        return ;

    }

    inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    inorder(root->right,inorderval);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>inorderval;

    //store inorder->sorted values;
    inorder(root,inorderval);

    //Create a node
    TreeNode<int>*newroot= new TreeNode<int>(inorderval[0]);

    //create another node current , which points to the same newroot node
    TreeNode<int>*curr=newroot;


    //2nd step(har node ke right ko uske next ppointer se point krwao aur har node ke left ko NULL se point krwao)
    for(int i=1;i<inorderval.size();i++){

        TreeNode<int>*temp= new TreeNode<int>(inorderval[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    //3rd step(final node ke dono pointers ko NULL se point krwao)
    curr->left=NULL;
    curr->right=NULL;

    return newroot;

}
