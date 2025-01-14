
//Using DFS
//T.C-->O(V+E)
//S.C-->O(2V)
class Solution
{
    
    private:
    void dfs(int node,stack<int>&st,int vis[],vector<int>adj[]){
        
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
        
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    int vis[V]={0};
	    stack<int>st;
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,st,vis,adj);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	    
	}
};



//Using BFS(KAHN'S ALGORITHM)
//T.C-->O(V+E)
//S.C-->O(2V)
class Solution
{
   
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	  
	  int indegree[V]={0};
	  for(int i=0;i<V;i++){
	      for(auto it:adj[i]){//nodes ki indegree nikalne ke liye , uske adjacent nodes ko traverse hu aur jab koi adjacent node aaye tooh us adjacent node ki indegree badha do  
	      //yaad rkhna ke jo adjacent nodes aare hai unki indegree badhana hai ,node ki nahi  
	          indegree[it]++;
	          
	      }
	  }
	  
	  queue<int>q;
	  for(int i=0;i<V;i++){
	      if(indegree[i]==0){//agar node ki indegree 0 hai tooh queue mai push kardo 
	          q.push(i);
	      }
	  }
	  
	  
	  vector<int>topo;
	  while(!q.empty()){
	      int node=q.front();
	      q.pop();
	      topo.push_back(node);
	      
	      //node is in your topo sort , so please remove it from the indegree
	      for(auto it:adj[node]){
	          indegree[it]--;
	          if(indegree[it]==0)q.push(it);
	          
	      }
	  }
	  return topo;
	}
};