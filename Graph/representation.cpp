#include<iostream>
using namespace std;


//USING ADJACENECY MATRIX 
//SPACE -->O(N*M)
int main(){
    int n,m;
    cin>>n>>m;

    //graph here 
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; // this statement will be removed in case of directed graph

    }
    return 0;
}




//INPUT
// 5 6 
// 1 2
// 1 3 
// 1 4
// 3 4
// 2 5
// 4 5


//USING ADJACENECY LIST
SPACE-->O(2M)

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//this statement will be removed in case of directed graph
    }

    return 0;
}

//ADjacency list using Unordered_map  //o(v+e)

//vector<vector<int>>prerequisites-->given hai ye [[1,0],[2,0],[2,1],[3,1]]
                        
                        //(u--->v)
//where [1,0] represents (1---->0)
//ab isse graph banao (by using adjacency list)

int main(){
    unordered_map<int,vector<int>>adj;

    for(vector<int>&vec:prerequisites){
        int u=vec[0];
        int v=vec[1];

        adj[u].push_back(v);
    }
    return solve(adj);

}




//WEIGHTED GRAPH

//MATRIX
int main(){
    cin>>n>>m;
    adj[n+1][n+1];

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[u][v]=wt;//this statement will be removed in case of directed graph

    }
}


//LIST
int main(){
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
            
         adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));//this statement will be removed in case of directed graph

    }
    return 0;
}



