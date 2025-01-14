//we can initialise the array with any value by using the fill_n command;
#include<iostream>
using namespace std;

int main(){
    int ar[10];
    fill_n(ar,10,2);
    for(int i=0;i<=10;i++){
        cout<<ar[i]<<endl;
    }
}