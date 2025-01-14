//in case of circular 
//increment->f=(f+1)%n;
//decrement->f=(f-1+n)%n


//USING ARRAY
class MyCircularDeque {
public:
    vector<int>deq;
    int k;
    int front;
    int rear;
    int currcnt;

    MyCircularDeque(int k) {
        this->k=k;
        deq=vector<int>(k,0);
        front=0;
        rear=k-1;
        currcnt=0;
    
    }
    
    bool insertFront(int value) {
        if(currcnt==k){
            return false;

        }
            front=(front-1+k)%k;
            deq[front]=value;
            currcnt++;
            return true;
    }
    
    bool insertLast(int value) {
        if(currcnt==k){
            return false;
        }
        rear=(rear+1)%k;
        deq[rear]=value;
        currcnt++;
        return true;

    }
    
    bool deleteFront() {
        if(currcnt==0){
            return false;
        }
        front=(front+1)%k;
        currcnt--;
        return true;
    }
    
    bool deleteLast() {
        if(currcnt==0){
            return false;
        }
        rear=(rear-1+k)%k;
        currcnt--;
        return true;   
    }
    
    int getFront() {
        if(currcnt==0){
            return -1;
        }
        return deq[front];
        
    }
    
    int getRear() {
        if(currcnt==0){
            return -1;
        }
        return deq[rear];
        

    }
    
    bool isEmpty() {
        if(currcnt==0) return true;
        return false;
    }
    
    bool isFull() {
        if(currcnt==k) return true;
        return false;
    }
};


//USING LINKED LIST

//std::list<int>-->doubly linked list
//list.push_front();
//list.push_back();
//list.pop_front();
//list.pop_back();
//list.isempty();