#include<iostream>
using namespace std;

void reverse(string &str,int i){
    //base case
    int j=str.size()-i-1;
    if(i>j) return ;

    swap(str[i],str[j]);
    i++;

    

    //recursive call
    reverse(str,i);
}

int main(){
    string name="Vansh";
    reverse(name,0);
    cout<<name<<endl;
}