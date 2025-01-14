// A
// BB
// CCC
// DDDD
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char i=65;
    char count=65;
    while(i<=65-1+n){
        int j=1;
        while(j<=i-64){
            cout<<i;

            j=j+1;
            count=count+1;


        }cout<<endl;
        i=i+1;

    }
}