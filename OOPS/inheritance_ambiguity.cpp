#include<iostream>
using namespace std;

class A {
    public:

    void func(){
        cout<<"i am A "<<endl;
    }
};

class B{

    public:

    void func(){
        cout<<"i am B "<<endl;
    }

};

class C:public A,public B{

};
int main(){

    C obj;

    obj.A::func();

    obj.B::func();
   // obj.func();will give an error 


}