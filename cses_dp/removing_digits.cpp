#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
#define reversi(a) reverse(a.begin(), a.end())

#define input2D(a,n,m) for(int _i=0;_i<n;_i++) for(int _j=0;_j<m;_j++) cin >> a[_i][_j];
#define print2D(a,n,m) for(int _i=0;_i<n;_i++){ for(int _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);  
typedef long long ll;

int dp[1000001];
int solve(int n){
    //base case 
    if(n==0) return 0;

    //memo check 
    if(dp[n]!=-1) return dp[n];

    string s=to_string(n);
    int ans=INT_MAX;
    for(auto &it:s){
        if(it-'0' == 0) continue;
        if(n>=(it-'0'))
        ans=min(ans,1+solve(n-(it-'0')));
    }
    return dp[n]=ans;
}
int main() {
    fast_io;

    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));

    cout<<solve(n)<<endl;
    // print(dp);
    
    return 0;
}
