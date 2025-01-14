
vector<int> diagonal(Node *root)
{
    queue<Node*> q;
    vector<int> ans;
    
    if(root==NULL){
        return ans;
        
    }
    
    q.push(root);
    
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        
        while(temp){
            if(temp->left){
                q.push(temp->left);//left walo ka track rkhne ke liye unko queue mai store rkho
                
            }
            
            ans.push_back(temp->data);//right walo ko print krte jao jab tak khatma na ho jaye ek line
            temp=temp->right;
            
        }
    }
    return ans;
    
}