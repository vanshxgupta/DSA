#include <bits/stdc++.h> 

bool issafe(int newx,int newy, vector<vector<bool>>&visited,vector<vector<int>>&arr,int n){

    if((newx>=0 && newx<n)&&(newy>=0 && newy<n)&&visited[newx][newy]!=1 && arr[newx][newy]==1){
        return true;

    }
    return false;


}
void solve(int x,int y, vector<vector<int>>&arr,int n,vector<string>&ans, vector<vector<bool>>&vis,string path){



    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;

    }


    //4 movement
    //D,L,R,U


    //Down-->(0,0) se (1,0) pe jayenge tooh x badha na x+1 hua 
    if(issafe(x+1,y,vis,arr,n)){
        vis[x][y]=1;
        solve(x+1,y,arr,n,ans,vis,path+'D');
        vis[x][y]=0;
    }

    //Left
    if(issafe(x,y-1,vis,arr,n)){
        vis[x][y]=1;
        solve(x,y-1,arr,n,ans,vis,path+'L');
        vis[x][y]=0;
    }

    //Right
    if(issafe(x,y+1,vis,arr,n)){
        vis[x][y]=1;
        solve(x,y+1,arr,n,ans,vis,path+'R');
        vis[x][y]=0;
    }

    //UP
    if(issafe(x-1,y,vis,arr,n)){
        vis[x][y]=1;
        solve(x-1,y,arr,n,ans,vis,path+'U');
        vis[x][y]=0;
    }


}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path="";



    //edge case-->agar matrix ke starting mai hi 0 hoga tooh rat aage chal hi nahi payega
    if(arr[0][0]==0){
        return ans;
    }

    solve(0,0,arr,n,ans,visited,path);
    return ans;

    
}