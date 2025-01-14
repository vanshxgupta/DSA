#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public:
    int *arr;
    int top;
    int size;

    //behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;

    }

    void push(int element){
        if(size-top>1){//i.e having atleast one empty space 
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
     int peak(){
        if(top>=0 && top<size)
        return arr[top];
        else{
            cout<<"Stack is empty "<<endl;
            return -1;
        }
     }

     bool isempty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
     }
};

int main(){
    
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(64);

    cout<<st.peak()<<endl;
    st.pop();
    cout<<st.peak()<<endl;
    st.pop();
    cout<<st.peak()<<endl;
    st.pop();
    cout<<st.peak()<<endl;

    if(st.isempty()){
        cout<<"Stack is empty"<<endl;
    }
    else{cout<<"Stack is not empty"<<endl;}
    return 0;

}