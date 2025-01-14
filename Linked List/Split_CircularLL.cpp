#include <bits/stdc++.h> 
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

void splitCircularList(Node *head)
{   

    //finding middle of the CLL
    Node*slow=head;
    Node*fast=head->next;
    while(head!=fast && fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node*first=head;

    Node*second=slow->next;//second ka head

    slow->next=head;//making connection between first LL (making it circualar)
    Node*curr=second;
    while(curr->next!=head){
        curr=curr->next;

    }
    curr->next=second;///making connection between second LL (making it circualar)

}