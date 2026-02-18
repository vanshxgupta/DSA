
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
 
#define input2D(a,n,m) for(long long _i=0;_i<n;_i++) for(long long _j=0;_j<m;_j++) cin >> a[_i][_j];

// vector<vector<long long>> mat(n, vector<long long>(m));
//  input2D(mat, n, m);  
 
 
typedef long long ll;
 
long long n,m;

int main() {
    fast_io;

    cin >> n>>m; 

    vector<vector<ll>>adj(n+1);
    vector<vector<long long>>graph;
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long len;
        cin>>u>>v>>len;
        adj[u].push_back(v);
        graph.push_back({u,v,len});
    }

    vector<long long>dist(n+1,0);//we don't have any source , tooh we have made everyone the source
    //bellaman ford

    vector<int>relaxant(n+1,-1);

    int x=-1;
    //n times relaxation
    for(int i=0;i<n;i++){
        x=-1;//nth relaxation mai bhi agar distance 0 se kam hua ,mtlab negative cycle exists
        for(auto &it:graph){
            ll u=it[0];
            ll v=it[1];
            ll len=it[2];

            if(dist[u]!=LLONG_MAX && dist[v]>dist[u]+len){
                dist[v]=dist[u]+len;
                relaxant[v]=u;
                x=v;
            }
        }
    }

    if(x==-1){
        no;
    }
    else{

        //move back n times to find the loop 
        int a=x;
        for(int i=0;i<n;i++){
            a=relaxant[a];
        }

        vector<int>cycle;
        for(int curr=a;;curr=relaxant[curr]){
            cycle.push_back(curr);
            if(curr==a && cycle.size()>1){
                break;
            }
        }

        reversi(cycle);
        yes;
        print(cycle);

        
    }

    return 0;
}