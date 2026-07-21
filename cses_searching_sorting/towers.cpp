#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;

    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    multiset<int>ms;
    for(int i=0;i<n;i++){
        auto it=ms.upper_bound(vec[i]);
        if(it==ms.end()){
            ms.insert(vec[i]);
        }
        else{
            ms.erase(it);
            ms.insert(vec[i]);
        }
    }
    
    cout<<ms.size()<<endl;

}