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

    static int random(){
        return timetocomplete;
    }
};

//intialise static keyword 
int Hero :: timetocomplete=5;

int main(){
        cout<<Hero::timetocomplete<<endl;//bina object banaye bhi access kar skte  hai isko
        

}
