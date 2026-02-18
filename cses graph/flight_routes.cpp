#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
 
#define input2D(a,n,m) for(long long _i=0;_i<n;_i++) for(long long _j=0;_j<m;_j++) cin >> a[_i][_j];

// vector<vector<long long>> mat(n, vector<long long>(m));
//  input2D(mat, n, m);  
 
typedef pair<long long,long long> pii;
typedef long long ll;
 
long long n,m;

int main() {
    fast_io;
    int k;
    cin >> n>>m>>k;

    vector<vector<pair<long long,long long>>>adj(n+1);
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long len;
        cin>>u>>v>>len;
        adj[u].push_back({v,len});
    }

    vector<vector<long long>>dist(n+1);//to store the k shortest distances in all the nodes 
    priority_queue<pii,vector<pii>,greater<pii>>q;
    //{distance,node}

    q.push({0,1});
    // dist[1].push_back(0);->this is wrong , idhar nahi likha hai ye 

    while(!q.empty()){
        long long node=q.top().second;
        long long length=q.top().first;
        q.pop();

        if(dist[node].size()>=k) continue;
        dist[node].push_back(length);
       
        for(auto &it:adj[node]){
            ll nextnode=it.first;
            ll weight=it.second;
            q.push({weight+length,nextnode});
        }
    }   
    
    print(dist[n]);

    return 0;
}