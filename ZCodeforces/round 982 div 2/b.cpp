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
        
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) {
            cout << 0 << endl;
            continue;
        }

        vector<int> rotate_pts;
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1]) {
                rotate_pts.push_back(i);
            }
        }

        if (rotate_pts.size() == 1) {
            cout << rotate_pts[0] - 1 << endl;
        } else {
            int max_elem = arr[rotate_pts[0] - 1];
            int min_remove = rotate_pts[0] - 1;

            for (int i = 1; i < rotate_pts.size(); ++i) {
                if (arr[rotate_pts[i] - 1] > max_elem) {
                    max_elem = arr[rotate_pts[i] - 1];
                    min_remove = min(min_remove, rotate_pts[i] - 1);
                }
            }
            
            cout << min_remove << endl;
        }
    }

    return 0;
}
