
//t.c-->O(E);, where E=flights.size();{ Additional log(V) of time eliminated here because we’re using a simple queue rather than a priority queue which is usually used in Dijkstra’s Algorithm }.
//s.c-->O( |E| + |V| ) { for the adjacency list, priority queue, and the dist array }.

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        //it is a directed graph and we are not given the adjacency list , so we have to make it from flights matrix
        
        //forming the adjaceny list
        vector<pair<int,int>>adj[n];
        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
            
            
        }
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            if(stops>K) continue;
            
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                int edgeweight=iter.second;
                
                if(cost+edgeweight<dist[adjnode] && stops<=K){
                    dist[adjnode]=cost+edgeweight;
                    q.push({stops+1,{adjnode,cost+edgeweight}});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
    
};
