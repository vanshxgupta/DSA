//USING DFS
//T.C-->O(V+E)+O(V)
//S.C-->O(3N)
class Solution {
    private:
    bool dfscheck(int node, vector<int>adj[],int vis[],int pathvis[],int check[]){
        
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        //traverse for adjacent nodes
        for(auto it:adj[node]){
            //when the node is not visited
            if(!vis[it]){
                if(dfscheck(it,adj,vis,pathvis,check)){//matlab cycle present hai , tooh vo safe node nahi ho skta tooh check ko 0 krdo
                    check[node]=0;
                    return true;//cycle present hai isliye return true;
                }
            }
            
            //if the node has been previously visited but it has to be visited on the same path i.e path visited mai bhi marked hai aur visited mai bhi , tooh 
            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       
       int vis[V]={0};
       int pathvis[V]={0};
       int check[V]={0};
       
       vector<int>safenodes;
       
       for(int i=0;i<V;i++){
           if(!vis[i]){
               dfscheck(i,adj,vis,pathvis,check);
           }
       }
       
       for(int i=0;i<V;i++){
           if(check[i]) safenodes.push_back(i);
       }
       return safenodes;
    }
};



//USING BFS(Topological sort)
//T.C-->O(V+E)+O(nlogn)
//S.C-->O(4N)

class Solution {
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};
		
		//saare ke saare edges ko reverse kar rahe hai aur saath hi saath unki indegree bhi nikal rahe hai 
		for (int i = 0; i < V; i++) {
            //it is neighbour of i  -->means edge is from i to it i.e (i->it)
            //and we have to convert it to i i.e (it->i)
            
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		 //finding out which are terminal nodes-->jinki indegree 0 vo terminal node(the actual definition of terminal node is jinki outdegree 0 bo terminal node , par kyunki hamne edges reverse kiye hai tooh definition bhi reverse ho gyi )
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};
