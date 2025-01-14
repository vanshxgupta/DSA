#include <bits/stdc++.h> 


//APPROACH-1:BY PUTTING THE DATA OF LINKED LIST TO ARRAY

// #include<vector>

//     bool checkpalindrome(vector<int>arr){
//         int n=arr.size();
//         int s=0;
//         int e=n-1;
        
//         while(s<=e){
//           if (arr[s] != arr[e]) {
//             return 0;
//           }
//           s++;
//           e--;
//         }
//         return 1;
//     }

//  bool isPalindrome(LinkedListNode<int> *head)
//     {
//       vector<int>arr;
//       LinkedListNode<int>*temp=head;
//       while(temp!=NULL){
//           arr.push_back(temp->data);
//           temp=temp->next;
          
//       }
      
//       return checkpalindrome(arr);
//     }


//APPROACH 2: MORE OPTIMISED SOLUTION


//function to find the middle of linked list 
LinkedListNode<int>* getmid(LinkedListNode<int> *head){
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;

}


//function to reverse a linked list 
LinkedListNode<int>*reverse(LinkedListNode<int> *head){
    LinkedListNode<int>*curr=head;
    LinkedListNode<int>*prev=NULL;
    LinkedListNode<int>*forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}



 bool isPalindrome(LinkedListNode<int> *head)
{
    if(head==NULL || head->next==NULL){//if single element or empty list 
        return true;
    }
    
    //find mid;
    LinkedListNode<int>* middle=getmid(head);

    //reverse list after middle
    LinkedListNode<int>*temp=middle->next;
    middle->next=reverse(temp);

    //compare both halves
    LinkedListNode<int>*head1=head;//pointers banaliye , jisse compare krna hai ( head1ke data  ko head2 ke data  se compare krenge)
    LinkedListNode<int>*head2=middle->next;
    
    while(head2!=NULL){

        if(head1->data!=head2->data){
            return false;
        }

        head1=head1->next;
        head2=head2->next;
    }

    //Linked list ko vapis purane roop mai laane ke liye
    temp=middle->next;
    middle->next=reverse(temp);

    return true;

    }
