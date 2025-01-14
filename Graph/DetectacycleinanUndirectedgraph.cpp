//USING BFS
//T.C->O(V+2E)+O(V)
//S.C->O(V)

class Solution {
    private:
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
          
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){

                if(!vis[it]){//agar visited nahi hai tooh visited mai mark kardo aur queue mai daaldo us node aur uske parent ko
                    vis[it]=1;
                    q.push({it,node});
                }

                else if(vis[it] && parent!=it){//if someone is visted and it does not come from its parent then there is a cycle 
                    return true;
                }               
            }
            
            
        }
        return false;
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        
        //connected components handling
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
        
        
    }
};




//USING DFS
//T.C->O(V+2E)+O(V)
//S.C->O(V)
class Solution {
    bool iscycledfs(int node,int parent,vector<int> adj[],int visited[],int V){
        
        visited[node]=1;
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(visited[it]) return true;
            if(iscycledfs(it,node,adj,visited,V)==true)
                return true;
            }           
        return false;//kahi bhi cycle nahi mili tooh return false;
        }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int node=0;
        int parent=-1;
        int visited[V]={0};
        
        //this condition will only work when graph have single component
        //return dfs(node,parent,adj,visited,V);
        
        
        
        //so handling the case if the graph have multiple component
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(iscycledfs(i,parent,adj,visited,V)==true) return true;
            }
        }
        return false;
        
    }
};
