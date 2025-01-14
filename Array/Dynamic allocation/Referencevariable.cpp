#include<iostream>
using namespace std;

int &fun(int a){
    int num=a;
    int& ans=num;
    return ans;
}//upar wala code is a bad pratice ,because ye num, ans vagera saare local variable hai 
//aur inka koi existence nahi hai iske bahar, agar isko call krenge main mai tooh 
//warning generate hogi 

void update2(int &n){//pass by refernce 
    n++;
}

int main(){
    int i=5;

    //create a ref variable
    int &j=i;
    //ab j bhi i ka hai memory locationi.e i ka hi dabba hai , bas dono ka naam alg alg hai 

    cout<<i<<endl;
    i++;

    cout<<i<<endl;
    j++;

    cout<<i<<endl;
    cout<<j<<endl;
    
    //i ya j kisi mai bhi changes karo uss dbbe mai change ho jayega 
    
    
    fun(i);

    return 0;

}