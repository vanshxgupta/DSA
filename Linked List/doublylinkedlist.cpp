#include<iostream>
using namespace std;

class Node{
    public:
    int data;//data jo node mai store krna hai 
    Node* prev;//previous element ka address 
    Node*next;//next wale ka adddres

    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value=this->data;

        //Memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data ";
    }

};

//traversinng a linked list
void print(Node*head){
    Node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}


//gives length of Linked list
int  getlength(Node * head){
    int len=0;
    Node* temp=head;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertathead(Node* &head,Node* &tail,int d){

    //empty list initally
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;

    }

    else{
    //creating a new node;
    Node*temp=new Node(d);

    temp->next=head;
    head->prev=temp;
    head=temp;}
}

void insertattail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;

    }
    else{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }

}

void insertatposition(Node* &tail,Node* &head,int position,int d){
    
    //insert at start
    if(position==1){
        insertathead(head,tail,d);
        return ;
    }

    Node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    //inserting at last postion
    if(temp->next==NULL){
        insertattail(tail,head,d);
        return;
    }

    //creating a node for d
    Node*nodetoinsert=new Node(d);

    nodetoinsert->next= temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}

//Deleting a node in a doubly linked list 
void deletenode(int position,Node* &head,Node* &tail){

    //deleting from first position
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;//delete krne ke liye khud ka destructor likhna padega(na likho fir bhi default desturctor se kaam chk raha hai) ,jo ki upar likha hai
        
    }

    else{
        //delteing any middle node or last node
        Node*curr=head;
        Node*prev=NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;;
            curr=curr->next;
            cnt++;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        curr -> next -> prev = prev;
        
        delete curr ;
        if(curr->next==NULL){
           tail=prev;
        }
        

    }


}

int main(){
    Node* node1= new Node(10);

    //without intial node statement will be 
    //Node*head=NULL;
    //Node*tail=NULL;
    Node* head= node1;
    Node*tail=node1;

    print(head);

    cout<<"now length is "<<getlength(head)<<endl;

    insertathead(head,tail,11);
    print(head);
    insertathead(head,tail,13);
    print(head);
    insertathead(head,tail,8);
    print(head);


    insertattail(tail,head,20);
    print(head);
    insertattail(tail,head,30);
    print(head);

    cout<<"now length is "<<getlength(head)<<endl;

    insertatposition(tail,head,2,100);
    print(head);

    insertatposition(tail,head,1,101);
    print(head);
    insertatposition(tail,head,8,102);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    deletenode(1,head,tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deletenode(8,head,tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}