// Ask: "From which sums can I reach the current sum?"
// I can come from sum-1, sum-2, ..., sum-6.
// Add the ways of all these previous sums.
// Base: dp[0] = 1 (one way to make sum 0).

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
int mod=1e9+7;

int dp[1000001];
int solve(int n){
    if(n==0) return 1;
    if(n==1){
        return 1;
    }

    if(dp[n]!=-1) return dp[n];

    int ways=0;
    for(int i=1;i<=6;i++){
        if(n>=i)
            ways=(ways+solve(n-i))%mod;
    }
    return dp[n]=ways%mod;
}

int main() {
    fast_io;

    //we have infinte amount of single coin

    //we will be using the form 2 in this problem 
    // try to think  , if we wannt to come to sum , from where all paths i can reach it ? i an reach it from sm-1 , sum-2 , sum-3......suum-6 
    //so oour transiotion is dp[sum]= for (i from 1 to 6)->summation of dp[sum-i]

    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));

    cout<<solve(n)<<endl;

    return 0;
}
