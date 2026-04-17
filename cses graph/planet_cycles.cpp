//CYCLES LENGTH USING DFS

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
int n,q;
int cyclestart=-1;
void dfs(vector<int>&parent,vector<int>&visited,vector<int>&cyclelength,vector<int>&distance,int pos,int node){
    visited[node]=1;

    //ek hi parent(ngr) hai , tooh uspe chale jao
    if(parent[i]==-1){
        return;
    }
    if(!visited[parent[node]]){
        distance[parent[node]]=distance[node]+1;
        dfs(parent,visited,cyclelength,distance,distance[node]+1,parent[node]);
    }
    else{
        cyclestart=parent[node];
        cyclelength[node]=distance[parent[node]]-distance[node]+1;
    }
    
    //rec ye baad bactrack krte samne , jis route se aaye hai , aur cycle hai tooh un sabme distance ko cyclelength hi daal do 
    if(cyclelength[node]!=-1){
        distance[node]=cyclelength[node];
        else 
    }

    return ;

}
int main() {
    fast_io;

    cin>>n>>q;

    vector<int>parent(n+1,-1);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        parent[i+1]=val;
    }

    vector<int>visited(n+1,-1);
    vector<int>cyclelength(n+1,0);
    vector<int>distance(n+1,-1);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(parent,visited,cyclelength,distance,1,i);
        }
    }

    return 0;
}
