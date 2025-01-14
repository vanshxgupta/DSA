#include <bits/stdc++.h> 
#include<Stack>
using namespace std;

void solve(stack<int>&myStack,int x){
    if(myStack.empty()){
       myStack.push(x);
        return ;
    }

    int num=myStack.top();//top wale element ko side mai rakhlo
    myStack.pop();

    //fir recursive call chala lo
    solve(myStack,x);

    myStack.push(num);//jin jin ko nikala tha unko vapis daal do ek ek krke

}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{   

    solve(myStack,x);
    return myStack;
}

int main(){
    stack<int> s;

    s.push(2);
    cout<<s.top();
    s.push(3);
    cout<<s.top();
    s.push(4);
    cout<<s.top();

    pushAtBottom(s,9);
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top();

}