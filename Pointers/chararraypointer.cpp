#include<iostream>
using namespace std;
int main(){

    int arr[5]={1,2,3,4,5};
    char ch[6]="abcde";// char ch[6]={'a','b','c','d','e'};both are the one and the same thing'

    cout<<sizeof("abcd")<<endl;//Note:iski size 5 hai as shyd last wle ko null character maante hai

    cout<<arr<<endl;//ye tooh address bata raha hai 
    cout<<ch<<endl;//ye tooh content print kar raha hai pura

    //cout function  is differently implemented in case of char arry and int arry

    char *c=&ch[0];
    //prints entire string
    cout<<c<<endl;

    char temp='z';
    char *p=&temp;
    cout<<p<<endl;// 8 wali location pe gaya 8 print ho gaya ,then vo uske aage wali locatio pe jayega vo print karega , ese chlta rahega tabh tak jab tak koi null character na aa jaye 

    char chr[6]="xyzab";//isme xyzab ek temprory memory bani hai aur ch memory mai usko copy kar diya hai 
    char *chs="pqrst";//risky-->ye nahi krna hai --> isme temporay memory mai pqrst store hai usse hamne ek pointer ko fist element se point kara diya
    
    return 0;

}