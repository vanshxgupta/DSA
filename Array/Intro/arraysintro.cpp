#include<iostream>
using namespace std;
// int main(){
//     int number[15];
//     cout<<"everything is fine "<<endl;

//     return 0;

// }


int main(){
    int number[15];
    cout<<"value at 14 index "<<number[14]<<endl;//as we have to given any value it will give a garbage value 
    
    //intialising an array
    int second[3]={5,7,11};
    cout<<"value at 2nd index "<<second[2]<<endl;
    cout<<"everything is fine "<<endl;

    int third[15]={2,7};
    int n=15;
    cout<<"printing the array"<<endl;

    for(int i=0;i<=n;i++){
        cout<<third[i]<<" ";

    }

    //intialising full array with 0
    int fourth[10]={0};

    return 0; 
}
