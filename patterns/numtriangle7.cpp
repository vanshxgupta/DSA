//    1
//   121
//  12321
// 1234321
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){//space
        int j=1;int space=1;
        while(space<=n-i){
            cout<<" ";
            space=space+1;

        }
        while(j<=i){
            //1st traingle
            cout<<j;
            
            j=j+1;

        

        }
        //2nd traingle
        int start=i-1;
        while(start){
            cout<<start;
            start=start-1;
        }

        i=i+1;
        cout<<endl;
        

    }return 0;
    

}