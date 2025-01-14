#include<iostream>
using namespace std;

//Function overloading 
class A{
    public:
    void sayhello(){
        cout<<"hello vansh "<<endl;

    }
    void sayhello(string name){
        cout<<"hello "<<name <<endl;
    }
    void sayhello(char name){
        cout<<"hello "<<name <<endl;
    }



};

//Operator overloading 

class B {
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;

    }

    void operator+ (B &obj){
        int value1=this->a;
        int value2=obj.a;

        cout<<"output:"<<value2-value1<<endl;//+ operaot ko - mai convert kar diya 


    }

    void operator() (){
        cout<<"main bracket hu "<<this->a <<endl;//ab jaha bhi bracket ayega , mai bracket hu statemnt return hogi 
    }
};

//Runtime polymorphism 

class Animal{
    public:
    void speak(){
        cout<<"Speaking "<<endl;

    }
};

class Dog : public Animal{

    public:
    void speak(){
        cout<<"Barking "<<endl;
    }
};

int main(){

    A obj; 
    obj.sayhello();
    

    B obj1,obj2;
    obj1.a=4;
    obj2.a=7;
    obj1+obj2;

    obj1();


    Dog obje;

    obje.speak();
}