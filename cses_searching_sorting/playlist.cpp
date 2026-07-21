#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;

    vector<int>playlist(n);
    for(int i=0;i<n;i++){
        cin>>playlist[i];
    }

    set<int>st;
    int i=0;
    int j=0;
    int maxi=0;

    while(j<n){
        while(i<=j && st.count(playlist[j])){
            st.erase(playlist[i]);
            i++;
        }
        st.insert(playlist[j]);
        int sizi=st.size();
        maxi=max(maxi,sizi);
        j++;
    }

    cout<<maxi<<endl;

}