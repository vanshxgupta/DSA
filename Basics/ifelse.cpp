#include<iostream>
using namespace std;
int main(){
    char ch ;
    cout<<"enter the cahracter: "<<endl;
    ch=cin.get();
    if(ch>65&&ch<90){
        cout<<"uppercase\n";

    }
    else if (ch>97 && ch<122){
        cout<<"lowercase\n";

    }
    else if(ch<57 &&ch>48){
        cout<<"digit\n";
    }
    else{
        cout<<"other";

    }
}