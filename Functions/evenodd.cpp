#include<iostream>
using namespace std;

//this function will return 1 if it is even 
//return 0 if it is odd

bool iseven(int a){
    if(a&1){
        return 0;//matlab odd
    
    }
    else{
        return 1;//matlab even

    }
}
int main(){
    int num;
    cin>>num;

    if (iseven(num)){
        cout<<"number is even"<<endl;

    }
    else{
        cout<<"number is odd";
    }
    return 0;

}