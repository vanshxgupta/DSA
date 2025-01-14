#include<iostream>
using namespace std;
int main(){
    int i=5;
    int*p=&i;
    int **p2=&p;
    
    cout<<"printing p "<<p<<endl;
    cout<<*p2<<endl;

    cout<<"address of p "<<&p<<endl;

    cout<<i<<endl<<endl;
    cout<<*p<<endl<<endl;//teeno same
    cout<<**p2<<endl<<endl;

    
    cout<<&i<<endl<<endl;
    cout<<p<<endl<<endl;//teeno same
    cout<<*p2<<endl<<endl;



    cout<<&p<<endl<<endl;
    cout<<p2<<endl<<endl;




}