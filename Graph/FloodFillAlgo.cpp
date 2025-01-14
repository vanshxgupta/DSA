//S.C->0(N*M)
//T.C->O(N*M)

class Solution {
    void dfs(vector<vector<int>>& ans,int row,int col,int newcolor,vector<vector<int>>& image,int deltarow[],int deltacol[],int initialcolor){
        ans[row][col]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+deltarow[i];
            int ncol=col+deltacol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialcolor && ans[nrow][ncol]!=newcolor){//iss statement ka matlab row,aur colo valid hona chahiye 
            //aur kya image element ka color inital color jesa hai ? aur kya apnne usko pehle newcolor se fill nahi kiya hai tooh ye statement chala do  
                ans[nrow][ncol]=newcolor; 
                dfs(ans,nrow,ncol,newcolor,image,deltarow,deltacol,initialcolor);
            } 
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialcolor=image[sr][sc];
        vector<vector<int>> ans=image; // copy the image to ans
        int deltarow[]={-1,0,1,0}; 
        int deltacol[]={0,1,0,-1};
        dfs(ans,sr,sc,newColor,image,deltarow,deltacol,initialcolor);
        return ans;
    }
};