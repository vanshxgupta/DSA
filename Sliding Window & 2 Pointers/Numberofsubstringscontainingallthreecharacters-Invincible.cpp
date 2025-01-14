//BRUTE FORCE
class Solution {
public:
    int numberOfSubstrings(string s) {
        int num=0;
        int n=s.length();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp.size()==3){
                num++;

            }
        
            }
        }
        return num;
    
    }
};
