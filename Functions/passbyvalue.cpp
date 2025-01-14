#include<iostream>
using namespace std;
void dummy(int n){
    n++;
    cout<<"n is "<<n<<endl;
//n idhar tooh badh gaya hai 
// par ek copy ban chuki hogi n++ 
// karne se pehle tooh jo ham value 
// n ko denge vahi  call pe ayega
}
int main(){
    int n;
    cin>>n;
    dummy(n);
    cout<<"number n is "<<n<<endl;
    return 0;

    
}
