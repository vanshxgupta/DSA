// -> dijsktra +dp
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define input(a) for(auto &x : a) cin >> x;
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sorti(a) sort(a.begin(), a.end())
#define rsorti(a) sort(a.rbegin(), a.rend())
 
#define input2D(a,n,m) for(long long _i=0;_i<n;_i++) for(long long _j=0;_j<m;_j++) cin >> a[_i][_j];

// vector<vector<long long>> mat(n, vector<long long>(m));
//  input2D(mat, n, m);  
 
typedef long long ll;
typedef pair<ll,ll> pi;

ll mod=1e9+7;
long long n,m;

int main(){
    fast_io;
    cin >> n>>m;

    vector<vector<pi>>adj(n+1);
    // vector<vector<long long>>graph;
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long len;
        cin>>u>>v>>len;
        adj[u].push_back({v,len});
        // graph.push_back({u,v,len});
    }

    // -> dijsktra
    // what is the minimum price of such a route? 
    // how many minimum-price routes are there?

    // what is the minimum number of flights in a minimum-price route? ->shortest route with minimum price
    // what is the maximum number of flights in a minimum-price route? ->longest route with minimum price 

    vector<vector<ll>>dp(n+1,vector<ll>(4,0));
    //dp[n][0]->minimum price from 1 to n 
    //dp[n][1]->no. of ways of minimum price from 1 to n 
    //dp[n][2]->shortest route with minimum price from 1 to n 
    //dp[n][3]->longest route with minimum price from 1 to n 

    dp[1]={0,1,0,0};

    //dp table llialization
    for(ll i=2;i<=n;i++){
        dp[i][0]=LLONG_MAX;
        dp[i][1]=0;
        dp[i][2]=LLONG_MAX;
        dp[i][3]=LLONG_MIN;
    }

    priority_queue<pi,vector<pi>,greater<pi>>pq;//{price,node}
    pq.push({0,1});


    while(!pq.empty()){
        ll node=pq.top().second;
        ll price=pq.top().first;
        
        pq.pop();

        if(price>dp[node][0]){
            continue;
        }

        for(auto &it:adj[node]){
            ll nextnode=it.first;
            ll nextprice=it.second;

            if((price+nextprice)<dp[nextnode][0]){//update the price
                dp[nextnode][0]=(price+nextprice);
                dp[nextnode][1]=dp[node][1]%mod;//llitize the route ->we can reach this node "nextnode" with same number of routes we can take to reach node
                dp[nextnode][2]=dp[node][2]+1;
                dp[nextnode][3]=dp[node][3]+1;
                pq.push({price + nextprice,nextnode});
            }
            else if((price+nextprice)==dp[nextnode][0]){//update the routes in that price
                dp[nextnode][0]=(price+nextprice);
                dp[nextnode][1]=(dp[nextnode][1]+dp[node][1])%mod;//add nextnode ways + node ways 
                dp[nextnode][2]=min(dp[nextnode][2],dp[node][2]+1);
                dp[nextnode][3]=max(dp[nextnode][3],dp[node][3]+1);
                // pq.push({price + nextprice,nextnode});->ye nahi aayega 
            }
        }
    }
    
    cout<<dp[n][0]<<" "<<dp[n][1]%mod<<" "<<dp[n][2]<<" "<<dp[n][3]<<endl;

    return 0;

}