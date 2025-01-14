//pointer - store address

#include<iostream>
using namespace std;

int main(){
    int num=5;
    cout<<num<<endl;

    cout<<"address of num is "<</* address operator */&num<<endl;

    int *ptr=&num;

    cout<<"Address is :"<<ptr<<endl;//iska matlab ptr wle dabbe ka adress bata do
    cout<<"value is :"<<*ptr<<endl;//iska matlab ptr wale badde mai jo value hai uska address bata do;

    double d=4.3;
    double *p2=&d;
    cout<<"Address is :"<<p2<<endl;//iska matlab ptr wle dabbe ka adress bata do
    cout<<"value is :"<<*p2<<endl;//iska matlab ptr wale badde mai jo value hai uska address bata do;

    //sizes;

    cout<<"size of integer is "<<sizeof(num)<<endl;//bit ki form mai deta hai sizeof function size

    cout<<"size of pointer is "<<sizeof(ptr)<<endl;

    cout<<"size of double is "<<sizeof(d)<<endl;
    cout<<"size of pointer is "<<sizeof(p2)<<endl;//pointer address store krta hai tooh uski size same hi hoi bhale hi data type alag ho 
    //size of pointer 4 hogi ya 8 depending on complier 


} 

