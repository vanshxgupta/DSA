#include<iostream>
using namespace std;


class Animal{

    public:
    int age;
    int weight;

    public:
    void bark(){
        cout<<"bau bau bau "<<endl;

    }


};

class Human{
    public:
    string color;


    public:
    void  speak(){
        cout<<"Manjil ko bhula kar jiya tooh kya jiya "<<endl;
    }

};

//Multiple inheritance
class Hybrid:public Animal, public Human{

};

int main(){
    Hybrid h;

    h.speak();
    h.bark();
    cout<<h.age<<endl;
    
}