//     *
//    **
//   ***
//  ****
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        //space print karlo
        int space=n-i;
        while (space>=0){
            cout<<" ";
            space=space-1;

        }
        //stars print karlo 
        int j=1;
        while(j<=i){
            cout<<"*";
            j=j+1;

        }
        cout<<endl;
        i=i+1;
    }
}