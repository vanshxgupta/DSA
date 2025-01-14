#include<iostream>
//#include "Hero.cpp" //agar kisi aur class ki file ko dusri kisi file mai kholna hai tooh ye use karo 
using namespace std;

class Hero{

    //properties

     private:
    int bodycount;
    //bodycount ko sirf class ke andr hi access kar skte hai 
    
    //agr ham koi private ko access karna chate hai outside class tooh getter aur setter ka use karo 

    
    public:

    int health;
    char level;

  

    getbodycount(){
        return bodycount;
    }

    setbodycount(int bc){
        bodycount=bc;

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

    //creation of object

    //static allocation
    Hero dholu;
    cout<<"size of dholu is "<<sizeof(dholu)<<endl;//size tooh 9 aani chahiye thi par 12 bata raha hai kyu? becuase complier extra padding daal de raha hai usme 


    
    dholu.health=70;
    dholu.level='A';

    cout<<"health is :"<<dholu.health<<endl;
    cout<<"Level is :"<<dholu.level<<endl;

    
 
    //cout<<"size:"<<sizeof(h1)<<endl;//object ka size utna hota hai jitna class mai uski properties ka size hoga , h1 ka size int ke barabar hoga
 
    cout<<"dholu bodycount is "<<dholu.getbodycount()<<endl;
    //use setter
    dholu.setbodycount(3);
    
    cout<<"dholu bodycount is "<<dholu.getbodycount()<<endl;


    //dynamically ;
    Hero *bholu= new Hero;
    cout<<"level of bholu is "<<bholu->level<<endl;
    (*bholu).sethealth(90);//(*bholu).sethealth(90); and bholu->sethealth(90) is the same thing;

    cout<<"health of bholu is "<<(*bholu).health<<endl;
    cout<<"bodycount iof  bholu "<<(*bholu).getbodycount()<<endl;



}