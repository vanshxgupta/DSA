#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);

int main() {
    fast_io;

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> paired;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        paired.push_back({b, a}); // {end, start}
    }

    // Sort by end time
    sort(paired.begin(), paired.end());

    multiset<int> ms;
    // Initialize K machines that are free at time 0 (or -1, depending on constraints)
    for(int i = 0; i < k; i++) {
        ms.insert(0); 
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int start = paired[i].second;
        int end = paired[i].first;

        // Find the first machine that becomes free strictly AFTER our start time
        auto it = ms.upper_bound(start);

        // If it == ms.begin(), all machines become free after our start time.
        // We cannot pick this interval.
        if(it != ms.begin()){
            // Move iterator back by 1 to get the machine that becomes 
            // free closest to, but <= our start time.
            --it; 
            
            // Assign this interval to that machine
            ms.erase(it);        // Remove the old free time
            ms.insert(end);      // Insert the new free time
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    return 0;
}