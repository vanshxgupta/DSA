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
 
typedef pair<long long,pair<long long,long long>> pii;
typedef long long ll;
 
long long n,m;

int main() {
    fast_io;

    cin >> n>>m;

    vector<vector<pair<long long,long long>>>adj(n+1);
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long len;
        cin>>u>>v>>len;
        adj[u].push_back({v,len});
    }

    //dist[u][0]->minimum distance to reach from source to u with 0 coupon used
    //dist[u][1]->minimum distance to reach from source to u with 1 coupon used
        
    vector<vector<long long>>dist(n+1,vector<long long>(2,LLONG_MAX));
    priority_queue<pii,vector<pii>,greater<pii>>q;
    //{distance,{node,state}}

    q.push({0,{1,0}});
    //source distance with changes and wthout changes is 0 only 
    dist[1][0]=0;
    dist[1][1]=0;

    while(!q.empty()){
        long long node=q.top().second.first;
        long long length=q.top().first;
        long long state=q.top().second.second;
        q.pop();

        if(length > dist[node][state]) continue;
       
        for(auto &it:adj[node]){
            ll nextnode=it.first;
            ll weight=it.second;

            if(state==0){
                //without changes
                if(length+weight<dist[nextnode][0]){
                    dist[nextnode][0]=length+weight;
                    q.push({dist[nextnode][0],{nextnode,0}});
                }
                //use coupon this time 
                if(length+(weight/2)<dist[nextnode][1]){
                    dist[nextnode][1]=length+(weight/2);
                    q.push({dist[nextnode][1],{nextnode,1}});
                }
            }
            else{
                //already coupon used
                if(length+weight<dist[nextnode][1]){
                    dist[nextnode][1]=length+weight;
                    q.push({dist[nextnode][1],{nextnode,1}});
                }
            }
        }
    }a
    
    cout<<dist[n][1]<<endl;//returing the distance to reach n from 1 with exactly 1 change
   
    return 0;
}