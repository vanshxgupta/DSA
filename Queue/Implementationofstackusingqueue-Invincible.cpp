//Implementation of stack using single queue

class MyStack {
public:
    MyStack() {
        
    }
    
    queue<int> q;
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
    }
};

//METHOD 2:IMPLEMENTATION OF STACK USING 2 QUEUES
// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();

//         }
//         swap(q1,q2);

//     }
    
//     int pop() {
//         int top=q1.front();
//         q1.pop();
//         return top;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();   
//     }
// };