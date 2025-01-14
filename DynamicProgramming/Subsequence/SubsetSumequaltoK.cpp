

//Memoization
#include <bits/stdc++.h> 

// bool f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
//     if(target==0 ) return true;
//     if(ind==0) return (arr[0]==target);

//     if(dp[ind][target]!=-1) return dp[ind][target];
//     bool nottake=f(ind-1,target,arr,dp);
//     bool take=false;
//     if(arr[ind]<=target) take=f(ind-1,target-arr[ind],arr,dp);
//     return dp[ind][target]= take|nottake;

// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>>dp(n,vector<int>(k+1,-1));
//     return f(n-1,k,arr,dp);

// }


//Tabulation

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
//     dp[0][0] = true;
//     dp[0][arr[0]] = true;

//     for (int i = 1; i < n; i++) {
//         dp[i][0] = true;
//         for (int target = 1; target <= k; target++) {
//             bool notTake = dp[i - 1][target];
//             bool take = false;
//             if (target >=arr[i] ) {
//                 take = dp[i - 1][target - arr[i]];
//             }
//             dp[i][target] = take || notTake;
//         }
//     }
    
//     return dp[n - 1][k];
// }


//Space optimisation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k + 1,0);
    vector<bool>curr(k + 1, 0);
    prev[0]=true;
    curr[0]=true;
    prev[arr[0]]=true;
    
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (target >=arr[i] ) {
                take = prev[target - arr[i]];
            }
            curr[target] = take |notTake;
        }
        prev=curr;
    }
    
    return prev[k];
}
