//bipartite graph check and if bipartite ,show the colors 

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
int n,m;

bool solve(int node,int color,vector<vector<int>>&adj,vector<int>&colors){
    colors[node]=color;
    
    for(auto &it:adj[node]){
        if(colors[it]==-1){
            if(!solve(it,1-color,adj,colors)){
                return false;
            }
        }
        else if(colors[it]==color){
            return false;
        }
    }
    return true;

}

int main() {
    fast_io;


          cin >> n>>m;

        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int u;
            int v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>colors(n+1,-1);

        bool flag=true;
        for (int i = 1; i <= n; i++) {
        if (colors[i] == -1) {
            if (!solve(i, 0, adj, colors)) {
                flag=false;
                break;
            }
        }
    }
        
        if(flag){
            for(int i=1;i<=n;i++){
                cout<<colors[i]+1<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
     
     

    return 0;
}
