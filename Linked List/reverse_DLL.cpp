#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node* prev;

    //constructor;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;

    }
};


insertathead(Node*&head,int d){
    Node*newnode=new Node(d);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void print(Node*&head){
    Node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverse(Node*&head){
    if(head==NULL || head->next==NULL){//for single node or empty list 
        return head;
    }

    Node* prev=NULL;
    Node*curr=head;
    Node*forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        curr->prev=forward;
        prev=curr;
        curr=forward;
    }
    return prev;

}

int main(){

	Node*node1=new Node(10);

	Node*head=node1;

	insertathead(head,9);
	insertathead(head,8);
	insertathead(head,7);
	insertathead(head,6);
	insertathead(head,5);
	print(head);

	head=reverse(head);
	print(head);

}
