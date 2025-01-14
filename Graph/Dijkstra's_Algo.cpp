
//USING PRIORITY QUEUE
//T.C-->O(E*logV)
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V);
        for(int i=0;i<V;i++) dist[i]=1e9;
        
        dist[s]=0;//source se source ka distance is 0
        pq.push({0,s});
        
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int edgeweight=it[1];
                int adjnode=it[0];
                
                if(distance+edgeweight<dist[adjnode]){//agar distamce of  previous wala + edgeweight , pehle ke distance array mai jo distance dala hai usse kam hai tooh naye array mai vo distance daaldo aur queue mai bhi push krdo 
                   
                    dist[adjnode]=distance+edgeweight;
                    pq.push({dist[adjnode],adjnode});//pushing the {dist,node} in the queue
                }
            }    
        }
            return dist;
    }
};



 
//USING SET

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        
        st.insert({0,s});
        dist[s]=0;
        
        while(!st.empty()){
            
            auto it=*(st.begin());//st.begin() is the pointer that points to the begining of the set and *(st.begin())  will give the value at the begining of the set
            //st.begin pe isliye point krva rahe hai kyunki , set ascending order mai store krta hai values
            
            int node=it.second;
            int distance=it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjnode=it[0];
                int edgeweight=it[1];
                
                if(distance+edgeweight<dist[adjnode]){
                    
                    //erase if it existed
                    if(dist[adjnode]!=1e9) st.erase({dist[adjnode],adjnode});
                    
                    dist[adjnode]=distance+edgeweight;
                    st.insert({dist[adjnode],adjnode});
                }
                
            }
            
            
            
        }
        
        return dist;
    }
};