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

    void print(){
        cout<<endl;
        cout<<"Name :"<<this->name<<", ";
        cout<<"health :"<<this->health<<", ";
        cout<<"level :"<<this->level<<endl;
        cout<<endl;   
    }

    void setname(char name[]){
        strcpy(this->name,name);
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

    //use default copy constructor// default copy constructor shallow copy krta hai 
    Hero hero2(hero1);
    hero2.print();

    //Hero hero2=hero1;

    hero1.name[0]='G';
    hero1.print();

    hero2.print();

    //shallow copy mai hero1 mai name krne par , hero2 mai bhi change ho gya !! kyunki hero1 aur hero2 dono same memory location ko point kar rahe hai


   


}