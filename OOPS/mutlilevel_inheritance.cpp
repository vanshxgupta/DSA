#include<iostream>
using namespace std;


class Animal{

    public:
    int age;
    int weight;

    public:
    void speakk(){
        cout<<"bau bau bau "<<endl;

    }


};

class Dog :public Animal{

};

class Germanshepherd: public Dog{

};
int main(){
    Dog d;
    Germanshepherd g;


    d.speakk();
    cout<<d.age<<endl;

    g.speakk();

    return 0;

}