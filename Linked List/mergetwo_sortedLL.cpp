#include<iostream>
using namespace std;


void solve(Node<int>*first,Node<int> *second){

    //if only one element is present in first LL
    if(first->next==NULL){
        first->next=second;
        return first;
        
    }

    Node<int>*curr1=first;
    Node<int>*next1=curr1->next;
    Node<int>*curr2=second;
    Node<int>*next2=curr2->next;
    while(curr1!=NULL && next1!=NULL && curr2!=NULL){
        //agar curr2 dono ke bich mai lie krta hai tooh rakhdo 
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data )){
            
            //add node in between the first line 
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;


            //updating pointers
            curr1=curr2;
            curr2=next2;

        }
        //agar lie nahi krta tooh pointers aage badha do 
        else{
            //curr1 and next1 ko aage badhana padega
            curr1=curr1->next;
            next1=next1->next;

            //par firse check karlo aage badhane ke baad ke ,kya next1 null tooh nahi ho gya
            if(next1==NULL){
                curr1->next=curr2;
                return first;//agar ho gya hai next1 null tooh first return krdo aur second wali list ke aage chipka do 

            }
            
        }


    }
    return first;
}
Node<int>*sorttwolists(Node<int>*first,Node<int>*second){
    if(first==NULL){
        return second;

    }

    if(second==NULL){
        return first;

    }

    //jis linked list ka first element sabse chota hai,vo first linked list manana hai
    if(first->data <= second->data){
        solve(first,second);

    }
    else{
        solve(second,first);
    }
}