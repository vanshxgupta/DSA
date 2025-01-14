//search a element in a rotated sorted array

#include<iostream>
#include<vector>
using namespace std;
int pivot(vector<int>& arr,int size){
    int s = 0;
    int e= size -1 ;
    int mid = s +(e-s)/2;
    while(s<e){
    if (arr[mid]>= arr[0]){
        s=mid +1;
    }
    else{
        e = mid;
    }
    mid = s +(e-s)/2;
}
return s;
}
int binarysearch( vector<int>& arr, int start,int end , int key){
    int mid =start + (end - start )/2;
    while(start<=end){
        if (arr[mid]==  key){
            return mid;
        }
        if(key > arr[mid]){
            start= mid  +1;
            }
        else{
            end = mid - 1;
        }
        mid = start +(end - start)/2;

    }
    return -1;
}
//binary m e binary search rotaed array me
int findpos(vector<int>& arr,int n,int k){
    int pivotin = pivot(arr,n);
    if(k > arr[pivotin] && k <= arr[n-1]){
        return binarysearch(arr,pivotin,n-1,k) ;
    }   
    else{
        return binarysearch(arr,0,pivotin-1,k);
    }
}
int main(){
    vector<int> arr={8,9,2,3,4,5,7};
    cout<< findpos(arr,7,7);


}