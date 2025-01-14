#include<bits/stdc++.h>
using namespace std;


//t.c-->O(4 alpha) i.e near about constant 
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

int main(){
    DisjointSet ds(7);
    ds.unionbysize(1, 2);
    ds.unionbysize(2, 3);
    ds.unionbysize(4, 5);
    ds.unionbysize(6, 7);
    ds.unionbysize(5,6);

    //is 3 and 7 same or not?
    if(ds.findUparent(3) == ds.findUparent(7)) {
        cout<<"same"<<endl;
    }
    else {
        cout<<"not same"<<endl;
    }

    ds.unionbysize(3, 7);

    //again ask-is 3 and 7 same or not?
    if(ds.findUparent(3) == ds.findUparent(7)) {
        cout<<"same"<<endl;
    }
    else {
        cout<<"not same"<<endl;
    }

    return 0;
    
}