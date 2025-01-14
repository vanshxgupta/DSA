// Total Time Complexity:
// Preprocessing the LPS array: O(m)
// Pattern Matching: O(n)
// Thus, the total time complexity is O(m + n).


class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        
        int m = pat.size();
        int n = txt.size();
        
        // Create an LPS array to store the longest proper prefix which is also a suffix
        //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
        // Step 1: Compute LPS (Longest Prefix Suffix) array->
        vector<int> LPS(m, 0);
        int length = 0;
        int i = 1;  // Start from the second character
        
        while (i < m) {
            if (pat[i] == pat[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = LPS[length - 1];  // Fall back to the previous longest prefix suffix
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        
        vector<int> ans;
        // Step 2: Perform KMP search
        i = 0;  // index for txt
        int j = 0;  // index for pat
        
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            
            if (j == m) {  // Found a match
                ans.push_back(i - j);
                j = LPS[j - 1];  // Use the LPS array to avoid unnecessary rechecks
            } else if (txt[i] != pat[j]) {  // Mismatch
                if (j != 0) {
                    j = LPS[j - 1];  // Use the LPS array to skip the pattern portion
                } else {
                    i++;  // Move to the next character in the text
                }
            }
        }
        
        return ans;
    }
};
