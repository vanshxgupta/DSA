#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;


    }

};

//functionn to build a tree
node* buildtree(node*root){

    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;

    }

    cout<<"enter data for inserting in left of "<< data <<endl;
    root->left = buildtree(root->left);
    cout<<"enter data for inserting in right of "<< data <<endl;
    root->right = buildtree(root->right);

    return root;

}


//inorder->LNR
void inorder(node*root){
    //base case
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

//preorder->NLR
void preorder(node*root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

//postorder->LRN
void postorder(node*root){
    //base case
    if(root==NULL){
        return;

    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

node* buildfromlevelorder(node*root){
    queue<node*>q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=neww node(data);
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        cout<<"enter left node for:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
            
        }
        cout<<"enter right node for:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);

        }

    }
}


int main(){

    node*root=NULL;

    //creating a tree
    root=buildtree(root);

    //give this input->   1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order 


    cout<<"inorder traversal is ";
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is ";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is ";
    postorder(root);



    return 0;
}