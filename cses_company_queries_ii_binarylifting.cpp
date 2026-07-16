#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
#define reversi(a) reverse(a.begin(), a.end())

#define input2D(a,n,m) for(int _i=0;_i<n;_i++) for(int _j=0;_j<m;_j++) cin >> a[_i][_j];
#define print2D(a,n,m) for(int _i=0;_i<n;_i++){ for(int _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);  

typedef long long ll;


vector<vector<int>>parent;
vector<int>depth;
int cols;
int rows;
void build_ancestor_table(int n,vector<int>&vec){

    //j=0;
    parent[0][0]=-1;
    for(int i=1;i<n;i++){
        parent[i][0]=vec[i];
    }

    for(int j=1;j<cols;j++){ //cols
        for(int i=0;i<n;i++){ //rows
            if(parent[i][j-1]!=-1)
            parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
}

void build_depth_array(int n,vector<int>&vec){
    for(int i=1;i<n;i++){
        depth[i]=depth[vec[i]]+1;
    }
}

int main() {
    fast_io;

    int n,q;
    cin >> n>>q;

    //this is contains just the 1st ancestor , that is the parent of the employees
    vector<int> employees(n,-1);
    for(int i = 1; i < n; i++){
        cin >> employees[i];
        employees[i]--;   // convert to 0-based
    }

    cols=log2(n)+1;
    rows=n;
    
    parent.assign(n,vector<int>(20,-1));
    depth.assign(n,0);

    build_ancestor_table(n,employees);
    build_depth_array(n,employees);

    while(q--){
        int u,v;
        cin>>u>>v;
        //0 based indexing 
        u--;
        v--;
        
        int depthu=depth[u];
        int depthv=depth[v];

        if(depthv>depthu){
            swap(u,v);
            swap(depthu, depthv);
        }
        
        if(depthu!=depthv){
            //make the depth equal by lfiting the u to the level of v ,
            //  using ancestortable lift u find the kth ancestor of u and make u= kthancestor of u

            int diff=depthu-depthv;
            int k=diff;

            //find the kth ancestor of u
            int kthancestor = u;

            for(int j=cols-1;j>=0;j--){
                if((k>>j)&1){
                    kthancestor=parent[kthancestor][j];
                }
            }
            u=kthancestor;
        }

        if(u == v){
            cout << u+1 << endl;
            continue;
        }

        //now depth of u and v are equal 
        // write the code to find the LCA now 
        for(int j=cols-1;j>=0;j--){
            if(parent[u][j]==-1) continue;
            if(parent[u][j]!=parent[v][j]){
                //jump the u and v both 
                u=parent[u][j];
                v=parent[v][j];
            }
        }
        //just one above the u ,there is LCA of u and v now 
        cout << parent[u][0] + 1 << endl;
    }

    return 0;
}
