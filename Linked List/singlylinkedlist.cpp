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


    //destructor
    ~Node(){

        int value=this->data;

        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;

        }
        cout<<"memory is free for node with data ";
    }
};


void Insertathead(Node* &head, int d){//as a reference head ko isliye liya hai kynki hamne ussi linked list mai changes chahiye nayi copy nahi banani hai 

    //new node create
    Node* temp=new Node(d);
    
    temp-> next=head;
    head=temp;

}

void insertattail(Node* &tail,int d){
    //new node create
    Node*temp=new Node(d);
    tail->next=temp;
    tail=tail->next;

}

void insertatposition(Node* &tail,Node * &head,int position ,int d){

    if(position==1){
        Insertathead(head,d);
        return ;
    }
    
    Node* temp=head;

    int cnt=1;
    while(cnt<(position-1)){
        temp=temp->next;
        cnt++;

    }

    //inserting at last position 
    if(temp->next==NULL){
        insertattail(tail,d);
        cnt;
    }
    cout<<endl;

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


void deletenode(int position, Node* &head,Node* &tail){
    
    //deleting 1st(start) node 
    if(position==1){
        Node* temp=head;
        head=head->next;
        //memmory free start node
        temp->next=NULL;
        delete temp;

    }
    else{
        //deleting any middle node or last node
        Node* current=head;
        Node* prev=NULL;

        int cnt =1;
        while(cnt<position){
            prev=current;
            current=current->next;
            cnt++;
        }

        if(current!=NULL){
        prev->next=current->next;
        

        //last  node ko delete karne par tail ki position maintain krne ke liye
        if(current->next==NULL){//matlab agar last position hai tooh
           tail=prev;
        }
        
        delete current;//delete karne ke liye khud ka destructor likhna padega(na likho fir bhi default desturctor se kaam chl raha hai ) , jo ki pura likha hai
        }
        
        

    }
}

int main(){
    Node* node1=new Node(10);
    cout<<node1->data<<endl;//again for revision : node1->data is  same as (*node1).data

    cout<<node1->next<<endl;

    //head pointed to node1
    Node *head=node1;
    //tail creation
    Node*tail=node1;
    print(head);

    Insertathead(head,12);
    print(head);

    Insertathead(head,15);
    print(head);

    insertattail(tail,20);
    print(head);
    
    Insertathead(head,30);
    print(head);

    insertattail(tail,80);
    print(head);

    insertatposition(tail,head,3,22);
    print(head);


    insertatposition(tail,head,1,40);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deletenode(8,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    


    return 0;

}