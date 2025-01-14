#include<iostream>
using namespace std;

/*
PASS BY VALUE
void update(int n){
    n++;

}
int main(){
    int n=5;//isme dono n alg alg memory location ko darsha rhe hai 
    cout<<"Before "<<n<<endl;
    update(n);
    cout<<"After "<<n<<endl;




    return 0;
}
*/

//PASS BY REFERNCE

void update2(int &n){//it is called as refernce variable
    n++;

}
int main(){
    int n=5;//isme koi naya memory ka dabba nahi bana hai ,dono n same memory ko point kar rhe hai 
    cout<<"Before "<<n<<endl;
    update2(n);
    cout<<"After "<<n<<endl;

    return 0;
}


