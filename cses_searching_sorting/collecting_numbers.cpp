// Store the position of every number. A new round is needed whenever i+1 appears before i in the array (pos[i] > pos[i+1]).
// The problem is about the order of consecutive values (1→2→3...), not adjacent array elements. Count position inversions of consecutive numbers.

#include <bits/stdc++.h>
using namespace std;

int  main() {
	
	long long  n;
	cin>>n;
	
	vector<long long >x(n);
    vector<int>positions(n+1);
	for(long long  i=0;i<n;i++){
	    int val;
	    cin>>val;
        x[i]=val;
        positions[val]=i+1;
	}
	
    // 4 2 1 5 3
    // 3 2 5 1 4
    
    int rounds=1;
    for(int i=2;i<=n;i++){
        if(positions[i]<positions[i-1]){
            rounds++;
        }
    }
    cout<<rounds<<endl;

}
