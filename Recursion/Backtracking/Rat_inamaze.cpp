//RAT IN A MAZE PROBLEM
// Consider a rat placed at (0, 0) in a square matrix of order N * N. 
// It has to reach the destination at (N - 1, N - 1). Find all possible
// paths that the rat can take to reach from source to destination. 
//The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix 
//represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

#include<bits/stdc++.h>

using namespace std;

//Safe ki conditions:
//1)matrix ke anr tooh hai na,2) kya vo pehle visited tooh nahi hai , agr viisted nahi hoga tooh 0 marked hoga visited array mai , 3)kya vo 1 hai (i.e allowed hai)?
bool issafe(int x,int n, vector<vector<int >> visited,vector<vector<int>>m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
        return true;

    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &m,int n, vector<string>& ans, int x,int y,vector<vector<int>> visited,string path){
    
    //you have reached x,y here
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return ;//jaha pahuchna tha pahuch gye 

    }
    visited[x][y]=1;

    //4 choices-D,L,R,U
    //down
    int newx=x+1;
    int newy=y;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back("D");
        //backtrack
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    //left
    int newx=x;
    int newy=y-1;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back("L");
        //backtrack
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    //right
    int newx=x;
    int newy=y+1;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back("R");

        //backtrack
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    //up
    int newx=x-1;
    int newy=y;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back("U");
        //backtrack
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

 


}


vector<string> findpath(vector<vector<int>>&m,int n){
    vector<string> ans;

    if(m[0][0]==0) return;//agar saare hi 0 hai tooh ,koi path hoga hi nahi

    int scrx=0;//source ka x wala coordinate
    int scry=0;//source ka y wala coordinate

    vector<vector<int>> visited=m;//ek visited naam ka 2d array create kar liya jisme initially saare 0 hai
    //intialise with 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        visited[i][j]=0;
        }
    }

    string path="";//different path store krne ke liye
    solve(m,n,scrx,scry,visited,path);
    sort(ans.begin(),ans.end());//as given in question , we have to arrange it in lexicographically increasing order 
    return ans;
}

int main(){
    vector<vector<int>> m = {{0, 0, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3;
    vector<string> result = findpath(m, n);
    
    for (const auto &path : result) {
        cout << path << endl;
    }
    
    return 0;
}




  
