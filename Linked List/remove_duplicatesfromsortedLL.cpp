//Remove duplicates from a sorted Doubly Linked List
#include<iostream>
using namespace std;
class Node {
public:
     int data;
     Node *prev;
     Node *next;

     //constructor
     Node(int data) {
        this->data = data;
           this->prev = NULL;
          this->next = NULL;
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

Node * removeDuplicates(Node *head)
{
    //if empty list
    if(head==NULL){
        return head;

    }

    //if non empty list
    Node*curr=head;
    while(curr!=NULL){
        if( curr->next!=NULL && curr->data==curr->next->data){
            Node*next_next=curr->next->next;
            Node*nodetodelete=curr->next;
            delete(nodetodelete);
            curr->next=next_next;
        }

        else{//not equal
            curr=curr->next;
        }

    }
    return head;
}

int main(){
    Node*node1=new Node(10);

	Node*head=node1;

	insertathead(head,9);
	insertathead(head,8);
	insertathead(head,6);
	insertathead(head,6);
	insertathead(head,5);
	print(head);

    head=removeDuplicates(head);
    print(head);


}