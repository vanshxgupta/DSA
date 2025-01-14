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

int main(){

    node*root=NULL;

    //creating a tree
    root=buildtree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order 

    cout<<"printing the level order traversal output"<<endl;
    levelordertraversal(root);


    return 0;
}