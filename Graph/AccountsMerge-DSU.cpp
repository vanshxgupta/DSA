class DisjointSet{
    vector<int>size,parent;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        
        int n=details.size();
        DisjointSet ds(n);
        
        unordered_map<string,int>mapmailnode;
        
        //mapping the accounts to indexes
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail=details[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end()){
                    mapmailnode[mail]=i;
                }
                //if the account alreasy exist then calling union 
                else{
                    ds.unionbysize(i,mapmailnode[mail]);
                }
            }
        }
        
        //merging the accounts who have gmail id's in common
        vector<string>mergedmail[n];
        
        for(auto it:mapmailnode){
            string mail=it.first;
            int node=ds.findUparent(it.second);
            mergedmail[node].push_back(mail);
        }
        
        //sorting the merged mail individually and then putting the name of the account holder and then the merged mail in the answer
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            if(mergedmail[i].size()==0) continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it:mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};