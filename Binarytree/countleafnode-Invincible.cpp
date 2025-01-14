
void inorder(BinaryTreeNode<int> *root, int &cnt){
    //base case
    if(root==NULL){
        return;

    }


    inorder(root->left,cnt);

    //is current node a leaf node?
    if(root->left==NULL  && root->right==NULL){
      cnt++;//if yes then cnt++
    }

    inorder(root->right,cnt);

}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    inorder(root, cnt);
    return cnt;


}