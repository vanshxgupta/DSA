#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;

    }

    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;

        }
        cout<<"memory is free for node with data:("<<value<<")"<<endl;
        
    }
};

void insertnode(Node* &tail,int element,int d){
    //assuming the element is present in the list 
    
    if(tail==NULL)//EMPTY LIST
    {
        Node* newnode= new Node(d);
        tail=newnode;
        newnode->next=newnode;
    }

    else{
        //non-empty list
        //assuming that the element is present in the list 

        Node*curr=tail;

        while(curr->data != element){
            curr=curr->next;

        }

        //element found->curr is representing element wala node
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}

void print(Node* &tail){
    Node* temp= tail;

    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    }while(tail!=temp);
    cout<<endl;

}

void deletenode(Node* &tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"List is empty , please check again"<<endl;
        return ;

    }
    else{
        //non empty 

        //assuming that " value " is present in the linked list 
        Node*prev=tail;
        Node*curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;

        }
        prev->next=curr->next;

        //1 Node Linked list 
        if(curr==prev){
            tail=NULL;
        }

        //>=2 Node linked list 
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }

}

int main(){

    Node* tail=NULL;

    //empty list me insert krre hai 
    insertnode(tail,5,3);
    print(tail);

    insertnode(tail,3,5);
    print(tail);
    insertnode(tail,5,7);
    print(tail);
    insertnode(tail,7,9);
    print(tail);
    insertnode(tail,3,12);
    print(tail);


    deletenode(tail,9);
    print(tail);
    deletenode(tail,3);
    print(tail);
    deletenode(tail,12);
    print(tail);





}