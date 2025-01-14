#include<iostream>
using namespace std;

bool issorted(int arr[],int size){
    //base case
    if(size==0||size==1) return true;

    
    if(arr[0]>arr[1]){
    return false;
    }//issi tarah first do elements ko compare krte rahenge 

    else{
        //recursive relation
        bool remainingpart=issorted(arr+1,size-1);//recusive relation mai ham ,arr ki size kam kar rahe hai aage se 
        return remainingpart;
    }   
}
int main(){
    int arr[5]={2,4,12,9,9};
    bool ans=issorted(arr,5);
    if(ans){
        cout<<"sorted";

    }
    else{
        cout<<"not sorted";
    }

}