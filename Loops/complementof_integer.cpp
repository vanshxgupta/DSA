//complement;
//the complement of an intger is the integer you get 
//when you flip all the 0's to 1's 
//and all the 1's to 1's in its binary representation
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int m=n;
    int mask=0;
    if(n==0){
        cout<<1<<endl;
    }
    else{
    while(m!=0){
        mask=(mask<<1)|1;
        m=m>>1;

    }
    int ans=(~n)&mask;
    cout<<ans;
        
    }


    
}