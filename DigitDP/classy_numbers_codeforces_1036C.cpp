#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll n;
ll dp[40][2][2][4];
ll dfs(string &s,ll pos,ll tight,ll leadingzeroes, ll cntofnonzerodigits){
   
    if(cntofnonzerodigits>3){ //pruning
        return 0;
    }

    if(pos==n){ //base case
        if(cntofnonzerodigits<=3){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[pos][tight][leadingzeroes][cntofnonzerodigits]!=-1){
        return dp[pos][tight][leadingzeroes][cntofnonzerodigits];
    }

    ll limit=tight?(s[pos]-'0'):9;
    ll ans=0;
    for(ll d=0;d<=limit;d++){
        ll nexttight=(tight && d==limit);
        ll nextleadingzeroes = (leadingzeroes && d==0);

        //leading zeros are not counted as non zero digits
        ll nextcntofnonzerodigits =cntofnonzerodigits+(d!=0 && !nextleadingzeroes);
        ans+=dfs(s,pos+1,nexttight,nextleadingzeroes,nextcntofnonzerodigits);
    }

    return dp[pos][tight][leadingzeroes][cntofnonzerodigits]=ans;
}
ll solve(ll val){
    memset(dp,-1,sizeof(dp));
    string s=to_string(val);
    n=s.size();
    return dfs(s,0,1,1,0); // string , pos , tight , leadingzeroes, numberof(non-zero)digits
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;

        cout<<solve(r)-solve(l-1)<<endl;
       
    }
}