#include <bits/stdc++.h>

class Deque {
    int* arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x) {
        // full ki condition
        if ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) {
            return false;
        }

        // to push first element
        else if (front == -1) {
            front = rear = 0;
        }

        // to maintain cyclic order
        else if (front == 0) {
            front = size - 1;
        } else { // normal flow
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x) {
        // full ki condition
        if ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) {
            return false;
        }

        // to push first element
        else if (front == -1) {
            front = rear = 0;
        }

        // to maintain cyclic order
        else if (rear == size - 1) {
            rear = 0;
        } else { // normal flow
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront() {
        // queue is empty?
        if (front == -1) {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        // if queue contains only single element
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) { // to maintain cyclic nature
            front = 0;
        } else { // normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear() {
        // queue is empty?
        if (front == -1) {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        // if queue contains only single element
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) { // to maintain cyclic nature
            rear = size - 1;
        } else { // normal flow
            rear--;
        }
        return ans;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        if (front == -1) {
            return true;
        } else {
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() {
        // full ki condition
        if ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) {
            return true;
        } else {
            return false;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
};
