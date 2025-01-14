

void convertedintosortedDLL(TreeNode<int>*root,TreeNode<int>*&head){
    //base case
    if(root==NULL){
        return NULL;
    }

    convertintosortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }

    head=root;

    convertedintosortedDLL(root->left,head);
}

