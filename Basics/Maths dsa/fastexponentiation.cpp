//Also called as binary exponentiation
//Finding the power of a number with lower time complexity--i.e O(logN);

#include<iostream>
using namespace std;

int fastpower(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            //b is odd
            res=res*a;

        }
        a=a*a;
        b=b>>1;//b ko right shift kiya tooh vo aadha ho jyega 
    }
    return res;
}

int main(){
    int a;
    int b;
    cin>>a>>b;
    int ans=fastpower(a,b);;

    cout<<ans;
    

}