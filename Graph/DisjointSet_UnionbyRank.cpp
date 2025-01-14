#include<bits/stdc++.h>
using namespace std;
//t.c-->O(4 alpha) i.e near about constant 
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findultimateparent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findultimateparent(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ultimateparent_u = findultimateparent(u);
        int ultimateparent_v = findultimateparent(v);

        if(ultimateparent_u == ultimateparent_v) {
            return;
        }
        if(rank[ultimateparent_u] < rank[ultimateparent_v]) {
            parent[ultimateparent_u] = ultimateparent_v;
        }
        else if(rank[ultimateparent_v] < rank[ultimateparent_u]) {
            parent[ultimateparent_v] = ultimateparent_u;
        }
        else {
            parent[ultimateparent_v] = ultimateparent_u;
            rank[ultimateparent_u]++;
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionbyrank(1, 2);
    ds.unionbyrank(2, 3);
    ds.unionbyrank(4, 5);
    ds.unionbyrank(6, 7);
    ds.unionbyrank(5, 6);

    //is 3 and 7 same or not?
    if(ds.findultimateparent(3) == ds.findultimateparent(7)) {
        cout<<"same"<<endl;
    }
    else {
        cout<<"not same"<<endl;
    }

    ds.unionbyrank(3, 7);

    //again ask-is 3 and 7 same or not?
    if(ds.findultimateparent(3) == ds.findultimateparent(7)) {
        cout<<"same"<<endl;
    }
    else {
        cout<<"not same"<<endl;
    }

    return 0;
}
