#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;

    }

    //destructor

};

void Insertathead(Node* &head, int d){//as a reference head ko isliye liya hai kynki hamne ussi linked list mai changes chahiye nayi copy nahi banani hai 

    //new node create
    Node* temp=new Node(d);
    
    temp-> next=head;
    head=temp;

}
void insertattail(Node*&tail,int d){
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
}

void insertatposition(Node*&head,Node*&tail,int position, int d){

    if(position==1){
        insertathead(head,d);
        return ;
    }

    if(len==position-1){
        insertattail(tail,d);
        return;
    }
    Node*temp= head;

    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;

    }

    //creating a node for d
    Node*nodetoinsert=new Node(d);

    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

  
}
void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
     
}

int main(){
    Node*node1=new Node(10);

    Node*head=node1;
    Node*tail=node1;
    cout<<node1->data<<endl;
    print(node1);
    Insertathead(node1,20);
    print(node1);

    insertattail(node1,30);
    print(node1);

    insertatposition(head,tail,4,22);
    print(node1);
}


