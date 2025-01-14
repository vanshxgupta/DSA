//APPROACH 1:

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> visited;
//         int n = s.length();
//         int ans = 0, i = 0, j = 0;
//         while (i < n && j < n) {
//             if (visited.find(s[j]) == visited.end()) {//if element not found than insett it
//                 visited.insert(s[j++]);
//                 ans = max(ans, j - i);
//             } else {
//                 visited.erase(s[i++]);
//             }
//         }
//         return ans;
//     }
// };


//APPROACH 2:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={-1};
        int l=0;int r=0;
        int maxlen=0;
        int n=s.size();

        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;

                }


            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            hash[s[r]]=r;
            r++;

        }
        return maxlen;

    }
};
