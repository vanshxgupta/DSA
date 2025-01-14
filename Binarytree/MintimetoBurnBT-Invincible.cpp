class Solution {
    
    //create mapping
    //return targetnode
    Node* createparentmapping(Node* root, int target, map<Node*,Node*>& nodetoparent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodetoparent[root] = NULL;//root ka parent null hai 

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                res = front;
            }

            if (front->left) {//mapping create kar di ke front ke left ka parent front hai
                nodetoparent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {//mapping create kar di ke front ke left ka parent front hai
                nodetoparent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }
    
    int burntree(Node* root, map<Node*,bool>& visited, map<Node*,Node*>& nodetoparent) {
        queue<Node*> q;
        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty()) {
            bool flag = false;//ye check rkhega ke koi addition hua hai ya nahi queue mai , agar koi additionn hua hai tooh flag=true kr dena udhar
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                //process neightbouring nodes
                Node* front = q.front();
                q.pop();


                //node ka left manage krlo
                if (front->left && !visited[front->left]) {//agar front ka left exist karta hai aur visited exist nhi krta hai tooh
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                
                
                //node ka right manage krlo
                if (front->right && !visited[front->right]) {//agar front ka right exist karta hai aur visited exist nhi krta hai tooh 
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                

                //node ka parent mange krlo
                if (nodetoparent[front] && !visited[nodetoparent[front]]) {//agar front ka parent exist karta hai aur visited exist nhi krta hai tooh 
                    flag = true;
                    q.push(nodetoparent[front]);
                    visited[nodetoparent[front]] = true;
                }
            }

            if (flag) {
                ans++;
            }
        }

        return ans;
    }
    
  public:
    int minTime(Node* root, int target) {
        
         //algo:
        //step1:create nodetoparent mapping
        //step2: find the target node
        //step3:burn the tree in min time
        
        
        map<Node*,Node*> nodetoparent;
        Node* targetnode = createparentmapping(root, target, nodetoparent);

        map<Node*,bool> visited;
        int ans = burntree(targetnode, visited, nodetoparent);

        return ans;
    }
};