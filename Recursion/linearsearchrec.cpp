#include<iostream>
using namespace std;

bool linearsearch(int arr[],int n,int key){
    
    if(n==0) return false;
    if(arr[0]==key){
        return true;

    }

    else{
        bool remainingpart=linearsearch(arr+1,n-1,key);
        return remainingpart;
    }

}

int main(){
    cout<<"size of array"<<endl;
    int n;
    cin>>n;
  
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"key"<<endl;
    int key;
    cin>>key;
    
    int ans=linearsearch(arr,n,key);
    if(ans){
        cout<<"present";
    }
    else{
        cout<<"absent";
    }


}
