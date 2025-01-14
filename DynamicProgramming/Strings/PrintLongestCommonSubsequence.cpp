#include <iostream>
#include <vector>
#include <string>
using namespace std;

void lcs(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Base case initialization
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) { // Changed from n to m
        dp[0][j] = 0;
    }

    // Filling the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of LCS
    int len = dp[n][m];
    string ans(len, '$'); // Resize the string to the length of LCS

    int index = len - 1;
    int i = n, j = m;

    // Backtracking to find the LCS
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans[index] = s[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Print the LCS
    cout << ans << endl;
}

int main() {
    string s = "abcde";
    string t = "bdgek";
    lcs(s, t);
    return 0;
}
