#include<queue>
#include<iostream>
using namespace std;

int main(){
    cout<<"Using priority queue here"<<endl;

    //max heap
    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"size is "<<pq.size()<<endl;
    cout<<"element at top:"<<pq.top()<<endl;
    pq.pop();
    cout<<"size is "<<pq.size()<<endl;

    cout<<"element at top:"<<pq.top()<<endl;
    pq.pop();

    cout<<"size is "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"pq is empty"<<endl;

    }
    else{
        cout<<"pq is not empty"<<endl;

    }
    cout<<endl;

    //min heap
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"size is "<<minheap.size()<<endl;
    cout<<"element at top:"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"size is "<<minheap.size()<<endl;

    cout<<"element at top:"<<minheap.top()<<endl;
    minheap.pop();

    cout<<"size is "<<minheap.size()<<endl;

    if(minheap.empty()){
        cout<<"minheap is empty"<<endl;
    }

    else{
        cout<<"minheap is not empty"<<endl;
    }

    return 0;
}