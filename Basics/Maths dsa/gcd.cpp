//gcd is  hcf

#include<iostream>
using namespace std;
//formula for finding gccd: gcd(a,b)=gcd(a-b,b);
// int gcd(int a, int b){
//     if(a==0){
//         return b;

//     }
//     if(b==0){
//         return a;

//     }
//     while(a!=b){
//         if(a>b){
//             a=a-b;
//         }
//         else{
//             b=b-a;
//         }     
//     }
//     return a;

// }

int gcd(int a,int b){
  if(b==0){
    return a;
  }
  
  return gcd(b,a%b);
}

int main(){
    int a,b;
    cout<<"enter the values of a and b"<<endl;

    cin>>a>>b;
    int ans=gcd(a,b);
    cout<<"gcd/hcf of a and b is "<<ans<<endl;
}