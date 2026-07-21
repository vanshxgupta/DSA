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


int mod=1e9+7;
typedef long long ll;

int dp[100001][101];
int n;
int m;
int solve(int ind,int prev,vector<int>&a){
    if(prev>m || prev<1) return 0;
    
    if(ind==n){
        return 1;
    }
    if(a[ind]!=0)
    if(abs(a[ind]-prev)>1) return 0;
    
    //memo chck
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    
    int ways=solve(ind+1,a[ind],a);
    if(a[ind]==0){
        for(int i=-1;i<=1;i++){
            ways=(ways+solve(ind+1,prev+i,a))%mod;
        }
    }

    return dp[ind][prev]=ways%mod;
}

int main() {
    fast_io;

    cin >> n>>m;

    vector<int> a(n);
    input(a);
    memset(dp,-1,sizeof(dp));
    
    int ways=0;
    if(a[0]==0){
        for(int i=1;i<=m;i++){
            ways=(ways+solve(1,i,a))%mod;
        }
    }
    else{
        ways=(ways+solve(1,a[0],a))%mod;
    }

    cout<<ways%mod<<endl;
    

    return 0;
}
