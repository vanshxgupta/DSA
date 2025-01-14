
void inorder(TreeNode<int>* root,vector<int>&inorderval){

    if(root==NULL){
        return;
    }

    inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    inorder(root->right,inorderval);

}

TreeNode<int>* inordertoBST(int s, int e, vector<int> inorderval){

    //base case
    if(s>e){
        return NULL;
    }
    
    int mid=(s+e)/2;
    TreeNode<int>*root=new TreeNode<int>(inorderval[mid]);
    root->left=inordertoBST(s,mid-1,inorderval);
    root->right=inordertoBST(mid+1,e,inorderval);
    return root;

}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
   
   vector<int>inorderval;

   //store inorder
   inorder(root,inorderval);

    return inordertoBST(0,inorderval.size()-1,inorderval);
    
}
