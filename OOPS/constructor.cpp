#include<iostream>
using namespace std;

class Hero{

    private:
    int bodycount;


    public:

    char *name;
    int health;
    char level;
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
    
};


int main(){


    Hero hero1;
    hero1.sethealth(12);
    hero1.setlevel('D');
    char name[5]="vansh";
    hero1.setname(name);
    hero1.print();

    Hero hero2(hero1);
    hero2.print();

    

    cout<<"dholu"<<endl;
    Hero dholu;


    Hero ramesh(10);
    ramesh.print();

    cout<<"Address of dholu is"<<&ramesh<<endl;


    cout<<"bholu"<<endl;
    Hero *bholu= new Hero;

    Hero temp(22,'B');//Parametrised constuctor called
    temp.print();

    Hero suresh(70,'c');
    suresh.print();


    //Copy constructer
    Hero ritesh(suresh);//this will create a copoy , which contains same health and level as of suresh;
    ritesh.print();

}