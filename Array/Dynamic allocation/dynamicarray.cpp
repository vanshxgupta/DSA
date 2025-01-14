#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int cnt = 0;
        int length =1;

        for (int i = 1; i< n; i++) {
            if (arr[i] == arr[i - 1]) {
                length++;
            } else {
                cnt += (length * (length + 1)) / 2;
                length = 1;
            }
        }
        cnt += (length* (length + 1)) / 2;

        cout << cnt << endl;
    }
    return 0;
}
