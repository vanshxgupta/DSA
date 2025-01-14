//print the sum of fibo numbers upto n 
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

int sumfibo(int n){
    
    if(n==2){
        return 2;
    }
    int sum=fibo(n)+sumfibo(n-1);
    return sum;
    
}


int main(){
    int n;
    cin>>n;
    
    cout<<sumfibo(n);


}