/ //RECURSIVE
// TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
// {
//    //base case
//    if(root==NULL){
//        return NULL;

//    }
//    if(root->data>P->data && root->data>Q->data){
//        return LCAinaBST(root->left,P,Q);
//    }
//    else if(root->data<P->data && root->data<Q->data){
//        return LCAinaBST(root->right,P,Q);
//    }


//    return root;
    

// }


//ITERATIVE
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
   //base case
   if(root==NULL){
       return NULL;

   }

   while(root!=NULL){
        if(root->data>P->data && root->data>Q->data){
            root=root->left;
   }
   else if(root->data<P->data && root->data<Q->data){
            root=root->right;
   }

   else {
            return root;
   }
   }


}