#include<bits/stdc++.h>
using namespace std;

//Question:
// count numbers 0....n that do not contain 4

int len;
int dp[20][2];
int dfs(int pos,int tight,string &digits){
    if(pos==len){
        return 1;
    }
    if(dp[pos][tight]!=-1){
        return dp[pos][tight];
    }
    int ans=0;
    int maxdigit=tight?(digits[pos]-'0'):9;
    for(int d=0;d<=maxdigit;d++){
        if(d==4) continue;
        int nexttight=(tight && d==maxdigit);
        ans+=dfs(pos+1,nexttight,digits);
    }
    return dp[pos][tight]=ans;
}

int count(int val){
    memset(dp,-1,sizeof(dp));
    string digits=to_string(val);
    len=digits.size();
    return dfs(0,1,digits);
}

int main(){
    int n;
    cin>>n;
    cout<<count(n)<<endl;
}