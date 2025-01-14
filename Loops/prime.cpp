#include<iostream>
using namespace std;
int main(){
    long long n;
    cout<<"enter value of n"<<endl;
    cin>>n;
    bool isprime=1;

    for(long long  i=2;i<n;i++){
        if(n%i==0){
            
            isprime=0;
            break;

        }
    }
    if(isprime==0){
        cout<<"not a prime no."<<endl;

    }else{
        cout<<"is a prime no."<<endl;
    }
}