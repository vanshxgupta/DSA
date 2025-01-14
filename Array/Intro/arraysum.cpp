#include<iostream>
using namespace std;
int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];

        
        
    }
    return sum;


}
int main(){

    int size;
    cin>>size;
    int arr[100];
    cout<<sum(arr,size);


}