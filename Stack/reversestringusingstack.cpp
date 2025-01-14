#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str="vansh";

    stack<char> s;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        s.push(ch);//string se leke har ek element ko stack mai dala 

    }

    string ans="";

    while(!s.empty()){
        char ch=s.top();
        ans.push_back(ch);//top wala element baar baar lenge aur ans wale array mai print karayenge
        s.pop();//top wale ko fir pop kar denge
    }
    
    cout<<"answer is :"<<ans<<endl;
    return 0;
}