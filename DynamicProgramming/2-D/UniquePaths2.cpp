//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 ||obstacleGrid[0][0]==1) return 0;
        int dp[m][n];
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                            else {
                                int up=0;
                                int left=0;
                                
                            if (i > 0 && obstacleGrid[i-1][j]==0)
                                up = dp[i - 1][j];
                            if (j > 0 && obstacleGrid[i][j-1]==0)
                                left = dp[i][j - 1];

                            dp[i][j] = up + left;
                            }
                    }
        }

        return dp[m-1][n-1];

    }
};