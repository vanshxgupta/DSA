//KRUSHAL'S ALGORITHM

class DisjointSet{
    //space-O(2n)
    vector<int> size, parent;

public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUparent(int u){
        if(u==parent[u]){
            return u;
        }

        return parent[u]=findUparent(parent[u]);
    }

    void unionbysize(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution{
    public:
        //Function to find sum of weights of edges of the Minimum Spanning Tree.
        int spanningTree(int V, vector<vector<int>> adj[]){

            //space ->O(m)
            vector<pair<int,pair<int,int>>> edges;
            
            //O(N+E)
            for(int i=0;i<V;i++){
                for(auto it:adj[i]){
                    int adjnode=it[0];
                    int wt=it[1];
                    int node=i;

                    edges.push_back({wt,{node,adjnode}});
                }
            }

            DisjointSet ds(V);
            
            //O(MLOGM)
            sort(edges.begin(),edges.end());
            int mstwt=0;
            
            //O(M*4*alpha*2)
            for(auto it:edges){
                int wt=it.first;
                int u=it.second.first;
                int v=it.second.second;

                if(ds.findUparent(u)!=ds.findUparent(v)){
                    mstwt+=wt;
                    ds.unionbysize(u,v);
                }
            }
            return mstwt;
        }
};
