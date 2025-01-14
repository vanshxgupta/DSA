//     int height(struct Node* node){
//         //base case
//         if(node==NULL){
//             return 0;
//         }
        
//         int left=height(node->left);
//         int right=height(node->right);
        
//     return max(left,right)+1;
//     }
    

// int diameter(Node*  root){
//     //base case
//     if(root==NULL){
//         return 0;
//     }

//     int op1=diameter(root->left);
//     int op2=dimater(root->right);
//     int op3=height(root->left)+height(root->right)+1;

//     int ans=max(op1,max(op2,op3));
//     return ans;

// }

//OPTIMISED APPROACH

pair<int,int> diameterfast(Node*root){
    //base case
    if(root==NULL){
        pair<int,int> p =make_pair(0,0);//diameter aur height dono hi ek saath return krva rahe hai
        return p;

    }

    pair<int,int> left=diameterfast(root->left);
    pair<int,int> right=diameterfast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3= left.second+right.second + 1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;

    return ans;

}

int diameter(Node*  root){

    return diameterfast(root).first;
}