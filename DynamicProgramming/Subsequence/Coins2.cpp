
//TABULATION
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));

        for(int ind=0;ind<n;ind++){
        dp[ind][0]=0;//target 0 ho gya hai tooh koi coin lene ki jaururt nahi hai 
        }

        for(int target=1;target<=amount;target++){
                int nottake=0;
                int ind=0;
                    if(target%coins[ind]==0){
                        dp[0][target]=target/coins[ind];//itne no. of coins le skte  hai agar ind=0 ka coin target ke barabar hai tooh
                   }
        }


        for(int i=1;i<n;i++){
            for(int target=1;target<=amount;target++){
                int nottake=dp[i-1][target];
                int take=1e9;
                if(target>=coins[i]){
                    take=1+dp[i][target-coins[i]];//taking the coin mai +1
                }
                dp[i][target]=min(nottake,take);
            }
        }
        int ans=dp[n-1][amount];
        if(ans==1e9){
            return -1;
        }
        return ans;

    }
};