class Solution{
    private:
    int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    Node* solve(int in[],int pre[], int &index ,int inorderStart , int inorderEnd , int n){

        //base case
        if(index>=n || inorderStart>inorderEnd){
            return NULL ;
        }
        

        //create a root node for element 
        int element = pre[index++] ; // At every interation index is increasing
        Node* root  = new Node(element); 

        //find element's index in inorder
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);

        //recursive calls 
        root->left = solve(in , pre , index  , inorderStart , position-1 ,n);
        root->right = solve(in , pre , index , position+1 , inorderEnd ,n);
        
        return root ;
        
    }

    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        
         int preorderindex  = 0 ;  //Pre order is NLR so First element is root .
         
         Node* ans = solve(in, pre, preorderindex , 0  , n-1 , n);
         return ans ;
}
};
