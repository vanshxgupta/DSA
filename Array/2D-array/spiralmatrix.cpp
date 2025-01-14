// Given an m x n matrix, return all elements of the matrix in spiral order.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int row=matrix.size();
        
        int col=matrix[0].size();

        int count=0;
        int total=row*col;//total elements 

        int sr=0;//starting row;
        int sc=0;//starting column;
        int er=row-1;//ending row;
        int ec=col-1;//ending column;

        while(count<total){


            //starting row;
            for(int index=sc;index<=ec;index++){
                ans.push_back(matrix[sr][index]);
                count++;

            }
            sr++;

            //ending column
            for(int index=sr;index<=er ;index++){
                ans.push_back(matrix[index][ec]);
                count++;

            }
            ec--;

            if (count < total) { // Check if we still need to go through more loops
              //ending row;
              for(int index=ec;index>=sc ;index--){
                  ans.push_back(matrix[er][index]);
                  count++;

              }
              er--;
              
              if (count < total) { // Check if we still need to go through more loops
                //staring column
                for(int index=er;index>=sr ;index--){
                    ans.push_back(matrix[index][sc]);
                    count++;

                }
                sc++;
              }

            }
        }
        return ans;

        
    }
};
