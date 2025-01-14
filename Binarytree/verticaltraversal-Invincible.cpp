// class Solution
// {
//     public:
//     //Function to find the vertical order traversal of Binary Tree.
//     vector<int> verticalOrder(Node *root)
//     {
//         map<int, map<int,vector<int> > > nodes;
//         queue< pair<Node*, pair<int,int> > > q;
//         vector<int> ans;
        
//         if(root == NULL)
//             return ans;
            
//         q.push(make_pair(root, make_pair(0,0)));
        
//         while(!q.empty()) {
//             pair<Node*, pair<int,int> > temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second.first;
//             int lvl = temp.second.second;
            
//             nodes[hd][lvl].push_back(frontNode->data);
            
//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
//         }
        
//         for(auto i: nodes) {
//             // i is <node,map>
            
//             for(auto j:i.second) {
//                 // j i map , where map is <hd, vector<int>>
                
//                 for(auto k:j.second)
//                 {
//                     // k is vector<int>
//                     ans.push_back(k);
//                 }
//             }
//         }
//         return ans;
//     }
// };






//for vertical traversal of binary tree if we are using level order traversal then maintaining level is redundant, we can do it only by using horizontal distance. Attaching code reference for better underatanding.
vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(!root)
        return ans;
        
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int> p = q.front();
            q.pop();
            
            Node *curr = p.first;
            int hd = p.second;
            
            mp[hd].push_back(curr->data);
            
            if(curr->left)
            q.push(make_pair(curr->left,hd-1));
            if(curr->right)
            q.push(make_pair(curr->right,hd+1));
        }
         for(auto it: mp)
        {
            for(auto i : it.second)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
  