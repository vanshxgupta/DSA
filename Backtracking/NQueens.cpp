
// //T.C->0(N!)
// //S.C->O(N*N)-->due to temp vector to store board configuration
// #include <bits/stdc++.h> 

// void addsolution(vector<vector<int>>&ans,vector<vector<int>>&board,int n){


//     vector<int>temp;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             temp.push_back(board[i][j]);
            
//         }
//     }
//     ans.push_back(temp);
// }

// bool issafe(int row,int col,vector<vector<int>> &board,int n){
    
//     int x=row;
//     int y=col;

//     //check for same piche wali row
//     while(y>=0){
//         if(board[x][y]==1){
//             return false;
//         }
//         y--;
//     }

//     //check for col
//     //column check krne ki need hi nahi hai , kyunki code hai ese likha hai hmne ke ek queen place 
//     //ki hui hogi koi column mai tooh dusri fill nahi kar payenge , agar koi karna bhi hogi fill tooh
//     // vo queen ko backtrack krke hatayenge pehle aur fir daalenge queen


//     //aage wali row aur aage wae do diagonal bhi check krne ki jrurt nhi hai 



//     //check for upar piche wala diagonal
//     x=row;
//     y=col;
//     while(x>=0 && y>=0){
//         if(board[x][y]==1){
//             return false;
//         }

//         y--;
//         x--;

//     }


//     //check for upar piche wala diagonal
//     x=row;
//     y=col;
//     while(x<n && y>=0){
//         if(board[x][y]==1){
//             return false;
//         }

//         y--;
//         x++;

//     }

//     return true;
// }

// void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){

//     //base case
//     if(col==n){
//         addsolution(ans,board,n);//board wale vector vector ko single vector mai convert krke answer mai daalo
//         return;
//     }


//     //solve one case and rest recursion will take care

//     for(int row=0;row<n;row++){//pehle column ke liye saari row pe jaana hai

//         if(issafe(row,col,board,n)){
//             //if placing queen is safe
//             board[row][col]=1;
//             solve(col+1,ans,board,n);

//             //back track
//             board[row][col]=0;
//         }
//     }
// }


// vector<vector<int>> nQueens(int n)
// {
// 	vector<vector<int>>board(n,vector<int>(n,0));
//     vector<vector<int>>ans;

//     solve(0,ans,board,n);

//     return ans;

// }




//OPTIMISATION-->// //T.C->0(N!)
// //S.C->O(N*N)

void addsolution(vector<vector<int>>&ans,vector<vector<int>>&board,int n){
    vector<int>temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
            
        }
    }
    ans.push_back(temp);
}

void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,int n){

    if(col==n){
        addsolution(ans,board,n);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1+col-row]==0){
            board[row][col]=1;
            leftrow[row]=1;
             lowerdiagonal[row+col]=1 ;
            upperdiagonal[n-1+col-row]=1;


            solve(col+1,ans,board,leftrow,upperdiagonal,lowerdiagonal,n);

            //backtrack
            board[row][col]=0;
            leftrow[row]=0;
             lowerdiagonal[row+col]=0;
            upperdiagonal[n-1+col-row]=0;

            
        }
    }
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;

    vector<int>leftrow(n,0);
    vector<int>upperdiagonal(2*n-1,0);
    vector<int>lowerdiagonal(2*n-1,0);


    solve(0,ans,board,leftrow,upperdiagonal,lowerdiagonal,n);

    return ans;

}