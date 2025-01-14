//Partition a set into two subsets such that the differnce of subset sums is minmum

//Memoization
// int subsetMin(vector<int>& arr, int n, int pathsum, int sum, vector<vector<int>>&dp)
// {
// 	// No more elements to explore along this depth of the recursion tree.
// 	if (n == 0) {
// 		return abs(sum - 2 * pathsum);//ye formula kese aaya -->s2=sum-s1 , s1=pathsum tooh s2-s1=sum-2*pathsum;
// 	}

//     if(dp[n][pathsum] != -1) return dp[n][pathsum];
// 	// For each element we have two choices either to include it in the subset or not.
// 	// So here we explore both the possibilities and choose the one which gives us the min subset sum difference.
// 	return dp[n][pathsum] = min(subsetMin(arr, n - 1, pathsum + arr[n - 1], sum, dp), subsetMin(arr, n - 1, pathsum, sum, dp));
// }

// int minSubsetSumDifference(vector<int>& arr, int n)
// {
// 	int sum = 0;
// 	for (int i = 0; i < n; i++) {
// 		sum += arr[i];
// 	}
//     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1)); // changed k to sum
// 	return subsetMin(arr, n, 0, sum, dp);
// }



//Tabulation
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum=0;
    for(int i=0;i<n;i++) totalsum+=arr[i];

    int k=totalsum;
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    
    if(arr[0]<=k)dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take | nottake;

        }
    }

    //finding the minimum
    int mini=1e8;
    for(int s1=0 ;s1<=totalsum/2;s1++){
        if(dp[n-1][s1]==true){
            int s2=totalsum-s1;
            mini=min(mini,abs(s2-s1));

        }
    }
    return mini;



}

//Space optimisation
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum=0;
    for(int i=0;i<n;i++) totalsum+=arr[i];

    int k=totalsum;
    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;

    
    if(arr[0]<=k)prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=prev[target];
            bool take=false;
            if(arr[ind]<=target) take=prev[target-arr[ind]];
            curr[target]=take | nottake;

        }
        prev=curr;
    }

    //finding the minimum
    int mini=1e8;
    for(int s1=0 ;s1<=totalsum/2;s1++){
        if(prev[s1]==true){
            int s2=totalsum-s1;
            mini=min(mini,abs(s2-s1));

        }
    }
    return mini;



}
