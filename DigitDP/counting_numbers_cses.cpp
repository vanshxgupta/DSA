#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll len;
ll dp[20][2][2][11];
ll dfs(ll pos,ll tight,ll leadingzero,ll prevdigit,string &digits){
    if(pos==len){
        return 1;
    }
    if(dp[pos][tight][leadingzero][prevdigit]!=-1LL){
        return dp[pos][tight][leadingzero][prevdigit];
    }
    ll ans=0;
    ll maxdigit=tight?(digits[pos]-'0'):9;
    for(ll d=0;d<=maxdigit;d++){
        if(leadingzero==0 && d==prevdigit){//leading zero na ho aur d==prevdigit ho tabhi continue krna , vrna 1,2,3...chutt jayenge agar direct d==prevdigit likha tooh
            continue;
        }
        ll nexttight=(tight && d==maxdigit);
        ll nextleadingzero=(leadingzero && (d==0));
        ll newprevdigit=d;
        ans+=dfs(pos+1,nexttight,nextleadingzero,newprevdigit,digits);
    }
    return dp[pos][tight][leadingzero][prevdigit]=ans;
}

ll solve(ll val){
    memset(dp,-1,sizeof(dp));
    string digits=to_string(val);
    len=digits.size();
    return dfs(0,1,1,10,digits);
}

int main(){
    long long a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1)<<endl;
}