//detect cycle in a undirected graph and print of cycle

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

int start=-1;
int endi=-1;
bool dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&visited,vector<int>&parents){

    visited[node]=1;
    parents[node]=parent;
    
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,node,adj,visited,parents))return true;
        }
        else if(it!=parent){//has cycle
            start=it;
            endi=node;
            return true;
        }
    }
    return false;
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
        vector<int>parents(n+1,-1);
        bool hascycle=false;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited,parents)){
                    hascycle=true;
                    break;
                }
            }
        }
       if(hascycle==false){
        cout<<"IMPOSSIBLE"<<endl;
       }
       else{
            vector<int>path;
            int i=endi;
            path.push_back(start);
            while(i!=start)
            {
                path.push_back(i);
                i=parents[i];
            }
            path.push_back(start);
            reverse(path.begin(),path.end());
            
            cout<<path.size()<<endl;
            print(path);
       }
        

    return 0;
}
