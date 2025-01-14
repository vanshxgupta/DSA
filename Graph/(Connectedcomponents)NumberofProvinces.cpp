//S.C-->0(2V)
//T.C-->O(V)+O(V+2E)

class Solution {
    private:
    // dfs traversal function 
    void dfs(int node, vector<int>adjls[],int vis[]){

        vis[node]=1;
        
        for(auto it: adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }
    
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        //the input is given in form of adjacenecy matrix and we have habit of doing in ajacenecy list ,so creating a adjacenecy list and going thru it 
        vector<int>adjls[V];
        
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){//i!=j isliye kiya kyunki jo matrix mai self nodes and unko nahi lena hai na 
                
                adjls[i].push_back(j);
                adjls[j].push_back(i);
                
                }
            }
        }
        
        int vis[V]={0};
        
        //dfs traversal ke through krenge
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
                
            }
        }
        return cnt;
        
    }
};



//USING DISJOINT SET 
#include<vector>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUparent(int n) {
        if (n == parent[n]) {
            return n;
        }

        return parent[n] = findUparent(parent[n]);
    }

    void unionbysize(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1) {
                    ds.unionbysize(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (ds.parent[i] == i) {
                cnt++;
            }
        }

        return cnt;
    }
};