//dp over dag->dp+toposort
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
ll m,n;

vector<int> findtoposort(vector<vector<int>>&adj,vector<int>&visited,vector<int>&indegree){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>toposort;
    while(!q.empty()){
        int fronti=q.front();
        toposort.push_back(fronti);
        q.pop();

        for(auto it:adj[fronti]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return toposort;
}

int main() {
    fast_io;
    cin >> n>>m;

    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1);
    vector<int>visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    vector<int>toposort=findtoposort(adj,visited,indegree);

    //dp on the toposort order
    // dp[n]->no.of ways to reach nth level from 1st level
    vector<int>dp(n+1);
    dp[1]=1;

    for(auto &node:toposort){
        if(dp[node]==INT_MIN){
            continue;
        }
        for(auto &it:adj[node]){
            dp[it]=(dp[it]+dp[node])%mod;
        }
    }

    if(dp[n]==INT_MIN){
        cout<<0<<endl;
    }
    else{
        cout<<dp[n]%mod<<endl;
    }

    return 0;
}
