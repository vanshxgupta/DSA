#include<limits.h>

//MEMOIZATION
// #include<bits/stdc++.h>
// using namespace std;

// int f(int i,int j,vector<vector<int>> &matrix,int n,int m, vector<vector<int>>& dp){
//     if(i==0) return matrix[i][j];
//     if(j<0 || j>=m) return INT_MIN;
//     if(dp[i][j] != -1) return dp[i][j];

//     int u=matrix[i][j]+f(i-1,j,matrix,n,m,dp);
//     int ld=INT_MIN, rd=INT_MIN;
//     if(j-1 >= 0) ld = matrix[i][j]+f(i-1,j-1,matrix,n,m,dp);
//     if(j+1 < m) rd = matrix[i][j]+f(i-1,j+1,matrix,n,m,dp);

//     return dp[i][j] = max(u,max(ld,rd));
// }

// int getMaxPathSum(vector<vector<int>> &matrix){
//     int n=matrix.size();
//     int m=matrix[0].size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     int maxi=INT_MIN;
//     for(int j = 0; j < m; j++) {
//         int a= f(n - 1, j, matrix, n, m, dp);
//         if(a > maxi) {
//             maxi = a;
//         }
//     }
//     return maxi;
// }



//TABULATION
int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j = 0; j < m; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++) {
            int u = matrix[i][j] + dp[i - 1][j];
            int ld = -1e8, rd = -1e8;
            if(j - 1 >= 0) ld = matrix[i][j] + dp[i - 1][j - 1];
            if(j + 1 < m) rd = matrix[i][j] + dp[i - 1][j + 1];
            dp[i][j] = max(u, max(ld, rd));
        }
    }

    int maxi = INT_MIN;
    for(int j = 0; j < m; j++) {
        if(dp[n - 1][j] > maxi) {
            maxi = dp[n - 1][j];
        }
    }
    return maxi;
}

