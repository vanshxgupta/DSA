#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node{
public:
    int data;
    node *left, *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(){
    int d;
    cout<<"enter data: ";
    cin>>d;
    if(d == -1){
        return NULL;
    }

    node *root = new node(d);
    root->left = buildtree();
    root->right = buildtree();

    return root;
}

void reverseordertraversal(node *root){
    queue<node*> q;
    stack<node*> s;
    stack<node*> ns;
    
    q.push(root);
    s.push(NULL);
    s.push(root);
    q.push(NULL);
    s.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
                s.push(NULL);
            }
        }
        else{
            if(temp->left){
                q.push(temp->left);
                s.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
                s.push(temp->right);
            }
        }
    }

    while(!s.empty()){
        while(s.top() != NULL){
            node *temp = s.top();
            ns.push(temp);
            s.pop();
        }
        while(!ns.empty()){
            node*tempi=ns.top();
            cout<<tempi->data<<" ";
            ns.pop();
        }

        if(!s.empty()){
            s.pop(); // popping NULL
        }
        cout<<endl;
    }
}

int main(){
    node *root = NULL;
    root = buildtree();

    //give this input->   1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout<<"printing the level order traversal output"<<endl;
    reverseordertraversal(root);

    return 0;
}

