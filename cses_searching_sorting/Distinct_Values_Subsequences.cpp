#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define prlong long(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
#define reversi(a) reverse(a.begin(), a.end())
 
#define input2D(a,n,m) for(long long _i=0;_i<n;_i++) for(long long _j=0;_j<m;_j++) cin >> a[_i][_j];
#define prlong long2D(a,n,m) for(long long _i=0;_i<n;_i++){ for(long long _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }
 
// vector<vector<long long>> mat(n, vector<long long>(m));
//  input2D(mat, n, m);  
 
 
typedef long long ll;
 
int main() {
    fast_io;
 
 
    long long n;
    cin >>n;
 
    vector<long long> p(n);
    input(p);
   
    long long cnt=0;
    
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[p[i]]++;
    }
    
    int mod=1e9+7;
    
    long long ans=1;
    for(auto &it:mp){
        ans=(ans*(it.second+1)%mod)%mod;
    }
    
    cout<<(ans - 1+mod)%mod<<endl;
    
    return 0;
}