class Solution {
    private:
    bool ispalindrome(string&s,int index,int end){
        while(index<end){
            if(s[index++]!=s[end--]){
                return false;

            }

        }
        return true;
    }
    void solve(string&s,int index,vector<string>&output,vector<vector<string>>&ans){
        int n=s.length();
        if(index>=s.length()){
            ans.push_back(output);
        }


        for(int i=index;i<n;i++){
            if(ispalindrome(s,index,i)){
                output.push_back(s.substr(index,i-index+1));
                solve(s,i+1,output,ans);
                output.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>output;
        int index=0;
        solve(s,index,output,ans);
        return ans;
    }
};