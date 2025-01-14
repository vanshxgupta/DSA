#include<iostream>
using namespace std;
int main(){
    int num=5;
    int *p=&num;
    int a=*p;
    cout<<"before "<<num<<endl;
    cout<<p<<endl;
    a++;
    cout<<"after "<<num<<endl;
    
    int num2=55;

    int *q=&num2;
    cout<<"before "<<num2<<endl;
    (*q)++;
    cout<<"after "<<num2<<endl;

    //copying a pointer

    int *z=q;//z ek aur dabbe ban gaya jisme q ka address hoga
    cout<<q<<" - "<<z<<endl;//ab q aur z print karyenge tooh us dabbe ka adress print ho jayega
    cout<<*q<<" - "<<*z<<endl;//inko print karane se *q aur *z jis value ko point kar raha hai vo print ho jayega 

    //important concept
    int i=3;
    int *t=&i;
    cout<<(*t)++<<endl;
    cout<<t<<endl;
    t=t+2;//interger 4 byte ka hota hai tooh t mai +1 krenge tooh address mai 4 se badh jayega 
    cout<<t<<endl;
    cout<<*t<<endl;



}