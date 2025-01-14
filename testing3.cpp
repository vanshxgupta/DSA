#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string sa;
	    string sb;
	    cin>>sa;
	    cin>>sb;
	    
	    unordered_map<char,int>mp;
	    
	    for(int i=0;i<n;i++){
	        mp[sa[i]]++;
	    }
	    for(int i=0;i<m;i++){
	        mp[sb[i]]++;
	    }
	    
	    unordered_map<char,int>check;
	    for(int i=0;i<26;i++){
	        char ch='a'+i;
	        check[ch]++;
	    }
	    
	    if(check==mp){
	        cout<<"NO"<<endl;
	    }
	    cout<<"YES"<<endl; 
	       
	       return 0;
	}

}
