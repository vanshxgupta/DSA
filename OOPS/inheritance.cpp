#include<iostream>
using namespace std;

class Human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getage(){
        return this->age;

    }

    void setweight(int w){
        this->weight=w;

    }


};

class Male: public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};

int main(){
    Male object1;
    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    cout<<object1.height<<endl;

    cout<<object1.color<<endl;
    object1.setweight(84);
    object1.sleep();
    cout<<object1.weight<<endl;

    return 0;

}