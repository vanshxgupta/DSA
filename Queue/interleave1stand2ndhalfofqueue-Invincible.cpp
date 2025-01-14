
// //METHOD: USING STACK
// class Solution{
// public:
//     vector<int> rearrangeQueue(queue<int> &q){
//         vector<int> v;
//         int n=q.size();
//         stack<int>s;
//         while(q.size()>n/2){
//             int val=q.front();
//             q.pop();
//             s.push(val);
            
//         }
        
//         while(!s.empty()){
//             int val=s.top();
//             s.pop();
//             q.push(val);
//         }
        
//         while(q.size()>n/2){
//             int val=q.front();
//             q.pop();
//             q.push(val);
            
//         }
        
//         while(!s.empty()){
//             int val=s.top();
//             s.pop();
            
//             q.push(val);
//             val=q.front();
//             q.pop();
//             q.push(val);
            
            
//         }

           // while(!q.empty){

//         v.push_back(q.front());
//          q.pop();
//         return v;
// }
        
        
//     }
// };

//METHOD: