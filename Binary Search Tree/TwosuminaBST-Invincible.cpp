void inorder(BinaryTreeNode<int>* root, vector<int>&inorderval){
        if(root==NULL){
            return ;

        }

        inorder(root->left,inorderval);
        inorderval.push_back(root->data);
        inorder(root->right,inorderval);

}


bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorderval;

    //store inorder ->sorted values
    inorder(root,inorderval);

    //use 2 pointer approach to check if pair exists
    int i=0;
    int j=inorderval.size()-1;

    while(i<j){
        int sum=inorderval[i]+inorderval[j];

        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }

    }
    return false;

}