class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	
    	if(root==NULL){
    	    return ans;
    	}
    	
    	queue<Node*>q;
    	bool lefttoright=true;
    	q.push(root);
    	
    	while(!q.empty()){
    	    
    	    int size=q.size();
    	    vector<int> arr(size);
    	    
    	    
    	    //level process
    	    for(int i=0;i<size;i++){
    	        
    	        Node*frontNode=q.front();
    	        q.pop();
    	        
    	        
    	        //normal insert or reverse insert?
    	        int index= lefttoright ? i:size-i-1;
    	        arr[index]=frontNode->data;
    	        
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	            
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	            
    	        }
    	        
    	    }
    	    //direction change of traversal
    	    lefttoright=!lefttoright;
    	    
    	        for(auto i:arr){
    	            ans.push_back(i);
    	        }
    	        
    	    
    	    
    	}
    	return ans;
    }
};