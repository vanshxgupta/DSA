#include<iostream>
using namespace std;


class Animal{

    public:
    int age;
    int weight;

    public:
    void speakk(){
        cout<<"Speaakking "<<endl;

    }


};

class Dog :public Animal{

};
int main(){
    Dog d;

    d.speakk();
    cout<<d.age<<endl;
    return 0;

}