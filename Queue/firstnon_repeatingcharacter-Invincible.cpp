class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int> count;
		    queue<char> q;
		    string ans="";
		    
		    for(int i=0;i<A.length();i++){
		        char ch=A[i];
		        
		        //increase count;
		        
		        count[ch]++;
		        
		        //queue mai push karo
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()]>1){//matlab repeating character hai 
		                q.pop();
		            }
		            else{
		                //non repeating character
		                ans.push_back(q.front());
		                break;
		                
		            }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');
		            
		        }
		        
		    }
		        return ans;
		}

};
