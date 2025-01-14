#include<iostream>
using namespace std;

int getlength(char name[]){
    int count=0;

    for(int i=0;name[i]!='\0';i++){//loop tabh tak chalega jab tak name mai null character nahi aa jata
        count++;

    }
    return count;

}
int main(){
    char name[20];
    cout<<"enter your name "<<endl;
    cin>>name;

    cout<<"length:"<<getlength(name)<<endl;
    return 0;

}