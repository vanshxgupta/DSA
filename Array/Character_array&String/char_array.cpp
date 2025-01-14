#include<iostream>
using namespace std;

int main(){
    char  name[20];
    cout<<"enter your name "<<endl;
    cin>>name;
    
    
    //character array input lelo
    //cin execution stop kar deta hai jab bhi apn (space, tab ,enter ) maar dete hai ;

    //null character is '\0' whose ascii value is 0;

    //jab bhi ham koi character array store krte hai tooh character ke end ke baad ek null character aa jata hai , 
    //null character is used as a terminator jisse ye pata chlta hai ki character array kaha end ho raha hai ;

    name[2]='\0';//ab hamne kya kiya ke name ke 2nd index pe null charcter daal diya 
    //tooh name sirf 0 aur 1 index pe chalega fir null charcter ko dekhke terminate ho jayega
    

    cout<<"your name is ";
    cout<<name<<endl;
   



    return 0;

}