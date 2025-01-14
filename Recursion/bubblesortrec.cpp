#include<iostream>
using namespace std;

void sortarray(int *arr,int n){

    //base case
    if (n==0 || n==1){
        return ;
    }

    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);//ese krke ye loop  ek ek highest elment ko last positiont tak pahucha dega 
        }

    }
    sortarray(arr,n-1);


}
int main(){
    int arr[5]={2,5,1,6,3}
;
sortarray(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}
}