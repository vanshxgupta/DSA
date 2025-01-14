#include<iostream>
#include<math.h>
using namespace std;

bool isarmstrong(int n,int len){
    int realn=n;
    int cubesum=0;
    while(n!=0){
        int digit=n%10;
        int cube=pow(digit,len);
        cubesum=cube+cubesum;
        n=n/10;
    }


    if(cubesum==realn){
        return true;
    }
    else{
        return false;
    }
    
}
int main(){
    cout<<"enter a number ";
    int n;
    cin>>n;

    cout<<"enter number of digits in it"; 
    int len;
    cin>>len;

    if(isarmstrong(n,len)){
        cout<<"yes it is armstrong ";
    }
    else{
        cout<<"no it is not armstrong";
    }
}