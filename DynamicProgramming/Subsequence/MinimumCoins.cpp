#include <bits/stdc++.h> 
//RECURSION
// int cnt=0;
// int solve(int ind,vector<int>&num,int target){
//     if(target==0){
//         return 0;
//     }

//     if(ind==0){
//       if (target%num[0]==0) {
//         return target/num[0];
//       } 
//       else
//         return INT_MAX;
//     }

//     int take=INT_MAX;

//     if(num[ind]<=target){
//         int solvi=solve(ind,num,target-num[ind]);
//         if(solvi!=INT_MAX){
//             take=1+solvi;
//         }
//     }
    
//     int nottake=0+solve(ind-1,num,target); 
//     return min(nottake,take);   

// } 

// int minimumElements(vector<int> &num, int x)
// {
    
//     int ans=solve(num.size()-1,num,x);
//     if(ans==INT_MAX){
//         return -1;
//     }
//     return ans;

// }



//MEMOIZATION
// int cnt=0;
// int solve(int ind,vector<int>&num,int target,vector<vector<int>>&dp){
//     if(target==0){
//         return 0;
//     }

//     if(ind==0){
//       if (target%num[0]==0) {
//         return target/num[0];
//       } 
//       else
//         return INT_MAX;
//     }
//     if(dp[ind][target]!=-1) return dp[ind][target];

//     int nottake=0+solve(ind-1,num,target,dp); 

//     int take=INT_MAX;
//     if(num[ind]<=target){
//         int solvi=solve(ind,num,target-num[ind],dp);
//         if(solvi!=INT_MAX){
//             take=1+solvi;
//         }
//     }
    
//     return dp[ind][target]= min(nottake,take);   

// } 

// int minimumElements(vector<int> &num, int x)
// {
//     vector<vector<int>>dp(num.size(),vector<int>(x+1,-1));
//     int ans=solve(num.size()-1,num,x,dp);
//     if(ans==INT_MAX){
//         return -1;
//     }
//     return ans;

// }



// //Tabulation
// int minimumElements(vector<int> &num, int x)
// {
//     int n=num.size();

//     vector<vector<int>>dp(num.size(),vector<int>(x+1,0));
//     for (int i = 0; i < n; i++) {
//       dp[i][0] = 0;
//     }

//     for(int i=1;i<=x;i++){
//       if (i % num[0] == 0) {
//           dp[0][i]=i/num[0];
//       } 
//       else
//         dp[0][i]=INT_MAX;
//     }
    
    
//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<=x;target++){
//             int nottake=0+dp[ind-1][target];
//             int take=INT_MAX;
//             if(num[ind]<=target){
//                 int solvi=dp[ind][target-num[ind]];
//                 if(solvi!=INT_MAX){
//                     take=1+solvi;
//                 }
//             }
//             dp[ind][target]=min(nottake,take);
//         }
//     }
//     if(dp[n-1][x]==INT_MAX){
//         return -1;
//     }
//     return dp[n-1][x];
      
// }


//Space optimisation
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();

    vector<int>prev(x+1,0);
    vector<int>curr(x+1,0);

    for(int i=1;i<=x;i++){
      if (i % num[0] == 0) {
          prev[i]=i/num[0];
      } 
      else
        prev[i]=INT_MAX;
    }
    
    
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=x;target++){
            int nottake=0+prev[target];
            int take=INT_MAX;
            if(num[ind]<=target){
                int solvi=curr[target-num[ind]];
                if(solvi!=INT_MAX){
                    take=1+solvi;
                }
            }
            curr[target]=min(nottake,take);
        }
        prev=curr;
    }
    if(prev[x]==INT_MAX){
        return -1;
    }
    return prev[x];
      
}