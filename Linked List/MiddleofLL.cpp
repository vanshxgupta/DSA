#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Node{
    public:
    int data;//us node mai value 
    Node* next;//next node  pointer 


    //constructor 
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

int getlength(Node*head){

    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;

    }
    return len;
}




//Regular soltuion
// Node*findMiddle(Node*&head){
//     int len=getlength(head);
//     int ans=(len/2);

//     Node*temp=head;
//     int cnt=0;
//     while(cnt<ans){
//         temp=temp->next;
//         cnt++;
//     }
//     return temp;

// }



//Optimised solution
Node* findMiddle(Node*head){
    if(head==NULL || head->next== NULL){//in case of 0 or 1 node
        return head;
    }

    //2 nodes
    if(head->next->next==NULL){
        return head->next;
    }

    Node*slow=head;
    Node*fast=head->next;
    //fast ko 2 se aage badhayenge 
    //slow ko ek se aage badhayenge
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;

        }
        slow=slow->next;
    }
}
void printmiddle(Node*&head){
    Node*temp=head;
    cout<<temp->data<<endl;
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
    insertattail(tail,60);
    print(head);
    
    Node*temp=head;
    head=findMiddle(head);
    printmiddle(head);

}
