// 1234
//  234
//   34
//    4
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    
    while(i<=n){
        int space=0;
        while(space<i-1){
            cout<<" ";
            space=space+1;
        }
        int j=1;int num=1;
        while(j<=n-i+1){

            cout<<j+i-1;
            
            j=j+1;

        }
        cout<<endl;
        i=i+1;
    }
}