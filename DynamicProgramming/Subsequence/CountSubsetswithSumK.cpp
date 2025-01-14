//Tabulation
#define MOD 1000000007;
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if (arr[0] <= k) {
        dp[0][arr[0]] += 1;
    }

    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= k; sum++) {
            int nottake = dp[i - 1][sum];

            int take = 0;
            if (arr[i] <= sum) {
                take = dp[i - 1][sum - arr[i]];
            }

            dp[i][sum] = take + nottake;
			dp[i][sum]=dp[i][sum]%MOD;
        }
    }

    return dp[n - 1][k];
}
