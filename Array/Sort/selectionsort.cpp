// Selection sort is one of the sorting algorithms that 
// works by repeatedly finding the minimum element from the
// unsorted part of the array and putting it at the beginning of the unsorted region of the array.

//  You are given an unsorted array consisting of N 
// non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{   
    //intially hamne starting element jo array mai 
    //hai usko hi minimum maan liya hai , aage jab 
    //bhi usse chota element aayega tooh swap kar denge

    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n-1;i++){
            if(arr[j]<arr[minindex]){
                minindex=j;//minindex ko update kar diya 

            }
        }
        swap(arr[minindex],arr[i]);//arr mai elements swap ho jayenge isse
        
    }
}
int main(){
    int arr[5]={3,7,6,8,9};
    selectionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
        
    }
   

}

