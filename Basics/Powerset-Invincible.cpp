//https://www.youtube.com/watch?v=b7AYbpM5YrE&ab_channel=takeUforward

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {//meaning of 1<<n is pow(2,n)
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not (set matlab 1 hai ya nahi )
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
};
