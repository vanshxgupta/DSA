#include<iostream>
using namespace std;


class A{
    public:
    void func1(){
        cout<<"Func 1"<<endl;

    }
};

class B:public A{

    public:
    void func2(){
        cout<<"inside function 2"<<endl;


    }


};

class C:public A{
    public:
    void func3(){
        cout<<"inside func 3"<<endl;

    }
};
int main(){
     A obj1;
     obj1.func1();

     B obj2;
     obj2.func1();
     obj2.func2();

     C object3;
     object3.func1(); 
     object3.func3();

     return 0;

}