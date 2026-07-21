#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
#define reversi(a) reverse(a.begin(), a.end())

#define input2D(a,n,m) for(int _i=0;_i<n;_i++) for(int _j=0;_j<m;_j++) cin >> a[_i][_j];
#define print2D(a,n,m) for(int _i=0;_i<n;_i++){ for(int _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);

typedef long long ll;

int main()
{
    fast_io;

    int x, n;
    cin >> x >> n;

    vector<int> p(n);
    input(p);

    set<int> st;      // positions of the traffic lights in sorted order
    multiset<int> ms; // lengths of the passage without traffic lights

    st.insert(0);
    st.insert(x);

    ms.insert(x);

    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        int ele = p[i];
        auto it = st.upper_bound(ele);
        int nexttrafficlight = *it;
        it--;
        int prevtrafficlight = *it;

        int length = nexttrafficlight - prevtrafficlight;
        ms.erase(ms.find(length));
        
        st.insert(ele);
        ms.insert(nexttrafficlight - ele);
        ms.insert(ele - prevtrafficlight);
        ans.push_back(*ms.rbegin());
    }
    // ans.push_back(*ms.rbegin());

    print(ans);
    return 0;
}
