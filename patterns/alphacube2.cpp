// ABCD
// EFGH
// IJKL
// MNOP
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    char count=65;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<count;

            j=j+1;
            count=count+1;


        }cout<<endl;
        i=i+1;

    }
}