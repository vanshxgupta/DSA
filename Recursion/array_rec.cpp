#include<iostream>
using namespace std;

void printarray(int arr[],int n,int index){

    //base case
    if(index==n){
        return ;

    }
    cout<<arr[index];
    printarray(arr,n,index+1);




}
int main(){
    int arr[]={1,2,3,4,5,6};
    int size=6;
    int index=0;
    printarray(arr,size,index);
}