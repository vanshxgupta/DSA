//in this question we just need to know the sum of MST and not the whole MST so we will not carrying parent with us 

//t.c-->O(ElogE);
//S.C-->O(E);
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
     
     vector<int>visited(V,0);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//{wt,node
    
     pq.push({0,0});
   
     int minsum=0;
     
     while(!pq.empty()){
         
         int node=pq.top().second;
         int wt=pq.top().first;
         pq.pop();
         
         if(visited[node]==1) continue;
         visited[node]=1;
        minsum+=wt;
         for(auto it:adj[node]){
             int adjnode=it[0];
             int edgewt=it[1];
             if(!visited[adjnode]){
                 pq.push({edgewt,adjnode});
             }
             
         }
         
         
     }
     return minsum;
     
        
    }
};