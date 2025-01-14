#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int data;
    Stack*next;

    Stack(int data){
        this->data=data;
        next=NULL;
    }

    void push(int element,Stack*&head,Stack*&tail){
        Stack*newnode=new Stack(element);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        else{
            //assuming element is present 
            tail->next=newnode;
            tail=newnode;
        }
    }    

    void pop(Stack*&head,Stack*&tail){
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            //edge case for last element

            if(head==tail){//if it has only one element 
                head=NULL;
                return;

            }

            Stack*temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
        }
    }

    int peak(Stack*&tail){

        if(tail==NULL){
            cout<<"Stack empty"<<endl;
        }
        else{
            return tail->data;
        }

    }

    bool isempty(Stack*&head){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }

};
    void print(Stack*&head){
        Stack*temp=head;
        if(temp==NULL) cout<<temp->data <<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

int main(){
    Stack *head = NULL;
    Stack *tail = NULL;
    Stack st(0);
    st.push(4,head,tail);
    st.push(8,head,tail);
    st.push(6,head,tail);
    print(head);


    cout <<"Peek element is "<< st.peak(tail) <<endl;

    st.pop(head,tail);

    print(head);
    
    cout<<"Peak element is "<<st.peak(tail) <<endl;

    st.pop(head,tail);

    print(head);

    st.pop(head,tail);

    if( st.isempty(head)){
        cout << "Stack is empty "<<endl;
    }else{
        cout<< "Stack is not empty"<<endl;
    }
        return 0;
}