//how to take input ;
//cin>>arr[i][j];

//output;
//cout<<arr[i][j];

#include<iostream>
using namespace std;

int main(){
    //create 2d array;
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//agar ese dalenge tooh row wise dalenge 
    //int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333};//1st row mai 1 11 111 1111 ayenge fir ...

    

    //taking input-->row wise input
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];

        }
    }
    
    //taking input-->col wise input 
     

    // for(int col=0;col<4;col++){
    //     for(int row=0;row<3;row++){
    //         cin>>arr[row][col];

    //     }
        

    // }
    //print
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";

        }
        cout<<endl;
        
    }
    return 0;
}

