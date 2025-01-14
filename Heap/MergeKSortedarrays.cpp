#include <bits/stdc++.h> 
#include<queue>
class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int row,int col){
       
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class compare{
    public:
    bool operator()(node*a,node*b){
        return a->data >b->data;

    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare>minheap;
    
    //step1:saare arrays k first element insert h
    for(int i=0;i<k;i++){
        node*temp=new node(kArrays[i][0],i,0);
        minheap.push(temp);
    }

    vector<int>ans;
    //step2:
    while(minheap.size()>0){
        node*temp=minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        int row=temp->row;
        int col=temp->col;

        if(col+1<kArrays[row].size()){
            node*next=new node(kArrays[row][col+1],row,col+1);
            minheap.push(next);

        }
    }
    return ans;
}