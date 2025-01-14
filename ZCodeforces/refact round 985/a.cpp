#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;

  while (t--) {
    int l;
    int r;
    int k;
    cin>>l>>r>>k;

    int cnt=0;
    if(k==1){
        cout<<(r-l+1)<<endl;
    }

    else{
        int ans=r/k;
        if(ans>=l){
        cout<<(ans-l+1)<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }   
}
  return 0;
}