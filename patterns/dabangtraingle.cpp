// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1
// **********
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    int z=n*2;
    while(i<=n){
        //first triangle;
        int j=1;
        while(j<=n-i+1){
            cout<<j;
            j=j+1;
            
        }
        

        //stars first triangle;
        int s=1;
        while(s<=i-1){
            cout<<"*";
            s=s+1;

        }//stars second trainfle;
        int t=1;
        while(t<=i-1){
            cout<<"*";
            t=t+1;

        }//last traingle;
        int k=n-i+1;
        while(k){
            cout<<k;
            k=k-1;

        }cout<<endl;
        i+=1;
        



    } 
   //last line of stars
    while(i<=z){
        cout<<"**";
        i=i+1;
    }
    
    return 0;
    

}