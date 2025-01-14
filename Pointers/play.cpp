#include<iostream>
using namespace std;

int main(){

    // int *p=0;//pointer create kara aur usme null value daali tooh segmentation fault aata hai 
    // cout<<*p<<endl;

    int i=5;
    int *z=&i;
    cout<<z<<endl;
    cout<<*z<<endl;

    int *q=0;//ye aur  upar vali chiz same hai 
    q=&i;
    cout<<q<<endl;
    cout<<*q<<endl;


}