#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long n,x;
	cin>>n>>x;
	
	long long mod=1000000007;
    
    vector<int>c(n);
    for(long long i=0;i<n;i++){
        cin>>c[i];
    }
    
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(long long j=0;j<n;j++){
            for(long long i=1;i<=x;i++){
            if(i-c[j]>=0)
            dp[i]=(dp[i]+dp[i-c[j]])%mod;
        }
    }
    
    cout<<dp[x]<<endl;
    
}