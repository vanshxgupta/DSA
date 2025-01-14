#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int n) {
    int ans =0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                int value = abs(matrix[i][j]);
                ans += value; 

                for (int k = 0; k < n - max(i, j); k++) {
                    matrix[i + k][j + k] += value;
                }
            }
        }
    }
    
    return ans; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        int ans = solve(matrix, n); 
        cout << ans << endl;
    }   
    return 0;
}
