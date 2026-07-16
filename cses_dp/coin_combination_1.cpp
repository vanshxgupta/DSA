#include <bits/stdc++.h>
using namespace std;
 
//dp[i]->number of distinct ways you can produce a money sum i using the available coins
// FORM 2
//SAME problem as minimizing coins , just there we have to mininnize , here we have to find the ways to form that sum
int main() {
	int n,x;
	cin>>n>>x;
	
	int mod=1000000007;
    
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0)
            dp[i]=(dp[i]+dp[i-c[j]])%mod;
        }
    }
    
    cout<<dp[x]<<endl;
    
}