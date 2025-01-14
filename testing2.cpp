#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int onefromeach(int n, int k, vector<int>& arr) {
    int cntans = 0;

    // Continue until we collect k cans
    while (k > 0) {
        bool buttonPressed = false;  // Track if we pressed any button in this round

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                // If no cans left, we still pressed the button, but no cans drop
                cntans++;
                buttonPressed = true;  // A button press happened
            } else if (arr[i] > 0) {
                // Take one can from this slot
                arr[i]--;
                k--;
                cntans++;  // Count the button press
                buttonPressed = true;  // A button press happened
                if (k == 0) break;  // Stop when we collected k cans
            }
        }

        // We only increment the round if at least one button was pressed
        if (buttonPressed && k > 0) {
            cntans++;  // After a full round of presses
        }
    }

    return cntans;
}

int uptoempty(int n, int k, vector<int>& arr) {
    int cntans = 0; 
    int cansCollected = 0; 

    sort(arr.begin(), arr.end());  // Sort in ascending order

    for (int i = 0; i < n && cansCollected < k; i++) {
        if (cansCollected + arr[i] >= k) {
            cntans += k - cansCollected;  // Only take as many cans as needed to reach k
            cansCollected = k;
        } else {
            cntans += arr[i];  // Press button arr[i] times
            cansCollected += arr[i];  // Collect all cans from this slot
            cntans++;  // Count the button press when the slot becomes empty
        }
    }

    return cntans;
}

int solve(int n, int k, vector<int>& arr) {
    vector<int> arrCopy = arr;  // Copy array for use in onefromeach

    int ans1 = onefromeach(n, k, arrCopy);  // Calculate answer using onefromeach strategy
    int ans2 = uptoempty(n, k, arr);  // Calculate answer using uptoempty strategy
    
    // Return the minimum of both strategies
    return min(ans1, ans2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(n, k, arr) << endl;
    }

    return 0;
}
