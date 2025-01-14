#include<iostream>
using namespace std;

void print(int arr[],int s,int e){
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

}

bool binarysearch(int*arr,int s,int e ,int k){
    cout<<endl;
    print(arr,s,e);

    
    //base case
    if(s>e) return false;

    int mid=s+(e-s)/2;
    cout<<"value of arr mid is "<<arr[mid]<<endl;
    //element found
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){//right part mai aane ke liye
        return binarysearch(arr,mid+1,e,k);

    }
    else{//left part mai aane ke
        return binarysearch(arr,s,mid-1,k);

    }
}


int main(){
    int arr[5]={4,56,478,568,2980};
    int size=5;
    int key=60;
    cout<<"present or not "<<binarysearch(arr,0,5-1,key);

}
