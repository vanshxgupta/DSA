#include <bits/stdc++.h> 

//Memoization

// int f(int i,int j, vector<vector<int>>&dp){

// 	if(i==0 && j==0 ) return 1;
// 	if(i<0 ||j<0) return 0;

// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int up=f(i-1,j,dp);
// 	int down=f(i,j-1,dp);
// 	return dp[i][j]=up+down;

// }
// int uniquePaths(int m, int n) {
// 	vector<vector<int>>dp(m,vector<int>(n,-1));
// 	return f(m-1,n-1,dp);

// }






//Tabulation
// int uniquePaths(int m, int n) {

// 	int dp[m][n];
// 	dp[0][0]=1;


// 	for(int i=0;i<m;i++){
// 		for(int j=0;j<n;j++){
// 			if(i==0 && j==0) dp[i][j]=1;
//                         else {
// 							int up=0;
// 							int left=0;
							
//                           if (i > 0)
//                             up = dp[i - 1][j];
//                           if (j > 0)
//                             left = dp[i][j - 1];

//                           dp[i][j] = up + left;
//                         }
//                 }
// 	}

// 	return dp[m-1][n-1];

	

// }






//Tabulation(space optimised)
int uniquePaths(int m, int n) {

	vector<int>prev(n,0);
	vector<int>curr(n,0);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0) curr[j]=1;
            		else {
							int up=0;
							int left=0;

                          if (i > 0)
                            up = prev[j];
                          if (j > 0)
                            left = curr[j-1];

                          curr[j] = up + left;
                        }
                }
				prev=curr;
	}

	return prev[n-1];
	

	

}
