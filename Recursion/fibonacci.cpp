//print the fibonacci number
#include<iostream>
using namespace std;

int fibo(int n){
    
    if(n==1){
        return 1;
    }
    
    if(n==2){
        return 1;
    }
    
    int ans=fibo(n-2)+fibo(n-1);
    return ans;

}


int main(){
    int n;
    cin>>n;

    cout<<fibo(n);


}