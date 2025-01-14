#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    cout<<"enter number";
    int n;
    cin>>n;
    int nsp=0;
    int count=0;
    for(int k=0; k<=INT_MAX; k++){
        for(int i=1; i<=6; i++)
        {

             for(int j=1; j<=nsp; j++)
        {
            cout<<"  ";
        }
        cout<<"* ";
        count++;
        if(i<4){
            nsp++;

        }
        else{
            nsp--;
        }
        if(count==n)break;
        cout<<endl;
        }
   if(count==n)break;
    }
 
    
}