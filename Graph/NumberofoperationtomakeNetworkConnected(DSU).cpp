//Using DSU

class DisjointSet{

public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1,0);
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


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        DisjointSet ds(n);
        
        int cntextra=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            
            if(ds.findUparent(u)==ds.findUparent(v)){
                cntextra++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        
        int cntcomponent=0;
        for(int i=0;i<n;i++){
            if(ds.findUparent(i)==i){
                cntcomponent++;
            }
        }
        int ans=cntcomponent-1;
        
        if(cntextra>=ans){
            return ans;
        }
        return -1;
        
        
        
    }
};

