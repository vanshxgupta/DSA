#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())

#define input2D(a,n,m) for(int _i=0;_i<n;_i++) for(int _j=0;_j<m;_j++) cin >> a[_i][_j];
#define print2D(a,n,m) for(int _i=0;_i<n;_i++){ for(int _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);  


typedef long long ll;

void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
    if(visited[node]){
        return ;
    }
    visited[node]=1;
    
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}

int main() {
    fast_io;

        int n,m;
        cin >> n>>m;

        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int u;
            int v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(n+1,0);
        
        vector<pair<int,int>>roads;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(i!=1){
                    roads.push_back({i-1,i});
                }
                dfs(i,adj,visited);
            }
        }
        
        int cnt=roads.size();
        cout<<cnt<<endl;
        for(auto &it:roads){
            cout<<it.first<<" "<<it.second<<endl;
        }
        
        

    return 0;
}
