#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[s];

    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;

        }
    }

    //place pivot at right position
    int pivotindex=s+cnt;
    swap(arr[pivotindex],arr[s]);

    //left and right wala part smbhal lete h 
    int i=s,j=e;
    while(i<pivotindex &&j>pivotindex){
        while(arr[i]<=pivot){//agar esa hai tooh clne do sahi chlra hai 
            i++;
        }
        while(arr[j]>=pivot){
            j--;
        }

        if(i<pivotindex && j>pivotindex){//nahi tooh swap karna padega
            swap(arr[i++],arr[j--]);
        }
    }


}

//quicksort-->partion-->recursion
void quicksort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return ;
    }

    //partion
    int p=partition(arr,s,e);

    //left part sort 
    quicksort(arr,s,p-1);

    //right wala part sort
    quicksort(arr,p+1,e);






}
int main(){
    int arr[5]={2,4,1,6,9};
    int n=5;

    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

    return 0;
    
}

//Method 2 

// int partition(vector<int> &arr, int start, int end) {
//     int pivot = arr[end]; // Choose the pivot as the last element
//     int pivotIndex = start;

//     for (int i = start; i < end; i++) {
//         if (arr[i] <= pivot) {
//             swap(arr[i], arr[pivotIndex]);
//             pivotIndex++;
//         }
//     }
//     swap(arr[pivotIndex], arr[end]);
//     return pivotIndex;
// }

// void solve(vector<int>&arr, int start, int end) {
//     if (start >= end)
//         return;

//     int p = partition(arr, start, end);
//     solve(arr, start, p - 1);
//     solve(arr, p + 1, end);
// }


// vector<int> quickSort(vector<int> arr)
// {
//    solve(arr,0,arr.size()-1);
//    return arr;
// }
