#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;

}

void swapalternate(int arr[],int size){
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
            //how to swap without swap function
            //temp=arr[i+1];
            //arr[i+1]=arr[i];
            //arr[i]=temp;
        }   

    }
}
int main(){
    int even[8]={5,2,9,4,7,6,1,0};
    int odd[5]={11,33,9,76,43};

    swapalternate(even,8);
    swapalternate(odd,5);

    printarray(even,8);
    printarray(odd,5);

}