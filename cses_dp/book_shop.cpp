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
int n;
int x;
vector<vector<int>>dp;
int solve(vector<int>&pages, vector<int>&prices,int ind,int remainingamount){
    if(ind>=n) return 0;
    //memo check 

    if(dp[ind][remainingamount]!=-1) return dp[ind][remainingamount];
    int take=INT_MIN;
    if(remainingamount>=prices[ind]){
        take=pages[ind]+solve(pages,prices,ind+1,remainingamount-prices[ind]);
    }
    int nottake=solve(pages,prices,ind+1,remainingamount);

    return dp[ind][remainingamount]=max(nottake,take);
}
int main() {
    fast_io;
    cin >> n>>x;

    dp.resize(n+1,vector<int>(x+1,-1));

    vector<int> prices(n);
    input(prices);
    vector<int> pages(n);
    input(pages);
    
    cout<<solve(pages,prices,0,x)<<endl;

    return 0;
}



//iterative 
#include <bits/stdc++.h>
using namespace std;
 
 
//state->dp[i][j]->maximum number of pages I can get (0.....i)books, and maximumm cost can be j
 
//transition equation=max(dp[i-1][j-cost[i]]+pages[i],dp[i-1][j]+0)
 
 
int main() {
	int n,x;
	cin>>n>>x;
	
	vector<int>h(n);
	for(int i=0;i<n;i++){
	    cin>>h[i];
	}//cost 
	
	vector<int>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}//pages
	
	vector<vector<int>>dp(n,vector<int>(x+1,0));
	       //dp[i][j]
	       
 
	 for(int i=0;i<n;i++){
	     for(int j=0;j<=x;j++){
 
	         int pick=0;
	         if(j>=h[i]){
	             pick=s[i];
	             if(i>=1)
	         pick+=dp[i-1][j-h[i]];
	         }
	         int notpick=0;
	         if(i>=1) notpick=dp[i-1][j];
	         
	         dp[i][j]=max(notpick,pick);
	     }  
	 }
	 
	 
    cout<<dp[n-1][x]<<endl;
	
 
}