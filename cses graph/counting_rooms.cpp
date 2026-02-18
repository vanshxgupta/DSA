#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())

#define input2D(a,n,m) for(int _i=0;_i<n;_i++) for(int _j=0;_j<m;_j++) cin >> a[_i][_j];
#define print2D(a,n,m) for(int _i=0;_i<n;_i++){ for(int _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);  


typedef long long ll;

int n,m;
void dfs(int r,int c,vector<vector<int>>&visited,vector<string>&grid){

    visited[r][c]=1;
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    
    for(int i=0;i<4;i++){
        int row=r+dx[i];
        int col=c+dy[i];
        
        if(row<n && col<m && row>=0 && col>=0 && visited[row][col]==0 && grid[row][col]=='.'){
           dfs(row,col,visited,grid);
         }
        
    }
   
}

int main() {
    fast_io;

        cin>>n>>m;
        
        vector<string>grid(n);
        for(int i=0;i<n;i++){
            cin >> grid[i];
        }
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.' && visited[i][j]==0){
                    cnt++;
                    dfs(i,j,visited,grid) ;
                }
                }
            }
        
        
        cout<<cnt<<endl;
        
    return 0;
}
