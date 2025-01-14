//Remove Duplicates From an Unsorted Linked List


//APPROACH 1 :
Node *removeDuplicates(Node *head)
{
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        Node* temp = curr;
        while (temp->next != NULL) {
            if (curr->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

//Approach 2:
