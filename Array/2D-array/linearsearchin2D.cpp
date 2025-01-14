#include<iostream>
using namespace std;

bool ispresent(int arr[][4],int target , int row , int col ){
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            if(arr[row][col]==target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    
    int arr[3][4];

    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];

        }
    }
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";

        }
        cout<<endl;
    }

    cout<<"enter the element to search"<<endl;
    int target;
    cin>>target;

    if(ispresent(arr,target,3,4)){
        cout<<"element found"<<endl;

    }
    else{
        cout<<"not found"<<endl;
    }

    return 0;
}
