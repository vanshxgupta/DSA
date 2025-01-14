
//INORDER
vector<int>getinorder(TreeNode*root){
    vector<int>inorder;
    TreeNode*curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr=curr->right;

        }
        else{

            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr){//if there exist prev ka right aur pre ka right vapis curr ko point na kre matlab
                prev=prev->right;//righmost tk jao

            }


            //thread creation
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{//thread removal
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return inorder;
}


//PREORDER
vector<int>getPREorder(TreeNode*root){
    vector<int>preorder;
    TreeNode*curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->val);
            curr=curr->right;

        }
        else{

            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr){//if there exist prev ka right aur pre ka right vapis curr ko point na kre matlab
                prev=prev->right;//righmost tk jao

            }


            //thread creation
            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->val);
                curr=curr->left;
            }
            else{//thread removal
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}