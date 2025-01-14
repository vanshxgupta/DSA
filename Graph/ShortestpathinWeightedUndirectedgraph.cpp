
//t.c-->O(ElogV)+O(V);
//S.C-->O(N)


vector<int>shortestpath(int n , int m , vector<vector<int>>&edges){

    vector<pair<int,int>adj[n+1];

    //forming the adjacency list
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});


    }


    //min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    //distance array and parent array
    vector<int>dist(n+1,1e9), parent(n+1);
    dist[1]=0;

    while(!pq.empty()){
        auto it=pq.top();
        int node=it.second;
        int dis=it.first;

        pq.pop();

        for(auto it:adj[node]){
            int adjnode=it.first;
            int edgeweight=it.second;
            if(dis+edgeweight<dist[adjnode]){
                dist[adjnode]=dis+edgeweight;
                pq.push({dist+edgeweight,adjnode});
                parent[adjnode]=node;

            }


        }
    }

    if(dist[n]==1e9) return -1;//if we are unable to reach destination then return the list containg -1;



//printing the path
    vector<int>path;
    int node=n;
    while(parent[node]!=node){//jab tak node ke parent ki value khud node ke value ke equal na ho tabh tak chalo top aur jab dono equal ho jaye tabh smj jaana src node pe aa gye hai tooh vaha kahtam krdo
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());//apne pass destination se source tak ka path ayega tooh apnko array reverse krna padega jisse source se destination tak path mile 
    return path;

}