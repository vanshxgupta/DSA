class Solution
{
    private:
    
    int findposition(int in[],int inorderstart,int inorderend,int element,int n){
        for(int i=inorderstart;i<=inorderend;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    Node *solve(int in[],int post[],int& index,int inorderstart,int inorderend,int n){
        //base case
        if(index<0 || inorderstart>inorderend){
            return NULL;

        }
        
        //create a root node of element
        int element=post[index--];//
        Node*root=new Node(element);
        int position=findposition(in ,inorderstart,inorderend,element,n);
        
        //recursive call(in case of inorder an post order traversal, we build the right subtree first)
        root->right=solve(in,post,index,position+1,inorderend,n);
        root->left=solve(in,post,index,inorderstart,position-1,n);
        return root;
        
        
    }
    
    public:
    //Function to return a tree created from postorder and inorder traversals.
    Node *buildTree(int in[], int post[], int n) {
      int postorderindex=n-1;//post order is LRN so Last element is root .
      Node*ans=solve(in,post,postorderindex,0,n-1,n);
      return ans;
       
    }
};
