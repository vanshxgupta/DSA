#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* createLinkedListFromArray(int arr[], int size){
    Node* head = new Node;
    head->data = arr[0];
    head->next = NULL;
    
    Node* current = head;

    for(int i=1; i<size; i++){
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    
    return head;
}

int main(){
    int arr[6] = {4, 5, 6, 7, 8, 9};
    Node* head = createLinkedListFromArray(arr, 6);

    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
