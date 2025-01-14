#include<iostream>
using namespace std;

int power(int base, int pow){
    
    if(pow==0)return 1;
    if(pow==1) return base;

    //recursive call
    int ans=power(base,pow/2);
    if(pow%2==0){
        return ans*ans;
    }
    else{
        return ans*ans*base;
    }

}
int main(){
    int base,pow;
    cin>>base>>pow;
    cout<<power(base,pow);
    
}