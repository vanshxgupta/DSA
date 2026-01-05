//leetcode 1025
class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                if(solve(n-i,dp)==0){//if any of them losses , then solve(x) will win 
                    ans=1;
                    break;
                }
            }
        }
        return dp[n]=ans;

    }
    bool divisorGame(int n) {

        // dp(x)->win/loose
        // if any of the dp(n-x) losses  then dp(x) will win 
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
    }
};