
//USING TABULATION
// Time Complexity: O(n*k)
//  Space Complexity: O(n)



class Solution {
private:
    int solve(vector<int>& height, int n, int k, vector<int>& dp) {
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 1; j <= k ;j++) {
                if(i>=j){
                int fs = dp[i - j] + abs(height[i] - height[i - j]);
                mini = min(fs, mini);
                }
            }
            dp[i] = mini;
        }
        return dp[n - 1];
    }

public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n + 1, -1);
        return solve(height, n, k, dp);
    }
};