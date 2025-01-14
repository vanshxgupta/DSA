#include<iostream>
#include<vector>
using namespace std;

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];

    }
}
vector<int> count(int arr[],int size){
    
    vector<int> final;


    for(int i=0;i<size;i++){
        int count =0;
        for(int a=1;a<size;a++){
            if(arr[i]==arr[a]){
                count++;


            }
            
            
            
            


        
        
            

        }
        final.push_back(count);

    }
    
}
int main(){
    int arr[5]={2,2,3,1,2};
    count(arr,5);
    printarray(arr,5);
    

}