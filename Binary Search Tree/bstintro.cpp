#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }

};
void levelordertraversal(Node*root){

    queue<Node*>q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        
            if(temp==NULL){
                cout<<endl;
            
            if(!q.empty()){
                //queue still has some child node
                q.push(NULL);

            }
            }

            else{//agar queue empty nahi hua hai tooh  
                 //left aur right mai chize  push kro
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }


    }
}

//inorder->LNR
void inorder(Node*root){
    //base case
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

//preorder->NLR
void preorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

//postorder->LRN
void postorder(Node*root){
    //base case
    if(root==NULL){
        return;

    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node*insertintobst(Node*root,int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;

    }

    if(d>root->data){
        //right part me insert krna h
        root->right=insertintobst(root->right,d);
    }
    else{
        //left part me insert krna h
        root->left=insertintobst(root->left,d);
    }
    return root;
}

void takeinput(Node*&root){

    int data;
    cin>>data;
    while(data!=-1){
        insertintobst(root,data);
        cin>>data;
    }
}
int main(){
    Node*root=NULL;
    cout<<"Enter data to create BST"<<endl;
    //10 8 21 7 27 5 4 3 -1
    takeinput(root);

    // cout<<"Printing the BST"<<endl;
    // levelordertraversal(root);

    cout<<"Printing inorder"<<endl;
    inorder(root);

    cout<<"Printing Preorder"<<endl;
    preorder(root);

    cout<<"Printing Postorder"<<endl;
    postorder(root);

    return 0;
    
}