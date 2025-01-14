//S.C-->O(3V)
//T.C-->O(V+2E)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       
       //forming the adjacenency list for undirected graph
       vector<int>adj[N];
       
       for(auto i:edges){
           int u=i[0];
           int v=i[1];
           
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
       
       //forming a distance array and initialsing all the elements distance to infinity initally and src to 0 distance
       int dist[N];
       for(int i=0;i<N;i++){
           dist[i]=1e9;
       }
       dist[src]=0;
       
       
       //forming a queue and applying BFS
        
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i]!=1e9){
                ans[i]=dist[i];
            }
        }
        
        return ans;
       
       
    }
};