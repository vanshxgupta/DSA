#include<iostream>
using namespace std;

//Sort 0_1_2;


//APPROACH 1: WTIH THE  REPLACEMENT OF DATA
// Node*sortlist(Node*head){
//     int zerocnt=0;
//     int onecnt=0;
//     int twocnt=0;

//     Node*temp=head;
//     while(temp!=NULL){
//         if(temp->data==0){
//             zerocnt++;

//         }
//         else if(temp->data==1){
//             onecnt++;

//         }
//         else if(temp->data==2){
//             twocnt++;

//         }
//         temp=temp->next;

//     }

//     temp=head;
//     while(temp!=NULL){
//         if(zerocnt!=0){
//             temp->data=0;
//             zerocnt--;

//         }
//         else if(onecnt!=0){
//             temp->data=0;
//             onecnt--;
//         }
//         else if(onecnt!=0){
//             temp->data=0;
//             twocnt--;
//         }

//         temp=temp->next;

        
//     }
//     return head;
// }




//APPROACH 2: IF DATA REPLACEMENT IS NOT ALLOWED
//then change links 


void insertattail(Noded*&tail,Node*curr){
    tail->next=curr;
    tail=curr;
}
Node* sortlist(Node*head){

    //creation of dummy nodes
    Node*zerohead=new Node(-1);
    Node*zerotail=zerohead;
    Node*onehead=new Node(-1);
    Node*onetail=onehead;
    Node*twohead=new Node(-1);
    Node*twotail=twohead;

    Node*curr=head;


    //create seperate list 0s,1s and 2s
    while(curr!=NULL){
        int value=curr->data;

        if(value==0){
            insertattail(zerotail,curr);

        }

        else if (value==1){
            insertattail(onetail,curr);
        }
        else if (value==2){
            insertattail(twotail,curr);

        }

        curr=curr->next;

    }

    //merge 3 sublist

    
    if(onehead->next!=NULL){//1s list not empty 
        zerotail->next=onehead->next;
    }

    else{
        //1s list ->empty
        zerotail->next=twohead->
    }
    
    onetail->next=twohead->next;
    twotail->next=NULL;

    //setuphead of merged list
    head=zerohead->next;

    //delete dummynodes
    delete zerohead;
    delete onehead;
    delete twohead;


    return head;
    
    
}

