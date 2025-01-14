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

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int len1 = n;   
        for (int i = 1; i < len1; i++) {  
            
            if (a[i] == len1+ 1 - (i + 1)) {  
                a.resize(len1 + i);  
                len1 += i;          
                i = 0;            
        }
        }
        int len2 = n;   
        for (int i=len2-1;i>0;i--) {  

            if (a[i] == len2 + 1 - (i + 1)) {  
                a.resize(len2 + i);  
                len2 += i;         
                i = len2-1;             
            }
        }

        int ans=max(len1,len2);
        cout << ans << endl;  
    }
  
    return 0;
}

