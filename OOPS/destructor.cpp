#include<iostream>
#include<string.h>
using namespace std;

class Hero{

    private:
    int bodycount;


    public:

    char *name;
    int health;
    char level;
    static int timetocomplete;

        Hero(){
        cout<<"Simple constructor called"<<endl;
        name=new char[100];

    }
   
    Hero(int health, char level){
        this->level=level;
        this->health=health;

    }



    //Parameterised constructor
    Hero(int bodycount){

        cout<<"this->"<<this<<endl;
        this->bodycount=bodycount;//use of this keyword
    }


    void print(){
        cout<<endl;
        cout<<"Name "<<this->name<<" ";
        cout<<"health "<<this->health<<endl;
        cout<<"level "<<this->level<<endl;
        cout<<endl;   
    }


        //Copy constructor
    Hero(Hero &temp){
        this->health=temp.health;
        this->level=temp.level;

    }

    void setname(char name[]){
        strcpy(this->name,name);
    }

    //Destructor
    ~Hero(){
        cout<<"Destructor bhai called"<<endl;
    }
    
};

int main(){

    //static
    Hero a;

    //dynamic
    Hero *b=new Hero();
    //manually destructor call
    delete b;


}
