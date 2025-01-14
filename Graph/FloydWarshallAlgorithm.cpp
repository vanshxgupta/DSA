//t.c-->O(n^3)
//s.c-->O(n^2)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == -1){//jin pe edge nahi hai unko bahut badi value de dete hai jisse ki hum un tak pahuch hi na paye 
                    matrix[i][j] = INT_MAX;
                }
                if(i == j) matrix[i][j] = 0;        
            }
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }  
        
        
        for(int i = 0; i < n; i++){
            if(matrix[i][i] < 0){
                cout << "negative cycle";
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == INT_MAX){
                    matrix[i][j] = -1;
                }
            }
        }
    }
};