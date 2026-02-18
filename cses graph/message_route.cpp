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
        
    vector<int>dist(n+1,-1);
    
    queue<int>q;

    vector<int>parenttracker(n+1,-1);
    
    q.push(1);
    dist[1]=1;
    bool found=false;
    while(!q.empty()){
        int sizi=q.size();
        
        for(int i=0;i<sizi;i++){
            int node=q.front();
            q.pop();
            
            if(node==n){
                found=true;
                break;
            }
            
            for(auto &it:adj[node]){
                if(dist[it]==-1){
                    dist[it]=dist[node]+1;
                    parenttracker[it]=node;
                    q.push(it);
                }
            }
        }
        if(found==true){
            break;
        }
    }
    
    if(found){
        cout<<dist[n]<<endl;
        int i=n;
        vector<int>route;
        route.push_back(n);
        while(i!=1){
            route.push_back(parenttracker[i]);
            i=parenttracker[i];
        }

        reverse(route.begin(),route.end());
        print(route);
    }
    else{
        cout<<"IMPOSSIBLE"<<endlbu;
    }
   
    return 0;
}