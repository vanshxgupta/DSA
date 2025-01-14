//recusion-function calls itself

#include<iostream>
using namespace std;

int getfact(int n){
    //base case-->it is mandorty in every recusive function
    if(n==0) return 1;

    //recursive call
    return n*getfact(n-1);

}
int main(){
    int n=6;
    int ans=getfact(n);
    cout<<ans;
}