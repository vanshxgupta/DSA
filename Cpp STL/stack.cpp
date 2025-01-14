#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> z;
    z.push(1);
    z.push(2);
    cout<<"top element "<<z.top()<<endl;

    
    stack<string> s;

    s.push("vansh");
    s.push("x");
    s.push("gupta");
    for(int i=0;i<s.size();i++){//printing of stack
        cout<<s.top()<<" ";
        s.pop();



    }
    cout<<endl;

    cout<<"top element "<<s.top()<<endl;

    s.pop();
    cout<<"top element "<<s.top()<<endl;
    cout<<"size of stack"<<s.size()<<endl;
    cout<<"empty or not "<<s.empty()<<endl;
}