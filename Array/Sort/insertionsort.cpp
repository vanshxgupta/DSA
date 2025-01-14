//insertion sort-
//..isme cards ki tarhe ek  ke baad ek element khulta hai 
//insertion sort mai sort nahi kr rahe hai shift kar rahe hai;

#include<iostream>
using namespace std;

void insertionSort(int n,int arr[]){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j;
        for(j=i-1;j<=0;j--){//ith element ko pakad ke usko piche wale 
        //ek ek elment se compare krre hai isliye loop i-1 se 0 tak chalaya hai

            if(arr[j]>temp){//abhi sort stable hai ;

                            //agar arr[j]>=temp likhte tooh sort unstable ho jata ;
                            

                //shift kardo
                arr[j+1]=arr[j];

            }
            else{
                //ruk jao
                break;
            }
            



        }
        arr[j+1]=temp;//  jab ek ek element se piche ja jaake compare krte hai tooh koi
        // ek esa element aata hai jiske aage hamko apna element rakhna hai tooh j ki value 
        //se ek jyda rakhna padega isliye esa kiya 
    }
}

int main(){
    int arr[5]={2,6,4,9,7};
    
    insertionSort(5,arr);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";

    }

}