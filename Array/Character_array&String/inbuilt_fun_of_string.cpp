#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    char ch[30];
    cout<<"enter text";

    cin.getline(ch,30,'z');//ch is the name of string , 
    //30 is the upper bound length of string and z is the
    /// terminating character of string (z is costume delimiter) matlab ab sirf 
    ///enter se output nahi ayega z likhke enter dabaane par output ayega
    cout<<ch<<endl;

    //length of an character array;
    //int len=strlen(ch);
    int len=strlen(ch);
    cout<<"len of string is:"<<len<<endl;

    
    //compare two strings
    //strcmp(s1,s2);-->//gives not equal to 0 when strings are not equal 
                    //gives equal to 0 when strings are equal 
    char s1[10];
    cin>>s1;
    char s2[12];
    cin>>s2;
    cout<<strcmp(s1,s2)<<endl;
    



    
    char s3[20];


    
    //copy string
    //strcpy(destination wali string, source string);
    strcpy(s3,s2);
    cout<<s3;
}