// This is equivalent to:

// Longest path in directed graph with possible cycles
// → Convert to shortest path by negating weights
// → Detect negative cycles that affect node n

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
 
long long n,m;

int main() {
    fast_io;

    cin >> n>>m;
    
    //room 1 to n jaane ka ->max score 

    vector<vector<ll>>adj(n+1);
    vector<vector<long long>>graph;
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long len;
        cin>>u>>v>>len;
        adj[u].push_back(v);
        graph.push_back({u,v,-len});//-ve len daaldo aur minimum nikalo , fir answer return krte time vapis -ve krke answer do , tooh maximum ban jaayega 
    }

    vector<long long>dist(n+1,LLONG_MAX);
    dist[1]=0;//source node distance as

    //bellaman ford

    //n-1 relaxtions
    for(int i=0;i<n-1;i++){
        for(auto &it:graph){
            ll u=it[0];
            ll v=it[1];
            ll len=it[2];

            if(dist[u]!=LLONG_MAX && dist[v]>dist[u]+len){
                dist[v]=dist[u]+len;
            }
        }
    }

    set<int>st;
    //detect negative cycles
    for(auto &it:graph){
        ll u=it[0];
        ll v=it[1];
        ll len=it[2];

        if(dist[u]!=LLONG_MAX && dist[v]>dist[u]+len){
            st.insert(v);
        }
    }

    //find which are the number of nodes that can be reached from 1 to node
    queue<int>q;
    q.push(1);
    vector<int>visited(n+1,0);

    set<int>reachable;

    while(!q.empty()){
        int nodi=q.front();
        q.pop();
        if(st.count(nodi)){
            reachable.insert(nodi);
        }
        
        for(auto &it:adj[nodi]){
            if(!visited[it]){
                visited[it]=true;
                q.push(it);
            }
        }
    }
    
    //now check if the reachable nodes can reach nn or not 
    queue<int>q1;
    for(auto &it:reachable){
        q1.push(it);
    }

    vector<int>visited1(n+1,0);
    bool flag=false;
    while(!q1.empty()){
        int nodi=q1.front();
        q1.pop();

        if(nodi==n){
            flag=true;
            break;
        }

        for(auto &it:adj[nodi]){
            if(!visited1[it]){
                visited1[it]=true;
                q1.push(it);
            }
        }
    }

    if(flag){
        cout<<-1<<endl;
    }
    else{
        cout<<-dist[n]<<endl;
    }
    return 0;

}