#include <bits/stdc++.h>
using namespace std;
 
int  main() {
	
	long long  n;
	cin>>n;
	
	vector<long long >coins(n);
	for(long long  i=0;i<n;i++){
	    
	    cin>>coins[i];
	    
	}
	
	sort(coins.begin(),coins.end());
	long long  smallest=1;
	for(long long  i=0;i<n;i++){
	    if(smallest>=coins[i]){
	        smallest=smallest+coins[i];
	    }
	    else{
	        break;
	    }
	}
	
	cout<<smallest<<endl;
 
}
