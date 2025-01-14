
void solve(BinaryTreeNode<int>* root,int&i, int k,int &ksmallest){

    //base case
    if(root==NULL|| i>=k){
        return ;

    }

    //left
    solve(root->left,i,k,ksmallest);
    i++;
    if (i == k) {
        ksmallest = root->data;
        return;
    }
    solve(root->right,i,k,ksmallest);

    
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    int ksmallest=-1;
    solve(root,i,k,ksmallest);
    return ksmallest;

}

