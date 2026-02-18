//multisource bfs 

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << ""; cout << endl;
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
int n,m;
int main() {
    fast_io;

    cin>>n>>m;
        
    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin >> grid[i];
    }
    
    //multisource dfs for the minimum monsterdist calculation for every grid point
    vector<vector<int>>monsterdist(n,vector<int>(m,INT_MAX));
    queue<pair<int,int>>q;

        
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    char dl[4]={'D','L','U','R'};


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                q.push({i,j});
                monsterdist[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        auto fronti=q.front();
        q.pop();
        int x=fronti.first;
        int y=fronti.second;

        for(int i=0;i<4;i++){
            int row=x+dx[i];
            int col=y+dy[i];

            if(row>=0 && row<n && col>=0 && col<m && (grid[row][col]=='.') && (monsterdist[row][col]>monsterdist[x][y]+1)){
                monsterdist[row][col]=monsterdist[x][y]+1;
                q.push({row,col});
            }
        }
    }
    
    
    //bfs to calaculte minium dist from me to every node
    queue<pair<int,int>>q1;
    vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
    vector<vector<char>>pathtrack(n,vector<char>(m,' '));
    
    pair<int,int> start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                q1.push({i,j});
                distance[i][j]=0;
                start={i,j};
            }
        }
    }
    
    pair<int,int> endi={-1,-1};

    while(!q1.empty()){
        auto fronti=q1.front();
        q1.pop();
        int x=fronti.first;
        int y=fronti.second;

        if(x==n-1 || x==0 || y==0 || y==m-1){
            endi={x,y};
        }

        for(int i=0;i<4;i++){
            int row=x+dx[i];
            int col=y+dy[i];

            if(row>=0 && row<n && col>=0 && col<m && (grid[row][col]=='.')){
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='.'){
                    if(distance[row][col]==INT_MAX && distance[x][y]+1 < monsterdist[row][col]){
                        distance[row][col]=1+distance[x][y];
                        q1.push({row,col});
                        pathtrack[row][col]=dl[i];
                    }
            }

            }
        }
    }
    if(endi.first==-1 && endi.second==-1){
        cout<<"NO"<<endl;
    }
    else{

    
    pair<int,int>curr=endi;

    vector<char>path;

    while(curr!=start){
        int xi=curr.first;
        int yi=curr.second;
        char direction=pathtrack[xi][yi];//direction from where ye aaya tha , udhar hi humko vapis jaana hai 
        // char backtrackdirection;
        if(direction=='U'){
            // backtrackdirection='D';
            curr.first++;
        }
        if(direction=='D'){
            // backtrackdirection='U';
            
            curr.first--;
            
        }
        if(direction=='L'){
            // backtrackdirection='R';;
            curr.second++;
            
        }
        if(direction=='R'){
            // backtrackdirection='L';
            curr.second--;

        }

        path.push_back(direction);
    }

    reversi(path);

    yes;
    cout<<path.size()<<endl;
    print(path);
}

    return 0;
}
