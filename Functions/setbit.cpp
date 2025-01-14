//find the total number of set bit 
//kitne number of 1 hai ye find karna hai

#include<iostream>
#include<math.h>

using namespace std;
int setbit(int n){
    int count=0;

    while(n!=0){
        
        if(n&1){
            count++;
        }
        n=n>>1;


    }
    return count ;


}


int main(){
    int a;
    int b;
    cin>>a>>b;
    int ina=setbit(a);
    int inb=setbit(b);
    cout<<"set bits of a ="<<ina<<endl;
    cout<<"set bits of b ="<<inb<<endl;
    int ans=ina+inb;
    cout<<"total number of setbit is "<<ans<<endl;
    return 0;
}
    
