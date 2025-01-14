// //APPROACH 1:
// void inorder(TreeNode *root,vector<int>&ans){
//     if(root==NULL){
//         return ;
//     }

//     inorder(root->left,ans);
//     ans.push_back(root->data);
//     inorder(root->right,ans);
// }


// vector<int> mergearray(vector<int> &a, vector<int> &b){
//     vector<int> ans;
//     int i=0;
//     int j=0;
//     while(i<a.size()&& j<b.size()){
//         if(a[i]<b[j]){
//             ans.push_back(a[i++]);
//         }
//         else{
//             ans.push_back(b[j++]);
//         }
//     }
//     while(i<a.size()){
//         ans.push_back(a[i++]);
//     }
//     while(j<b.size()){
//         ans.push_back(b[j++]);
//     }
//     return ans;
// }


// TreeNode* inordertoBST(int s, int e, vector<int>&arr){

//     //base case
//     if(s>e){
//         return NULL;
//     }

//     int mid=(s+e)/2;
//     TreeNode*root=new TreeNode(arr[mid]);
//     root->left=inordertoBST(s,mid-1,arr);
//     root->right=inordertoBST(mid+1,e,arr);
//     return root;

// }

// vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
// {

//     //step1:store the inorders of both the bsts
//     vector<int> in1;
//     vector<int> in2;

//     inorder(root1,in1);
//     inorder(root2,in2);


//     //step 2: merge the two inorder arrays
//     vector<int>mergedarray=mergearray(in1,in2);
//     return mergedarray;

//     //step 3: inorder to BST ;

//     //int s=0;
//     //int e=mergedarray.size()-1;
//     //return inordertoBST(s,e,arr);
// }





//APPROACH 2:
void convertedintosortedDLL(TreeNode<int>*root,TreeNode<int>*&head){
    //base case
    if(root==NULL){
        return NULL;
    }

    convertintosortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }

    head=root;
    
    convertedintosortedDLL(root->left,head);
}

TreeNode<int>mergeDLL(TreeNode<int>*head1,TreeNode<int>*head2){

    TreeNode<int>*head=NULL;
    TreeNode<int>*tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                    head=head1;
                    tail=head1;
                    head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;

            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;

            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head1=head2->right;
            }
        }
    }
    while(head1!=NULL){
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
                
    }
    while(head2!=NULL){
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;

    }

    return head;


}
int countnodes(TreeNode<int>*head){
    int cnt=0;
    TreeNode<int>*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
TreeNode<int>*sortedDLLtoBST(TreeNode<int>*&head,int n){

    //base case
    if(n<=0 || root==NULL){
        return NULL;
    }

    TreeNode<int>*left=sortedLLtoBST(head,n/2);
    root->left=left;

    head=head->right;
    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
    
}



vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {

    //Step 1: Convert a BST into sorted LL
    TreeNode*head1=NULL;
    convertedintosortedDLL(root1,head1);
    head1->left=NULL;

    TreeNode*head2=NULL;
    convertedintosortedDLL(root2,head2);
    head2->left=NULL;

    //Step 2: Merge 2 sorted LL
    
    TreeNode<int>*head=mergeDLL(head1, head2);

    //Step 3:

    return sortedDLLtoBST(head,countnodes(head));

}
