//Detect and Remove Loop 
#include<map>
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

};
 
//APPROACH 1:(using map)



// bool detectloop(Node*&head){

//     Node*temp=head;
//     if(head==NULL) return false;//empty list mai tooh loop hoga hi nahi

//     map<Node*,bool> visited;
    
//     while(temp!=NULL){


//         if(visited[temp]==true){//cycle is present
//         return 1;
//         }
//         visited[temp]=true;
//         temp=temp->next;

//     }
//     return false;
// }



//APPROACH 2:FLOYD'S CYCLE DETECTION ALGO

Node* floyddetectloop(Node*head){
    if(head==NULL){
        return NULL;
    }

    Node*slow=head;
    Node*fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;

        }

        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node *getstartingnode(Node*head){
    if(head==NULL){
        return NULL;

    }

    Node*intersection=floyddetectloop(head);//intersection is the point where slow and fast met before in floyds detection loop
    Node*slow=head;
    if(intersection==NULL){
        return NULL;
    }
    
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;

    }
    return slow;

}

Node* removeloop(Node*head){
    if(head==NULL){
        return NULL;
    }

    Node*startofloop=getstartingnode(head);
    Node*temp=startofloop;

    if(startofloop==NULL){
        return head;
    }
    while(temp->next!=startofloop){
        temp=temp->next;

    }
    temp->next=NULL;
    return head;
}