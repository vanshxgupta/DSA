#include<iostream>
using namespace std;


class A{
    public:
    void funa(){
        cout<<"fun_a"<<endl;

    }


};

class D{
    public:
    void fund(){
        cout<<"fun_d"<<endl;

    }
};

class B:public D,public A{


};

class E:public D{

};



int main(){

    A object1;

    object1.funa();
    

    B object2;
    object2.funa();
    object2.fund();

    E object3;
    
    object3.fund();

    return 0;


}