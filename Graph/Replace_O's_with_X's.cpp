
//T.C->O(N)+O(M)+O(N*M)*4
//S.C->O(N*M)

class Solution{
    
    private:
    void dfs(int row, int col,vector<vector<int>>&vis,vector<vector<char>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vis[row][col]=1;
        
        //check for top, bottom , left, right 
        
        int deltarow[4]={-1,0,1,0};
        int deltacol[4]={0,1,0,-1};
        
        for(int i=0;i<4;i++){//4 neighbours hai isliye loop 4 baar chalaya 
            
            int nrow=row+deltarow[i];
            int ncol=col+deltacol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat);
                
            }
            
            
        }
        
        
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        
        //traverse first row and last row
        for(int j=0;j<m;j++){
            
            
            //first row
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat);
                
            }
            
            //last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat);
            }
        }
        
        
        //traverse first coll and last col
        for(int i=0;i<n;i++){
            
            //first col
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat);
                
            }
            
            //last col
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat);
            }
            
            
        }
        
        //marking other O's to X's, these are the O's which are not marked in the visited matrix(i.e the O's which are not connected to the boundary)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
            
        }
        
        return mat;
    }
};
