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


int main(){

    node*root=NULL;

    //creating a tree
    root=buildtree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
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