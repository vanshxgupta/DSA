//negative decimal  to binary
#include<iostream>
#include<math.h>

using namespace std;
int main(){
    long long int n;
    cin>>n;
    unsigned long long int i=0, ans=0;
    if(n<0){
        n=pow(2,16)+n;

    }
    cout<<n<<endl;
    while(n){
        int bit=n&1;
        ans=(pow(10,i)*bit)+ans;
        n=n>>1;
        i++;
    
    }
    cout<<ans<<endl;
}