#include<iostream>
#include<string.h>

using namespace std;

class Hero{

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

    //copy constructor
    Hero(Hero& temp){//temp mai hero1 ayega
        char *ch=new char[strlen(temp.name)+1];//hero1 ke name ki length 

        strcpy(ch,temp.name);
        this->name=ch;//name hero1 ka copy karo in hero2 name 

        cout<<"Copy constructor called"<<endl;
        this->health =temp.health;
        this->level=temp.level;

    }



    void print(){
        cout<<endl;
        cout<<"Name :"<<this->name<<", ";
        cout<<"health :"<<this->health<<", ";
        cout<<"level :"<<this->level<<endl;
        cout<<endl;   
    }

    void setname(char name[]){
        this->name=name;
    }

    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }
    
    void sethealth(int h){
        health=h;

    }

    void setlevel(char ch){
        level=ch;
    }


    
};


int main(){


    Hero hero1;
    hero1.sethealth(12);
    hero1.setlevel('D');
    char name[6]="vansh";
    hero1.setname(name);
    hero1.print();

    //use of new copy constructor// deep copy constructor
    Hero hero2(hero1);
    hero2.print();

    //Hero hero2=hero1;

    hero1.name[0]='G';
    hero1.print();

    hero2.print();

    //in deep copy constructor , hum entirely ek dusra array bana lete hai aur usko send kar dete hai hero2 mai tooh hero1 i values usme chali jaati hai,
    // par jab hum hero1 mai change karenge  tooh vo changes hero 2 mai reflect nhi honge kyunki dono ka address alg alg hai , unlikely shallow  copy wala case

    
    //Copy assignment operator;

    hero1.health=50;

    hero1.print();
    hero2.print();


    hero1.name=hero2.name;//hero1 aur hero2 ka name same ho jayega
    hero1.print();
    hero2.print();

    hero1=hero2;//herro1 aur hero 2 ki saari prop same ho jayegi 
    hero1.print();
    hero2.print();

 
}