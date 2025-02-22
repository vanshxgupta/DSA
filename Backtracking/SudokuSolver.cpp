//T.C->O(9^m), where m is the no. of empty cells
//S.C->O(81)

#include <bits/stdc++.h> 

bool issafe(int row,int col, vector<vector<int>>&board,int val){
    for(int i=0;i<board.size();i++){
        //row check 
        if(board[row][i]==val){
            return false;

        }

        //col check
        if(board[i][col]==val){
            return false;
        }

        //3*3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board){

    int n=board[0].size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){

            //cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(issafe(row,col,board,val)){
                        board[row][col]=val;

                        //recursive call
                        bool furtherpsbl=solve(board);
                        if(furtherpsbl){
                            return true;
                        }
                        else{

                            //backtrack krna padega
                            board[row][col]=0;
                        }
                    }
                }

                return false;//(1 se 9 tak saari values check krli par answer nahi aaya tooh psbl nahi hai solve krna )
            }
        }
    }
    return true;

}
void solveSudoku(vector<vector<int>>& sudoku)
{

    solve(sudoku);

}