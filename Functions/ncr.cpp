#include<iostream>
using namespace std;
int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
        
    }
    return fact;
}
int ncr(int n, int r){
    int num= fact(n);
    int deno=fact(r)*fact(n-r);
    int ncr=num/deno;
    return ncr;

}
int main(){
    int n,r ;
    cin>>n>>r;
    cout<<"answer is "<<ncr(n,r)<<endl;
    return 0;
}