
//T.C->O(v)+O(2E);
//S.C->O(3v);
class Solution {
    private:
    void dfs(int node,int vis[],vector<int>&ans,vector<int> adj[]){
        
        vis[node]=1;
        ans.push_back(node);
        
        for(int it:adj[node]){//traverse all its neighbours
        
            if(!vis[it]){//if neighbours are not visited
                dfs(it,vis,ans,adj);
            }
        }
        
        
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       
       int vis[V]={0};
       int start=0;
       vector<int>ans;
       dfs(start,vis,ans,adj);
       return ans;
    }

};



///during rev->by codestorywithmik
class Solution {
    
    void dfs(vector<vector<int>>& adj,int u,vector<bool>&visited,vector<int>&ans){
        
        if(!visited[u]){
            ans.push_back(u);
            visited[u]=1;
            for(auto &v:adj[u]){
                if(!visited[v]){
                    dfs(adj,v,visited,ans);
                }
            }
        }
    }
  public:
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        
        //adjacency list already given
        vector<int>ans;
        int n=adj.size();
        
        vector<bool>visited(n,0);
        
        dfs(adj,0,visited,ans);
        return ans;
        
      
    }
};