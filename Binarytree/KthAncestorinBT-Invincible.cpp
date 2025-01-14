//APPROACH-1

// void solve(Node* root, int k, int node, vector<int>& path, int& ans) {
//     if (root==NULL)
//         return;
        
//     if(ans==0){ 
//         path.push_back(root->data);
//     }
    
    
//     solve(root->left, k, node, path, ans);
//     solve(root->right, k, node, path, ans);

//     if (root->data == node) {
//         int temp = k;
//         while (!path.empty() && temp > 0) {
//             path.pop_back();
//             temp--;
//         }
        
//         if (!path.empty())
//             ans = path.back();
//         else
//             ans = -1; // Reset ans to -1 if path is empty
//     } 
    
//     else if(ans==-1) return;
    
//     else path.pop_back();
// }

// int kthAncestor(Node* root, int k, int node) {
//     vector<int> path;
//     int ans = 0;
//     solve(root, k, node, path, ans);
//     if(ans==0) return -1;
//     return ans;
// }


//APPROACH 2:USING RECURSION

Node* solve(Node*root,int &k,int node){
    //base  case
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
        
    }

    Node*leftans=solve(root->left,k,node);
    Node*rightans=solve(root->right,k,node);
    
    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k<=0){
            
            //answer lock kardiya
            k=INT_MAX;//ye isliye kiya hai kyunki , ek baar k zero bnne ke baad vapis se na ban paye jab ham k-- krenge tooh 
            return root;
            
        }

        return leftans;
    }
    if(leftans==NULL && rightans!=NULL){
        k--;
        if(k<=0){
            
            //answer lock kardiya
            k=INT_MAX;
            return root;
            
        }

        return rightans;
    }
    return NULL;
    
}
int kthAncestor(Node* root, int k, int node) {
    
    Node*ans=solve(root,k,node);

    if(ans==NULL){
        return -1;
    }
    if(ans->data==node){//(edge case)agar apni root node matlab first wali hi node ke equal hai tooh return kardo -1;
        return -1;
        
    }
    else{
        return ans->data;
    } 
}


