// Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

// You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{   
    for(int i=1;i<n;i++){
        bool swapped = false;

        
        for(int j=0;j<n-i;j++){//n-i tak isliye chalaya kyunki , har ith round mai ith largest element
                                // right corner mai set hota jayega tooh uska check karne ki jarurt nahi hai 
            if(arr[j]>arr[j+1]){//agar age wala element bada hai tooh un dono ko swap kar do

                swap(arr[j],arr[j+1]);
                swapped= true;


            }
            

        }
        if(swapped==false){
            break;
            
            
        }
        
        
    }
}
int main(){
    int arr[5]={3,7,6,9,8};
    bubbleSort(arr,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";

    }
    return 0;

}