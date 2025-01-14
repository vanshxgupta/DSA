//t.c-->o(ElogV) where , E=N*M*4 and V=log(N*M)
//s.c-->o(n*m)
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        
        int n=rows;
        int m=columns;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        
        while(!pq.empty()){
            
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            if(row==n-1 && col==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int neweffort=max(abs(heights[row][col]-heights[newr][newc]),diff);
                    if(neweffort<dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({dist[newr][newc],{newr,newc}});
                        
                        
                    }
                }
            }
        }
        return 0;
    }
};