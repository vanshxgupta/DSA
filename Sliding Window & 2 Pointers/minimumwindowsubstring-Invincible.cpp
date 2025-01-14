
//OPTIMAL
class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = 1e9;
        int sindex = -1;
        string ans = "";
        int n = s.length();
        int m = t.length();
        if (m > n) {
            return "";
        }
        int hash[256] = {0};
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            hash[t[j]]++;
        }
        for (int i = 0, j = 0; j < n; j++) {
            if (hash[s[j]] > 0) {
                cnt++;
            }
            hash[s[j]]--;
            if (cnt == m) {
                while (hash[s[i]] < 0) {
                    hash[s[i]]++;
                    i++;
                }
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    sindex = i;
                }
            }
        }
        if (sindex == -1) {
            return "";
        }
        return s.substr(sindex, minlen);
    }
};
