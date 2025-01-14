#include <bits/stdc++.h> 

//MEMOIZATION

// int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){

//     //base case
//     if(i==0 && j==0){
//         return grid[i][j];
//     }

//     if(dp[i][j]!=-1) return dp[i][j];
//     int up=INT_MAX,left=INT_MAX;

//     if(i>0)
//      up=f(i-1,j,grid,dp)+grid[i][j];

//     if(j>0)
//      left=f(i,j-1,grid,dp)+grid[i][j];

//     return dp[i][j]=min(up,left);
    
// }

// int minSumPath(vector<vector<int>> &grid) {
    
//     int n=grid.size();
//     int m=grid[0].size();
//     vector<vector<int>>dp(n,(vector<int>(m,-1)));

//     return f(n-1,m-1,grid,dp);

// }




//TABULATION

// int minSumPath(vector<vector<int>> &grid) {
    
//     int n=grid.size();
//     int m=grid[0].size();
//     vector<vector<int>>dp(n,(vector<int>(m,-1)));

//     dp[0][0]=grid[0][0];

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){

//             if(i==0 && j==0) dp[i][j]=grid[i][j];

//             else{
//                 int up=INT_MAX;
//                 int left=INT_MAX;

//                 if(i>0)
//                 up=dp[i-1][j]+grid[i][j];
//                 if(j>0)
//                 left=dp[i][j-1]+grid[i][j];

//                 dp[i][j]=min(up,left);

//             }


//         }
//     }

//     return dp[n-1][m-1];

// }




//SPACE OPTIMIZATION

int minSumPath(vector<vector<int>> &grid) {
    
    int n=grid.size();
    int m=grid[0].size();
    vector<int>prev(m,0);

    vector<int>curr(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(i==0 && j==0) curr[j]=grid[i][j];

            else{
                int up=INT_MAX;
                int left=INT_MAX;

                if(i>0)
                up=prev[j]+grid[i][j];
                if(j>0)
                left=curr[j-1]+grid[i][j];

                curr[j]=min(up,left);

            }
            prev=curr;


        }
    }

    return prev[m-1];

}
