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


//APPROACH 1- ITERATIVE METHOD-code for reversing a linked list
// Node* reverseLinkedList(Node* &head){

//     if(head==NULL  || head->next==NULL) return head;//Case of single node list or empty LL

//     Node* prev=NULL;
//     Node*curr=head;
//     Node*forward=NULL;
//     while(curr!=NULL){
        
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;//previous wale ko current bbana rahe hai 
//         curr=forward;//current ko forward bana rahe hai 

//     }
//     return prev;

// }




//APPROACH 2- RECURSIVE METHOD

// void reverse(Node* &head,Node*&curr,Node*&prev){
//             //base case
//         if(curr==NULL){
//             head=prev;
//             return;
//         }

//         Node*forward=curr->next;
//         reverse(head,forward,curr);
//         curr->next=prev;
        
// Node *reverseLinkedList(Node *&head) 
// {
        
//         Node*curr=head;
//         Node*prev=NULL;
//         reverse(head,curr,prev);
//         return head;
        
// }

// }





//APPROACH 3-RECURSIVE METHOD

//reverse2 fucntion will give head of the reverse list
Node* reverse2(Node* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //first element ko chodke , agle element ko chota head bola hai 
    Node* chotahead= reverse2(head->next);
    head->next->next=head;
    head->next=NULL;

    return  chotahead;
}
Node *reverseLinkedList(Node *&head) 
{
        
        Node*curr=head;
        Node*prev=NULL;
        reverse2(head);
        return head;
        
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
    print(head);
    

    Node*temp=head;
    head=reverse2(head);
    print(head);
    return 0;
    
}

