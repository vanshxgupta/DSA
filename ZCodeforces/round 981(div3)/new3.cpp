#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int size = (n + 1) / 2;
        vector<vector<int>> dp(size, vector<int>(2, 0)); // dp[i][0] and dp[i][1] represent states without/with a swap

        dp[0][0] = 0; // Base case, no swap
        dp[0][1] = 0; // Base case, swap

        for (int i = 1; i < size; i++) {
            // Transition with no swap
            dp[i][0] = min(dp[i - 1][0] + (a[i] == a[i - 1]) + (a[n - i - 1] == a[n - i]),
                           dp[i - 1][1] + (a[i] == a[n - i]) + (a[n - i - 1] == a[i - 1]));

            // Transition with swap
            dp[i][1] = min(dp[i - 1][1] + (a[i] == a[i - 1]) + (a[n - i - 1] == a[n - i]),
                           dp[i - 1][0] + (a[i] == a[n - i]) + (a[n - i - 1] == a[i - 1]));
        }

        int ans = min(dp[size - 1][0], dp[size - 1][1]);

        // Adjust answer for even-length case
        if (n % 2 == 0) {
            ans += (a[n / 2 - 1] == a[n / 2]);
        }

        cout << ans << endl;
    }
    return 0;
}
