#include<iostream>
using namespace std;
int main(){
    cout<<"enter number:"<<endl;
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
       
        for(int j=1; j<=i; j++){
           if((i+j)%2==0){ cout<<"1";}
           else{cout<<"0";

           }
        }
        
         cout<<endl;

    }
}
