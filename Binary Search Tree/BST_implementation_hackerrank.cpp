
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int val;
    Node(int val){
        left=NULL;
        right=NULL;
        this->val=val;
    }
};

class BST{
    public:
    Node* insertelement(int value,Node* root){
        Node*newnode=new Node(value);
        if(root==NULL){
            root=newnode;
            return root;
        }
        
        Node *curr=root;
        while(true){
            if(curr->val>value){
                if(curr->left==NULL){
                    curr->left=new Node(value);
                    return root;
                }
                curr=curr->left;
            }
            else{
                if(curr->right==NULL){
                    curr->right=new Node(value);
                    return root;
                }
                curr=curr->right;
            }
        }

        return root;
    }
    
    bool searchelement(int value,Node* root){
        Node*curr=root;
        while(curr!=NULL){
            if(curr->val ==value){
                return true;
            }
            if(curr->val>value){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return false;
    }
    
    int maxelement(Node* root){
        if(root == NULL){
            return -1;
        }

        Node* cur = root;

        while(cur->right){
            cur = cur->right;
        }

        return cur->val;
    }
    
     int minelement(Node* root){
        if(root == NULL){
            return -1;
        }

        Node* cur = root;

        while(cur->left){
            cur = cur->left;
        }

        return cur->val;
    }
    
};


int main(){

    BST tree;
    Node* root = NULL;

    while(true){
        int op;
        cin>>op;
        if(op==5){
            break;
        }
        else if(op==1){
            int val;
            cin>>val;
            if(tree.searchelement(val,root)){
                cout<<"FOUND"<<endl;
            }
            else{
                cout<<"NULL"<<endl;
            }
        }
        else if(op==2){
            cout<<"max: "<<tree.maxelement(root)<<endl;
        }
        else if(op==3){
            cout<<"mini: "<<tree.minelement(root)<<endl;
        }
        else{
            int val;
            cin>>val;
            
            root = tree.insertelement(val, root);
        }
        
    }
    return 0;
}
