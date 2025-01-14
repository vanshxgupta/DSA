#include<iostream>
using namespace std;

int score=15;//global variable
//global variabe-->isko use mat karo , this is a bad pratice
void a(int& i){
    cout<<score<<"in a"<<endl;
    score++;//ye global variable change ho gya hai , ab ye change har jghe reflect hoga
    
    char ch='a';//ch is local varible , sirf issi fun tk simit hai
    cout<<i<<endl;
    
}

void b(int &i){
    cout<<score<<"in b"<<endl;
    cout<<i<<endl;

}



int main(){
    int i=5;
    a(i);
    b(i);

}