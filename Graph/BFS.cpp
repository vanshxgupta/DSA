
//T.C-->0(v)+0(2E)
//S.C-->O(3V)
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        
        int vis[V]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
        
        return bfs;
        
    }
};


//codestorywithmik
class Solution {
    
    void bfs(vector<vector<int>> &adj,int u,vector<bool>&visited,vector<int>&ans){
        queue<int>q;
        q.push(u);
        visited[u]=true;
        ans.push_back(u);
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(auto &v:adj[u]){
                
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                    ans.push_back(v);
                }
                
            }
        }
    }
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
       
       //adjacency list given hai , alg se banane ki jrurt nahi hai 
       int n=adj.size();
       vector<int>ans;
       vector<bool>visited(n,0);
       
       bfs(adj,0,visited,ans);
       return ans;
       
    }
};