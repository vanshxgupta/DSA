#include<iostream>
using namespace std;
void print(int arr[],int n,int start=0 ){//agar mai start ko optional rakhna chta hu ,agar uski value input mai mile tooh vo use kar lo nahi tooh jo default mai rkha hai vo use kar lo, tooh ham default ka use krte hai 
    //default krne ke liye righmost wle ko sabse pehle default banana padega ,direct bich ka default nahi kar skte ,  
    for(int i=start;i<n;i++){
        cout<<arr[i]<<endl;

    }
}

int main(){
    int arr[5]={1,4,7,8,9};


}