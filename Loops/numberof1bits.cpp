//write a function that takes an unsigned integer and returns the number 
//of 1 bits it has (alsp known as the hamming weight ).
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count =0;
    while(n!=0){
        if(n&1){
            count++;

        }
        n=n>>1;

    }cout<<count;

    } 