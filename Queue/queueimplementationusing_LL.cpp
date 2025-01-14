#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;


    //constructor
    node(int val){
        data=val;
        next=NULL;

    }
};

class queue{
    public:
    node*front;
    node*rear;


    //constructor
    queue(){    
        front=NULL;
        rear=NULL;

    }

    void push(int data){
        node*n= new node(data);

        //if queue is empty , and we are pushing first element
        if(front==NULL){
            rear=n;
            front=n;
            return ;
        }

        rear->next=n;
        rear=n;
    }

    void pop(){

        //if queue is empty
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return ;
        }

        node*current=front;
        front=front->next;

        delete current;


    }

    int getfront(){

        //checking if empty?
        if(front==NULL){
            cout<<"empty queue"<<endl;
            return -1;

        }

        return front->data;
    }

    bool empty(){

        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.getfront()<<endl;
    q.pop();
    cout<<q.getfront()<<endl;
    q.pop();
    cout<<q.getfront()<<endl;qu
    q.pop();
    cout<<q.getfront()<<endl;
    q.pop();
    
    cout<<q.empty()<<endl;


    return 0;
}