// ABCD
// BCDE
// CDEF
// DEFG
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        char start='A'+i-1;
        while(j<=n){
            cout<<start;
            start=start+1;
            j=j+1;

        }cout<<endl;
        i=i+1;
    }
}