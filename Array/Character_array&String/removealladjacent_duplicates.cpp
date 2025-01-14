// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        int i=0;
        stack<char> st;
        while(i<n){
            if(st.empty() || st.top()!=s[i]){//agar stack empty hai ya stack ka top wala 
            //element string ke element ke equal nahi hai tooh vo element stack mai daal do;

                st.push(s[i]);


            }
            else{
                st.pop();//nahi tooh vo element ko pop kar do ;
                
            }
            i++;


        }
        string ans="";
        while(!st.empty()){//jab tak string empty nahi ho jaati 
            char ele=st.top();//top ke element ko element mai store kara 
            st.pop();//aur us element ko nikaal liya 
                //iss trhe se stack ke element ko nikaalte hai 

            ans+=ele;

        }
        reverse(ans.begin(),ans.end());
        return ans;
       


        
    }
};