//T.C-->O(V+E)+O(V)+(V+E)
//S.C-->O(5V)

class Solution {
    private:
    void toposort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st){
        
        vis[node]=1;
        for(auto it:adj[node]){
            int v=it.first;
            if(!vis[v]){
                toposort(v,adj,vis,st);
            }
             
        }
        st.push(node);
    }
    
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       
       //making of adjacenecy list 
       vector<pair<int,int>>adj[N];
       for(int i=0;i<M;i++){
           int u=edges[i][0];//kis node se start hoke
           int v=edges[i][1];//kis node tak edge ja rahi hai 
           int wt=edges[i][2];//aur un dono ke bich mai jo edge hai uska weight
           
           adj[u].push_back({v,wt});
       }
       
       
       
       //find the topo sort
       int vis[N]={0};
       stack<int>st;
       for(int i=0;i<N;i++){
           if(!vis[i]){
               toposort(i,adj,vis,st);
           }
       }
       
       
       //step 2 :do the distance thing
       vector<int> dist(N);
       for(int i=0;i<N;i++){
           dist[i]=1e9;
           dist[0]=0;//given here in the question the src node is 0 
       }
           while(!st.empty()){
               int node=st.top();
               st.pop();
               
               for(auto it :adj[node]){
                   int v=it.first;//adjacent nodes
                   int wt=it.second;//distances
                   
                   
                   if(dist[node]+wt<dist[v]){//agar iss node+wt ki distance , pehle ke distance se kam hai tooh usko update krdo 
                       dist[v]=dist[node]+wt;
                       
                   }
               }
           }
           
           for(int i=0;i<N;i++){
               if(dist[i]==1e9){
                   dist[i]=-1;
               }
           }
      
       
       return dist;
       
    }
};