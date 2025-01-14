// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

// You need to find and return that number which is unique in the array/list.

//  Note:
// Unique element is always present in the array/list according to the given condition.



// int findUnique(int *arr, int size)
// {//2M+1 se ye batana chahte hai ke array ke andr odd number of elements hai 
//     int ans=0;
//     for(int i=0;i<size;i++){
//         ans=ans^arr[i];//xor operator ko agar do same value dikh gayi tooh vo 0 dega 
//         //aur jo unique element bacha hai uska xor 0 ke saath milke vahi element return karega

//     }
//     return ans;
// }

#include<iostream>
using namespace std;

void searchu(int arr[], int size){
    for(int i =0 ;i<size;i++){
        int count=0;
        for(int a= 0; a<size;a++){
          
            if (arr[i]!=arr[a]){
                count++;
            }
        }
        if(count==size-1){
            cout<< arr[i]<< " ";
        }
        
        }
    }


 int main(){
    int arr[5]={3,56,3,2,5};
    searchu(arr,5);
 }