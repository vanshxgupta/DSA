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

bool iscircularlist(Node*head){
    //empty list
    if(head==NULL){
        return true;

    }
    
    Node*temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    
    if(temp==head){
        return true;
    }

    return false;

}

//Approah 2: through visited or not visited

// bool isCircular(Node* head){
   
//     if(head==NULL) return true;
//         int A[1000001] = { 0 };//Create a visited set to store visited nodes
//     Node *temp = head;
//     bool check = true;
//     int first = head->data;
//     while(true){
//         int val = temp->data;
//         if(temp->next == NULL) return false;
//         if(A[val]==true){//if that visited true the it is clear that the linked list is circular 
//             if (val==first)//this condition is to check for loop inside LL
//                 return true;
//             else 
//             return false;
//         }
//         A[val] = true;
//         temp = temp->next;
//     }
// }


void print(Node* &tail){
    Node* temp= tail;

    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    }while(tail!=temp);
    cout<<endl;

}

int main(){

    Node* tail=NULL;

    //empty list me insert krre hai 
    insertnode(tail,5,3);
    insertnode(tail,3,5);
    insertnode(tail,5,7);
    insertnode(tail,7,9);
   
    print(tail);

    if(iscircularlist(tail)){
        cout<<"Linked list is circular  "<<endl;
    }
    else{
        cout<<"Linked list is not circular "<<endl;
    }
}