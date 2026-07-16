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

int main() {
    fast_io;

    int t;
    cin >> t;

    while (t--) {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    input(a);
        
    //    x<=y<=x+k

    map<int,int> mp;
    vector<int> vec;
    vector<int> freq;

    for(int i=0;i<n;i++){
       mp[a[i]]++;
    }

    for(auto &it:mp){
        vec.push_back(it.first);
        freq.push_back(it.second);
    }

    int sizi=vec.size();

    vector<int> state(sizi,0);

    bool flag=false;

    int losecnt =0;
    int r=sizi-1;

    for(int i=sizi-1;i>=0;i--){
       
        while(r>i && vec[r]>vec[i]+k){
            if(!state[r]){
                losecnt --;
            }
            r--;
        }

        if(losecnt>0){
            state[i]=1;
        }
        else{
            state[i]=0;
            if(freq[i]%2==0){
                state[i]++;
            }
        }

        if(state[i]==0){
            losecnt++;
        }

        if(state[i]==1){
            flag=true;
        }
        
    }

    if(flag){
        yes;
    }
    else{
        no;
    }

}



}
