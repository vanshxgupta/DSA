#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define input(a)      \
    for (auto &x : a) \
        cin >> x;
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
#define reversi(a) reverse(a.begin(), a.end())

#define input2D(a, n, m)               \
    for (int _i = 0; _i < n; _i++)     \
        for (int _j = 0; _j < m; _j++) \
            cin >> a[_i][_j];
#define print2D(a, n, m)               \
    for (int _i = 0; _i < n; _i++)     \
    {                                  \
        for (int _j = 0; _j < m; _j++) \
            cout << a[_i][_j] << " ";  \
        cout << "\n";                  \
    }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);

typedef long long ll;

int main()
{
    fast_io;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    input(a);

    unordered_map<int, int> mp; // ele,freq
    set<pair<int, int>> st;     //-freq,ele

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        st.insert({-mp[a[i]], a[i]});
        if (i >= k - 1)
        {
            int val = st.begin()->second;
            ans.push_back(val);
            st.erase({-mp[a[i - k + 1]], a[i - k + 1]});
            mp[a[i - k + 1]]--;
            if (mp[a[i - k + 1]] == 0)
                mp.erase(a[i - k + 1]);
        }
    }

    print(ans);
    return 0;
}
