// //APPROACH 1:
// class Solution{
//     void solve(Node*root,int k,int &count, vector<int > path){
//         if(root==NULL){
//             return ;
            
//         }
//         path.push_back(root->data);
        
//         //left
//         solve(root->left,k,count,path);
//         //right
//         solve(root->right,k,count,path);
        
//         //check for Ksum
        
//         int size=path.size();
//         int sum=0;
//         for(int i=size-1;i>=0;i--){
//             sum+=path[i];
//             if(sum==k){
//                 count++;
                
//             }
//         }
        
//         path.pop_back();
        
        
        
//     }
//   public:
//     int sumK(Node *root,int k)
//     {
//         vector<int> path;
//         int count=0;
//         solve(root,k,count,path);
//         return count;
//     }
// };


//APPROACH 2:OPTIMISED

class Solution{
  public:
  unordered_map<int,int>mp;//will be storing the frequency of prefixsum
  
  
  void solve(Node*root,int k, int sum,int &ans){
     
     if(!root) return;
     sum+=root->data;
     ans+=mp[sum-k];//ans mai add krdo map mai jitni bhi frequency padi hai us element ki , agar kuch frquency nahi hai tooh  0 chali jayegi , tension mat lo
     mp[sum]++;//jo prefix sum aya hai uski frequency ko increase krne ke liye 
     
     solve(root->left,k,sum,ans);
     solve(root->right,k,sum,ans);
     
     mp[sum]--;
     
  }
  
  
    int sumK(Node *root,int k)
    {
       int ans=0;
       mp[0]=1;
       solve(root,k,0,ans);
       return ans;
       
       
    }
};