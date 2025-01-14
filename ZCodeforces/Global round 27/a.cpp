#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long t;
  cin >> t;

  while (t--) {
    long long n,m,r,c;
    cin>>n>>m>>r>>c;

    cout<<(m-c)+2*(n-r)*(m-1)+(n-r)<<endl;
    
}   
  return 0;
}