//if are given an array of 0,1 numbers then we have to sort 
//the array by putting all the the zeros on left and 1 on right 
#include<iostream>
using namespace std;

void printarray(int arr[],int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void sortone(int arr[],int n){
    int step=0;
    int left=0,right=n-1;
    while(left<right){
        cout<<"step"<<step++<<endl;
        printarray(arr,n);
        cout<<endl;
        while(arr[left]==0 && left<right){
            left++;//agar 0 left mai mil gaya tooh agye badh jao
        }
        while(arr[right]==1 && left<right){
            right--;//1 ke liye right side se check karenge ,agar 1 hoga tooh piche aate jao 

        }
        //agar yaha pauch gye ho,iska matlab 
        //arr[left]==1 and arr[right]==0
        if(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }

        


    }
    cout<<"returning the sorted array"<<endl;
    printarray(arr,8);
}
int main(){
    int arr[8]={1,1,0,1,0,1,0,0};
    sortone(arr,8);
    printarray(arr,8);


}