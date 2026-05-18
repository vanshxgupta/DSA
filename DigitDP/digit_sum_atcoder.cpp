#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod=1e9+7;
ll len;
string s;
int D;
ll dp[10005][2][101];
ll dfs(ll pos,ll tight,ll summod,string &digits){
    if(pos==len){
        if(summod%D==0){
            return 1;
        }
        else return 0;
    }
    if(dp[pos][tight][summod]!=-1){
        return dp[pos][tight][summod];
    }
    ll ans=0;
    ll maxdigit=tight?(digits[pos]-'0'):9;
    for(ll d=0;d<=maxdigit;d++){
        ll nexttight=(tight && d==maxdigit);
        ans=(ans+dfs(pos+1,nexttight,(summod+d)%D,digits))%mod;
    }
    return dp[pos][tight][summod]=ans;
}

ll solve(string &digits){
    memset(dp,-1,sizeof(dp));
    len=digits.size();
    return dfs(0,1,0,digits);
}

int main(){
    cin>>s;
    cin>>D;
    // cout<<solve(s)-1<<endl;
    //solve()-1 cause  we have to find the values from 1 to k ,
    //  but we are calling dfs from 0 ... so 0 will also be included in it ,so we subtract it  
    cout<<(solve(s)-1+mod)%mod <<endl;
}