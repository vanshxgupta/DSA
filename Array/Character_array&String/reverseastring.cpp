#include<iostream>
using namespace std;
void reverse(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }
}

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

    int len=getlength(name);
    reverse(name,len);

    cout<<"reversed name is "<<endl;
    cout<<name<<endl;
    return 0;

}

