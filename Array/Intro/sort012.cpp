//You have been given an integer array/list(ARR) of size 'N'. 
//It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

//dutch flag algo

// #include <bits/stdc++.h> 
// void sort012(int *arr, int n)
// {int low=0;
// int mid=0;
// int high=n-1;
// while(mid<=high){
//     if(arr[mid]==0){
//         swap(arr[mid], arr[low]);
//         mid++;
//         low++;

//     }
//     else if(arr[mid]==1){
//         mid++;

//     }else{
//         swap(arr[mid],arr[high]);
//             high--;
//     }
// }


// }



//count sort algo
#include<iostream>
using namespace std;

void sort012(int arr[],int n){
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
            
        }
        else if(arr[i]==1){
            count1++;
            
        }  
        else if(arr[i]==2){
            count2++;
            
        }      
    }
    for(int i=0;i<count0;i++){
        cout<<0;
    }
    for(int i=0;i<count1;i++){
        cout<<1;
    }
    for(int i=0;i<count2;i++){
        cout<<2;
    }
    

}
int main(){
    int arr[12]={0,1,2,0,1,2,1,2,0,0,0,1};
    sort012(arr,12);
    
}
