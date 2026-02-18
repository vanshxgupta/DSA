//floyd warshall algorithm

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
 
typedef long long ll;
long long n,m,q;
int main() {
    fast_io;
    cin>>n>>m>>q;

    //dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]));

    vector<vector<long long>>graph;
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long len;
        cin>>u>>v>>len;
        graph.push_back({u,v,len});
        graph.push_back({v,u,len});
    }
    
    vector<vector<long long>>dist(n+1,vector<ll>(n+1,LLONG_MAX));

    long long gs=graph.size();
    for(long long i=0;i<gs;i++){
        long long u=graph[i][0];
        long long v=graph[i][1];
        long long len=graph[i][2];

        dist[u][v]=min(dist[u][v],len);
        dist[v][u]==min(dist[u][v],len);  //taking minium becuase , there can be multiple roads , of different length 
    }
    //base case of floud warshal
    for(long long i=1;i<=n;i++){
       dist[i][i]=0;
    }

    for(long long k=1;k<=n;k++){
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
  


    while(q--){
        long long u;
        long long v;
        cin>>u>>v;

        if(dist[u][v]>=LLONG_MAX){
            cout<<-1<<endl;
            continue;
        }
        cout<<dist[u][v]<<endl;
    }
    
    return 0;
}