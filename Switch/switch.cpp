#include<iostream>
using namespace std;
int main(){
    int num=1;
    char ch='1';
    switch(num){
        case 1: cout<<"first "<<endl;
                break;
        case 2 : cout<<"second "<<endl;
                
        case '1': cout<<"character"<<endl;
                break;
        default: cout<<"it is default case "<<endl;

    }

}
