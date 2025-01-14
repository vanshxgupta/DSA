Node*minvalue(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;

    }
    return temp;
}


Node* deletefrombst(Node*root,int val){
    //base case
    if(root==NULL){
        return root;

    }
    if(root->data==val){

        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        } 

        //right child
        if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        } 

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minvalue(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
            return root;

        }

    }
    else if (root->data>val){
        //left part me jao
        root->left=deletefrombst(root->left,val);
        return root;

    }
    else{
        //right part me jao
        root->right=deletefrombst(root->right,val);
        return root;
    }
}