//BINARY LIFTING 

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

int n,q;
int main() {
    fast_io;

    cin>>n>>q;

    vector<int>parent(n+1,-1);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        parent[i+1]=val;
    }

    vector<vector<int>>dp(n+1,vector<int>(31,-1));

    //base case
    for(int i=1;i<=n;i++){//steps=2^0=1
        dp[i][0]=parent[i];
    }

    //transition
    for(int steps=1;steps<=30;steps++){//2^steps
        for(int i=1;i<=n;i++){
            if(dp[i][steps-1]!=-1){
                dp[i][steps]=dp[dp[i][steps-1]][steps-1];
            }
        }
    }

    //queries
    for(int i=0;i<q;i++){
        int node;
        int k;
        cin>>node>>k;

        for(int j=0;j<=30;j++){
            if(node==-1){
                break;
            }
            if((1<<j)&k){
                node=dp[node][j];
            }
        }
        cout<<node<<'\n';   // <-- important change , endl is slow , it flushes the output everytime
    }

    return 0;
}
