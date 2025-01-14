#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a=1;
    for(int i=n;i>=1;i--){

        //spaces wala triangle print kara lo pehle , 0 se n-1 space tak;
        for(int nsp=0;nsp<n-i;nsp++){
            cout<<" ";

        }
        
        for(int j=1;j<=i;j++){
            if(a<=9){
            cout<<a<<" ";}
            

            else if(a&1){
                cout<<"9 ";
            }
            else{
                cout<<"0 ";
            }
            a++;


        }
        cout<<endl;

        
    }
    
int last=pow(n,2)+n-1;
int b=9;
    for(int i=2;i<=n;i++){

        //space triangle;
        for(int nsp=n-i-1;nsp>=0;nsp--){
            cout<<" ";
        }

        for(int j=1;j<=i;j++){
            if(a<=last && a>last-9){
                cout<<b<<" ";
                b--;
            }

            else if(a&1){
                cout<<"9 ";
            }
            else{
                cout<<"0 ";
            }
            a++;
            
        }
        cout<<endl;


    }
}