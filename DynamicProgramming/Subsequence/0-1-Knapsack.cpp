//MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;


// int solve(vector<int>& weight, vector<int>& value, int ind, int target,vector<vector<int>>& dp){
//     if(ind == 0){
//         if(weight[0] <= target) return value[0];
//         else return 0;
//     }

//     if(dp[ind][target] != -1) return dp[ind][target];
    
//     int nottake = 0 + solve(weight, value, ind - 1, target, dp);
//     int take = INT_MIN;
//     if(weight[ind] <= target){
//         take = value[ind] + solve(weight, value, ind - 1, target - weight[ind], dp);         
//     }
    
//     return dp[ind][target] = max(nottake, take);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
//     vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
//     return solve(weight, value, n-1, maxWeight, dp);
// }



//TABULATION

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
//     vector<vector<int>> dp(n , vector<int>(maxWeight + 1, 0));
	
// 	for(int i=weight[0];i<=maxWeight;i++) dp[0][i]=value[0];

//     for(int ind=1;ind<n;ind++){
//         for(int w=0;w<=maxWeight;w++){
//             int nottake=0+dp[ind-1][w];
//             int take=INT_MIN;
//             if(weight[ind]<=w){
//                 take=value[ind]+dp[ind-1][w-weight[ind]];

//             }
//             dp[ind][w]=max(nottake,take);
//         }
//     }
//     return dp[n-1][maxWeight];

// }




// //Space Optimisation(2 rows)
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
//     vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
	
// 	for(int i=weight[0];i<=maxWeight;i++) prev[i]=value[0];

//     for(int ind=1;ind<n;ind++){
//         for(int w=0;w<=maxWeight;w++){
//             int nottake=0+prev[w];
//             int take=INT_MIN;
//             if(weight[ind]<=w){
//                 take=value[ind]+prev[w-weight[ind]];

//             }
//             curr[w]=max(nottake,take);
//         }
//         prev=curr;
//     }
//     return prev[maxWeight];

// }




//Space Optimisation(1 row)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
	
	for(int i=weight[0];i<=maxWeight;i++) prev[i]=value[0];

    for(int ind=1;ind<n;ind++){
        for(int w=maxWeight;w>=0;w--){
            int nottake=0+prev[w];
            int take=INT_MIN;
            if(weight[ind]<=w){
                take=value[ind]+prev[w-weight[ind]];

            }
            prev[w]=max(nottake,take);
        }
    }
    return prev[maxWeight];

}
