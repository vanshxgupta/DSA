
//In this question the memoization and tabulation are done from different methods
//Memoization
bool f(int ind,int sum,int remainingsum,vector<int> &arr,vector<vector<int>>&dp){

	int n=arr.size();

	if(sum==remainingsum){
		return true;
	}
	if(ind>=n){
		return false;
	}

	if(dp[ind][sum]!=-1) return dp[ind][sum];

	//keep
	bool keep=f(ind+1,sum+arr[ind],remainingsum-arr[ind],arr,dp);

	//leave
	bool leave=f(ind+1,sum,remainingsum,arr,dp);

	return dp[ind][sum]=keep|| leave; 
}

bool canPartition(vector<int> &arr, int n)
{
	int totalsum=0;
	vector<vector<int>>dp(n,vector<int>(1e4,-1));
	for(int i=0;i<n;i++){
		totalsum+=arr[i];
	}
	return f(0,0,totalsum,arr,dp);

}



//Tabulation
class Solution {

    bool f(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base cases
        dp[0][0] = true;
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            dp[i][0] = true;
            for (int j = 1; j <= target; j++) {
                bool nottake = dp[i-1][j];
                bool take = false;
                if (nums[i] <= j) {
                    take = dp[i-1][j - nums[i]];
                }
                dp[i][j] = take || nottake;
            }
        }

        return dp[n-1][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        return f(nums, target);
    }
};
