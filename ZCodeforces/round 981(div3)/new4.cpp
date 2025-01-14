#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    int presum = 0;
    int cnt = 0;
    int lastind=-1;
    mp[0]= -1;

    for (int i = 0; i<n;i++) {
        presum += arr[i];

        if (mp.find(presum)!=mp.end() && mp[presum]>=lastind) {//check karo kya vo presum pehle aa chuka h ? agar aa chuka hoga mtlb uske bich mai koi esi value aayi hogi , jisme subarraysum=0 ho skta h
            cnt++;
            lastind=i;
        }

        mp[presum]=i;
    }

    cout<<cnt<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve(); 
    }

    return 0;
}
