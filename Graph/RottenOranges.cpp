//s.c->o(n*m)
//T.c->o(n*m)
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int visited[n][m];
        queue<pair<pair<int,int>,int>> q;
        
        
        //intially marking the visited and pushing into the queue who are rotten
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                visited[i][j]=2;
                q.push({{i,j},0});
                
                }
                
                
                else{
                    visited[i][j]=0;
                    
                }
                
            }
        }
        
        //write bfs
        int time=0;
        int deltarow[4]={-1,0,1,0};
        int deltacol[4]={0,1,0,-1};
            
            
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            time=q.front().second;
            q.pop();
            
            //neighbouring 
            for(int i=0;i<4;i++){
                int nrow=row+deltarow[i];
                int ncol=col+deltacol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=2;
                    
                    
                }
            }     
        }  

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){      
                if(visited[i][j]!=2 && grid[i][j]==1){//iss statement ka mtalb grid wali same position pe fresh orange tha fir bhi visited array ki i,j position par rotten orange nahi hua tooh return -1 
                return -1;
            }
        }
        }
        return time;
        
    }
};