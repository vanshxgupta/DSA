
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

#define input2D(a,n,m) for(long long _i=0;_i<n;_i++) for(long long _j=0;_j<m;_j++) cin >> a[_i][_j];
#define print2D(a,n,m) for(long long _i=0;_i<n;_i++){ for(long long _j=0;_j<m;_j++) cout << a[_i][_j] << " "; cout << "\n"; }

// vector<vector<int>> mat(n, vector<int>(m));
//  input2D(mat, n, m);  


typedef long long ll;
long long mod=1e9+7;

vector<vector<long long>>dp;
long long n;
long long solve(long long ind,vector<int>&a,long long sumleft){
    if(ind==n-1){
        if(sumleft%a[ind]==0) return (sumleft/a[ind]);
        else return LLONG_MAX;
    }
    if(dp[ind][sumleft]!=-1) return dp[ind][sumleft];

    long long take=LLONG_MAX;
    long long nottake=solve(ind+1,a,sumleft);

    if(sumleft>=a[ind]){
        long long val=solve(ind,a,sumleft-a[ind]);
        if(val!=LLONG_MAX){
            take=1+val;
        }
        // cout<<"take"<<take<<" ";
    }

    return dp[ind][sumleft]=min(take,nottake);
}

int main() {
    fast_io;
    long long N;
    cin >> N;
    n=N;

    long long x;
    cin>>x;

    vector<int>a(n);
    input(a);

    dp.assign(n+1,vector<long long>(x+1,-1));
    if(solve(0,a,x)==LLONG_MAX) cout<<-1<<endl;
    else 
    cout<<solve(0,a,x)<<endl;

    return 0;


    
}


//iterative : cses par recusrion runtime dera hai kuch test cases par , sirf iterative chalega 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, x;
    cin >> n >> x;
 
    vector<long long> vec(n);
    for (long long i = 0; i < n; i++) {
        cin >> vec[i];
    }
 
    vector<long long> dp(x + 1, LLONG_MAX);
    dp[0] = 0;
 
    for (long long i = 1; i <= x; i++) {
        for (long long j = 0; j < n; j++) {
            if (i >= vec[j] && dp[i - vec[j]] != LLONG_MAX) {
                // "Agar main i-c sum ko minimum coins se bana sakta hoon, toh i sum ko banaane ke liye wohi coins + 1 (current coin) kar sakta hoon."
                dp[i] = min(dp[i], dp[i - vec[j]] + 1);
            }
        }
    }
 
    if (dp[x] >= LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

}
