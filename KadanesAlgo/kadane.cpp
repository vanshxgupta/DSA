 int maxSubArray(vector<int>& nums) {
    int n=nums.size();

    int sum=0;
    int i=0;
    int maxi=INT_MIN;
    while(i<n){
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
        i++;
    }

    return maxi;

}
