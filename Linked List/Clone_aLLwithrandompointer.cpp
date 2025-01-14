//Clone a linked list with next and random pointer

//APPROACH 2:use of map 

// #include<bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node*next;
//     Node*arb;

//     Node(int x){
//         data==x;
//         next=NULL;
//         arb=NULL;

//     }
// };

// class Solution
// {
    
//     private:
//     void insertattail(Node*head,Node*tail,int d){
//         Node*newnode=new Node(d);
//         if(head==NULL){
//             head=newnode;
//             tail=newnode;
//             return;
//         }
//         else{
//             tail->next=newnode;
//             tail=newnode;
//         }
//     }
//     public:
//     Node *copyList(Node *head)
//     {
//         //step1:create a clone list 
        
//         Node*clonehead=NULL;
//         Node*clonetail=NULL;
        
//         Node*temp=head;
//         while(temp!=NULL){
//             insertattail(clonehead,clonetail,temp->data);
//             temp=temp->next;
//         }
        
        
//         //step2Lcreate a map
//         unordered_map<Node*,Node*> oldtonewnode;
        
//         Node*originalnode=head;
//         Node*clonenode=clonehead;
//         while(originalnode!=NULL && clonenode!=NULL){
//             oldtonewnode[originalnode]=clonenode;
//             originalnode=originalnode->next;
//             clonenode=clonenode->next;
            
//         }
        
//         originalnode=head;
//         clonenode=clonehead;
        
//         while(originalnode!=NULL){
//             clonenode->arb=oldtonewnode[originalnode->arb];//random ka naam isme arb rakha hua hai 
//             originalnode=originalnode->next;
//             clonenode=clonenode->next;
            
//         }
//         return clonehead;
        
        
        
//     }
// };




//APPROACH 3:without use of map
//changing links 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

    private:
    void insertattail(Node*&head,Node*&tail,int d){
        Node*newnode=new Node(d);

        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;

        }
    }
public:
    Node* copyRandomList(Node* head) {

        // step1:create a clone list 
        Node*clonehead=NULL;
        Node*clonetail=NULL;

        Node*temp=head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }

        //step2: clonenodes add in between original list 
        Node*originalnode=head;
        Node*clonenode=clonehead;

        while(originalnode!=NULL && clonenode!=NULL){
            Node*forward=originalnode->next;
            originalnode->next=clonenode;
            originalnode=forward;

            forward=clonenode->next;
            clonenode->next=originalnode;
            clonenode=forward;

        }

        //step3: random pointer copy
        
        temp=head;

        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                }
            else{
                temp->next->random=temp->random;
            }

            }
            temp=temp->next->next;
        }


        //step4: revert changes done in step2 
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
            originalnode->next=clonenode->next;
            originalnode=originalnode->next;

            if(originalnode!=NULL)
            clonenode->next=originalnode->next;

            clonenode=clonenode->next;



        }

        //step5: return ans;
        return clonehead;

    }
};
