#include<bits/stdc++.h>

//In this we are using 0 based indexing 

void heapify(vector<int>&arr,int n,int i){

    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[smallest]>arr[left]){//yaha pe 0 based indexing ki hui hai isliye left<=n   less than equal to nahi lagaya sirf less than lagaya hai 
        smallest=left;
    }
    if(right<n && arr[smallest]>arr[right]){
        smallest=right;

    }

    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
    return ;
}
vector<int> buildMinHeap(vector<int> &arr)
{   
    int n=arr.size();
    for (int i = (n / 2)-1; i >= 0; i--) {
      heapify(arr, n, i);
    }
   return arr;

}
