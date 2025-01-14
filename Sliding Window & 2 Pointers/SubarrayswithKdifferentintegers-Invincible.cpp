class Solution {

    int solve(vector<int>&nums,int k){
        int l=0;
        int r=0;
        int cnt=0;
        map<int,int> mp;
        int n=nums.size();
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
                
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int x=solve(nums,k);
        int y=solve(nums,k-1);
        return x-y;
    }
};