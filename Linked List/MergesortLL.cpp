#include<iostream>
using namespace std;

Node*findmid(Node*head){
    Node*fast=head->next;
    Node*slow=head;

    while(fast!=NULL && fast->next!=NULL && slow!=NULL){
        fast=fast->next->next;
        slow=slow->next;

    }
    return slow;

}

Node*merge(Node*left,Node*right){
    if(left==NULL){
        return right;//agar left part NULL hai tooh right wale ko return kardo 

    }
    if(right==NULL){
        return left;

    }

    Node*ans=new Node(-1);
    Node*temp=ans;
    
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;

        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;

        }

    }
    while(left!=NULL){//Jab right null ho jaye par left null na ho
            temp->next=left;
            temp=left;
            left=left->next;

    }
    while(right!=NULL){//Jab left null ho jaye par right null na ho
            temp->next=right;
            temp=right;
            right=right->next;
    }
    ans=ans->next;
    return ans;

}

Node* mergesort(Node*head){

    //base case
    if(head==NULL || head->next==NULL){
        return head;

    }

    //break linked list into 2 halves,after finding mid
    Node*mid=findmid(head);
    Node*left=head;//starting of left part
    Node*right=mid+1;//starting of right part
    
    mid->next=NULL;//isko null se point kara diya tooh yaha ab tooh links  ban gayi alg alg , ek head se mid tak aur dusri mid+1 se NULL tk

    //recursive calls to sort both halves
    left=mergesort(left);
    right=mergesort(right);

    //merge both left and right 
    Node*result=merge(left,result);

    return result;

}