//given a signed 32 bit integer x, return x with its digits reversed.
//if it go outside intger range , then return 0;
#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    while(n!=0){
        int digit=n%10;
        if((ans>INT_MAX/10)||(ans<=INT_MIN/10)){
            return 0;
        }
        ans=(ans*10)+digit;

        n=n/10;
        

    }
    cout<<ans;
}