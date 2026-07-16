vector<int> printmaxsubarray(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans;

    int left = 0;
    int sum = 0;
    int maxi = INT_MIN;

    int maxleft = 0;
    int maxright = 0;

    int i = 0;
    while(i < n) {
        sum += nums[i];
        if(sum > maxi) {
            maxi = sum;
            maxleft = left;
            maxright = i;
        }
        if(sum < 0) {
            sum = 0;
            left = i + 1;
        }
        i++;
    }
    for(int i = maxleft; i <= maxright; i++) {
        ans.push_back(nums[i]);
    }
    return ans;
}

