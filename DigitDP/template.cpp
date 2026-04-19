#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//STANDARD TEMPLATE
ll len;
ll dp[20][2][2];
ll dfs(ll pos,ll tight,ll leadingzero,string &digits){
    if(pos==len){
        return 1;
    }
    if(dp[pos][tight][leadingzero]!=-1){
        return dp[pos][tight][leadingzero];
    }
    ll ans=0;
    ll maxdigit=tight?(digits[pos]-'0'):9;
    for(ll d=0;d<=maxdigit;d++){
        ll nexttight=(tight && d==maxdigit);
        ll nextleadingzero=(leadingzero && (d==0));
        ans+=dfs(pos+1,nexttight,nextleadingzero,digits);
    }
    return dp[pos][tight][leadingzero]=ans;
}

ll solve(ll val){
    memset(dp,-1,sizeof(dp));
    string digits=to_string(val);
    len=digits.size();
    return dfs(0,1,1,digits);
}

int main(){
    long long a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1)<<endl;
}