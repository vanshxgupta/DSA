#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertattail(Node* &tail,int d){
    //new node create
    Node*temp=new Node(d);
    tail->next=temp;
    tail=tail->next;

}

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
     
}
 int getlen(Node*&head){
     Node*temp=head;
     int cnt=0;
     while(temp!=NULL){
         temp=temp->next;
         cnt++;

     }
     return cnt;
 }

Node*kReverse(Node* head,int k){
    //base call
    if(head==NULL){
        return NULL;

    }

    //step1:reverse first k nodes

    Node*forward=NULL;
    Node*curr=head;
    Node*prev=NULL;
    int cnt=0;
    while(curr!=NULL && cnt<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;

    }

    
    //step2:recursion sambhal lega
    if(forward!=NULL ){
        
        if(getlen(forward)>=k){
            head->next = kReverse(forward, k);

        }
        else{
            head->next=forward;
        }
        
    }

    //step3:return head of reversed list 
    return prev;
}
int main(){
    Node* node1=new Node(10);

    //head pointed to node1
    Node *head=node1;
    //tail creation
    Node*tail=node1;

    insertattail(tail,20);
    insertattail(tail,30);
    insertattail(tail,40);
    insertattail(tail,50);
    print(head);
    
    head=kReverse(head,3);
    print(head);

}