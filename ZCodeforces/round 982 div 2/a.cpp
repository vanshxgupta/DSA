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

        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            int wi, hi;
            cin >> wi >>hi;
            vec[i] = {wi, hi};
        }

        int maxw = 0, maxh = 0;
        for (int i = 0; i < n; i++) {
            maxw = max(maxw, vec[i].first); 
            maxh = max(maxh, vec[i].second);
        }
        int perimeter = 2 * (maxw + maxh);

        cout << perimeter << endl;
    }

    return 0;
}
