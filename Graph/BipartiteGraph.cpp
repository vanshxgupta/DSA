//Using BFS
//T.C-->O(V+2E)+O(V)
//S.C-->O(2V)
class Solution {
    
    private:
    bool check(int start,int V, vector<int>adj[],int color[]){
        queue<int>q;
	   q.push(start);
	  
	   
	   color[start]=0;
	   
	   while(!q.empty()){
	       int node=q.front();
	       q.pop();
	       
	       for(auto  it:adj[node]){
	           
	           //if the adjacent node is yet not colored
	           //you will gice the opppsite color of the node
	           if(color[it]==-1){
	               color[it]=!color[node];
	               q.push(it);
	           }
	           
	           //is the adjacent guy havinf the same color 
	           //someone did color it on some other path
	           
	           else if (color[it]==color[node]){//node ki adjacenecy list mai  dekh rahe hai ke kya koi 2 adjacent node ka color same tooh nahi? agar same hai tooh return false; 
	           
	               return false;
	           }
	           
	       }
	   }
	   return true;
	   
	}
    
public:
	bool isBipartite(int V, vector<int>adj[]){
        int color[V];
         for(int i=0;i<V;i++) color[i]=-1;
         for(int i=0;i<V;i++){
             if(color[i]==-1){
                 if(check(i,V,adj,color)==false){
                     return false;
                 }
             }
         }
         return true;
	}
        

};





//USING DFS
//T.C-->O(V+2E)+O(V)
//S.C-->O(3V)
class Solution {
    
    private:
    bool dfs(int node,int colour, vector<int>adj[],int color[]){
        
        color[node]=colour;
        
        for(auto it : adj[node]){
            if(color[it]==-1){
                if(dfs(it,!colour,adj,color)==false) return false;
            }
            else if(color[it]==colour){
                return false;
            }
        }
        return true;
        
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
        int color[V];
         for(int i=0;i<V;i++) color[i]=-1;
         for(int i=0;i<V;i++){
             if(color[i]==-1){
                 if(dfs(i,0,adj,color)==false){
                     return false;
                 }
             }
         }
         return true;
	}
        
};

