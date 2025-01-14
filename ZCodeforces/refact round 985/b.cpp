#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        string r;
        cin >> r;

        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        if(mp['0']==0 || mp['1']==0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
        int flag=0;
        for(int i=0;i<n-1;i++){
            mp['0']--;
            mp['1']--;
            if(mp['0']==0 && mp['1']==0){
                cout<<"YES"<<endl;
                break;
            }

            else{
            if(r[i]=='0'){
                mp['0']++;
            }
            else{
                mp['1']++;
            }
            }
            if(mp['0']==0 || mp['1']==0){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }

        }
        }

    }
}
