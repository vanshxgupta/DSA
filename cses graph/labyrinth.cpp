
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
void bfs(int r,int c,vector<vector<int>>&visited,vector<string>&grid){
    
    int time=0;
    queue<pair<int,int>>q;
    q.push({r,c});
    visited[r][c]=1;

    vector<vector<char>>prevmatrix(n,vector<char>(m,0));
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    char dl[4]={'D','L','U','R'};

    int bi=-1;
    int bj=-1;
    int ai=r;
    int aj=c;

    bool flag=0;
    while(!q.empty()){
        int sizi=q.size();
        for(int x=0;x<sizi;x++){
            auto fronti=q.front();
            q.pop();
            
            int r=fronti.first;
            int c=fronti.second;
       
            for(int i=0;i<4;i++){
                int row=r+dx[i];
                int col=c+dy[i];

                if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0){
                    if(grid[row][col]=='B'){
                        prevmatrix[row][col]=dl[i];
                        bi=row;
                        bj=col;
                        flag=1;
                        break;
                    }
                    else if(grid[row][col]=='.'){
                        visited[row][col]=1;
                        prevmatrix[row][col]=dl[i];
                        q.push({row,col});
                    }
                }
            }
            if(flag){
                break;
            }
        }
        time++;
        if(flag){
            break;
        }
    } 


    if(flag==0){
        no;
    }
    else{
        yes;
        cout<<time<<endl;

        //path
        //backtrrack the path
        string path="";
        int i=bi;
        int j=bj;
        while(!(i==ai && j==aj)){
            if(prevmatrix[i][j]=='D'){//down se aaya hai ->matlab bactrack krega tooh up jayega
                path.push_back('D');
               
                i--;
            }
            else if(prevmatrix[i][j]=='U'){
                path.push_back('U');
               
                i++;
            }
            else if(prevmatrix[i][j]=='R'){
                path.push_back('R');
               
                j--;
            }
            else if(prevmatrix[i][j]=='L'){
                path.push_back('L');
               
                j++;
            }
        }
        reverse(path.begin(),path.end());
        cout<<path<<endl;

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
        
    pair<string,int> ans;
    bool found=false;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
               bfs(i,j,visited,grid);
                found=true;
                break;
            }
        }
        if(found) break;
    }

    return 0;
}
