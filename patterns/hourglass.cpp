#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;


    for(int i=n;i>=1;i--){

        //spaces wala triangle print kara lo pehle , 0 se n-1 space tak;
        for(int nsp=0;nsp<n-i;nsp++){
            cout<<" ";

        }
        
        for(int j=1;j<=i;j++){
            cout<<"* ";

        }
        cout<<endl;

        
    }

    for(int i=2;i<=n;i++){

        //space triangle;
        for(int nsp=n-i-1;nsp>=0;nsp--){
            cout<<" ";
        }

        for(int j=1;j<=i;j++){
            cout<<"* ";
             
        }
        cout<<endl;


    }
}