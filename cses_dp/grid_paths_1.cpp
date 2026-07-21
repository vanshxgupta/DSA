#include <bits/stdc++.h>
using namespace std;
 
//state->dp[i][j]->no. of paths from (0,0) to (i,j)
 
//dp[0][0]=1;
//transition equation->dp[i][j]=d[i-1][j]+dp[i][j-1];//with no obstacle
//obstacle aaya tooh uspe jaane ke paths 0 ,i.e obstacles ka dp[i][j]=0;
 
int main() {
	int n;
	cin>>n;
	
	int mod=1000000007;
    
    vector<vector<char>>grid(n,vector<char>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!='*'){
            if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    
    cout<<dp[n-1][n-1]%mod<<endl;
    
}
