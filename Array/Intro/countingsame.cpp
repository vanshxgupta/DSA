#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter o. of elements"<<endl;
    cin>>n;
    cout<<"enter elements:\n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cout<<"repeating element is "<<arr[j]<<" "<<endl;
                
            }
        }
    }
}
