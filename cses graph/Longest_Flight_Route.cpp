//Dp over DAG->dp + toposort
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

int main() {
    fast_io;

    int n,m;
    cin >> n>>m;

    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1);

    //we need a well processing order to do dp over it , we cannot directly do dfs, bfs, that is why we are first making a toposort order , and then we will do dp over it 
    // dp[v]->reprsents the length of the longest route from 1 to v

    //toposort
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        indegree[v]++;
    }

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
    
    //dp
    vector<int>dp(n+1,INT_MIN);
    dp[1]=1;
    vector<int>parent(n+1,-1);
    
    // Each edge is processed once ->O(n + m)
    for(auto &node:toposort){
        if(dp[node]==INT_MIN){
            continue;
        }
        for(auto &it:adj[node]){
            if(dp[node]+1>dp[it]){//previous path chota tha , aur bda mil skta hai tooh bade se update karo
                dp[it]=dp[node]+1;
                parent[it]=node;//update the path also
            }
        }
    }

    if(dp[n]==INT_MIN){
        //path do not exist
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    else{
        vector<int>path;
        int i=n;
        while(i!=-1){
            path.push_back(i);
            i=parent[i];
        }
        cout<<path.size()<<endl;
        reversi(path);
        print(path);
    }

 
    return 0;
}
