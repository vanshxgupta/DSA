// class Solution{
//     private:
//         int height(struct Node* node){
//         //base case
//         if(node==NULL){
//             return 0;
//         }
        
//         int left=height(node->left);
//         int right=height(node->right);
        
//     return max(left,right)+1;
//     }
//     public:
//     //Function to check whether a binary tree is balanced or not.
//     bool isBalanced(Node *root)
//     {
//     //base case
//     if(root==NULL){
//         return true;
//     }
//     bool left=isBalanced(root->left);
//     bool right=isBalanced(root->right);
//     bool diff=abs(height(root->left)-height(root->right))<=1;
    
//     if(left&&right&&diff){
//         return true;
        
//     }
//     else{
//         return false;
        
//     }
//     }
// };

//OPTIMISED
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
        // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;//left.second is the height of left subtree and right.second is the height of right subtree
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    
};