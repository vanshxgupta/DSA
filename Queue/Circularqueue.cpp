#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int front;
    int rear;
    int *arr;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n) {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {
        // checking if the queue is full
        if ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) {
            // cout<<"Queue is full"<<endl;
            return false;
        } else if (front == -1) { // to push the first element in the queue
            rear = 0;
            front = 0;
            arr[rear] = value;
        } else if (front != 0 && rear == size - 1) { // to push an element in queue when the queue is full forward but has space at starting
            rear = 0; // to maintain cyclic nature
            arr[rear] = value;
        } else { // normal case
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue() {
        // checking if the queue is empty
        if (front == -1) {
            return -1;
        }
        int ans = arr[front]; // store the value to be popped
        arr[front] = -1; // mark the position as empty
        // if there is single element in queue
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return ans;
    }
};
