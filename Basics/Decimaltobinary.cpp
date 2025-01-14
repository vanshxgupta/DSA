//decimal to binary

//divide the number by 2 and store the remainder , repeat this step till n=0 and then reverse the answer;

#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    float ans=0;
    int i=0;
    while(n!=0){
        int bit = n&1;//n number ke rightmost bit se AND hoga aur 0 ya 1 mai se kuch aayega
        
        ans=(bit*pow(10,i))+ans;//isse reverse aayega number //same number laane ke liye -->ans=(ans*10)+bit;
        n=n>>1;//isse 2 se divide ho jayega 
        i++;
    }
    cout<<"answer is "<<ans<<endl;
}