#include<bits/stdc++.h>
#include<iostream>
using namespace std;


//using memoization 
//t.c-->o(n);
//s.c-->o(2n);
// int f(int n,vector<int>&dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];

//     return dp[n]=f(n-1,dp)+f(n-2,dp);

// }

// int main(){

//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);

//     cout<<f(n,dp);
//     
//     return 0;
// }



//Using tabulation
// int main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     dp[0]=0;
//     dp[1]=1;

//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];

//     }
//     cout<<dp[n];

//     return 0;
// }




//Using tabulation with space optimisation
int main(){
    int n;
    cin>>n;
    int prev2=0;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int curri=prev1+prev2;  
        prev2=prev1;
        prev1=curri;
    }
    cout<<prev1;
    return 0;

}