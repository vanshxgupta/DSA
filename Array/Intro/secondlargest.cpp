#include<iostream>
using namespace std;

int secondlargest(int arr[],int n){
    int maxi=-500000;
    int smaxi=-25000;

    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            smaxi=maxi;
            maxi=arr[i];
        }//{7,6,5,4,3,2,1}-->iss tarah ke decreasing array mai kaam  nahi karegi if statement isliye humko else if likhne ki jarurt padi 
        else if(smaxi<arr[i] && maxi!=arr[i]){
            smaxi=arr[i];
        }


    }

    return smaxi;

}
int main(){
    int arr[6]={7,6,2,4,3,1,5};
    cout<<secondlargest(arr,6);
    return 0;

}