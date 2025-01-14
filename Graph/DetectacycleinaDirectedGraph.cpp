//Using DFS
//  T.C-> O(V+E)+O(V)
//S.C-->O(2V)

class Solution {
    
    private:
    bool dfscheck(int node, vector<int>adj[],int vis[],int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        
        //traverse for adjacent nodes
        for(auto it:adj[node]){
            //when the node is not visited
            if(!vis[it]){
                if(dfscheck(it,adj,vis,pathvis)==true){
                    return true;
                }
            }
            
            //if the node has been previously visited but it has to be visited on the same path
            else if(pathvis[it]){
                return true;
            }
            
        }
        pathvis[node]=0;
        return false;
        
        
    }
    
    
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        
        int pathvis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfscheck(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
        
        
    }
};



//Using BFS(toposort method)
//  T.C-> O(V+E)
//S.C-->O(3V)

class Solution {
    
    private:
    
    void toposorti(int V, vector<int> adj[],vector<int>&toposort){
        
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            toposort.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        
        return ;
        
    }
    
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
      
        vector<int>toposort;
        toposorti(V,adj,toposort);
        
        if(toposort.size()==V){//we do not have a cycle
            return false;
        }
        return true;//it have a cycle
        
    }
};
