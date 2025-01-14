#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid=s+(e-s)/2;

    //length naap lo do chote arrays ke jo ki bade array se tut ke bane hai
    int len1=mid-s+1;
    int len2=e-mid;

    //array bna lo do 
    int *first=new int[len1];
    int *second= new int[len2];


    //copy values
    int mainarrayindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainarrayindex++];

    }
    for(int i=0;i<len2;i++){
        second[i]=arr[mainarrayindex++];
    }

    //merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainarrayindex=s;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainarrayindex++]=first[index1++];

        }
        else{
            arr[mainarrayindex++]=second[index2++];

        }

    }
    while(index1<len1){
        arr[mainarrayindex++]=first[index1++];

    }
    while(index2<len2){
        arr[mainarrayindex++]=second[index2++];
    }

    delete [] first;
    delete []second;//heap memory ko manaully dlete krna pdhta hai 
    

}

void mergesort(int *arr,int s,int e){
    //base case
    
    if(s>=e) return;
    int mid=s+(e-s)/2;


    //left part sort krna hai 
    mergesort(arr,s,mid);

    //right part sort karna hai 
    mergesort(arr,mid+1,e);

    //merge
    merge(arr,s,e);

}
int main(){
    int arr[5]={2,1,7,4,5};
    int n=5;
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}
