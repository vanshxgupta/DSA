class Solution {
    int solve(vector<int>&nums , int k){

        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        int n=nums.size();

        
       while(r<n){
        
        sum+=(nums[r]%2);//nums[l]%2 will give 1 if nums[l] is odd otherwise it will give 0
        while(sum>k){
            sum=sum-(nums[l]%2);//nums[l]%2 will give 1 if nums[l] is odd otherwise it will give 0
            l++;
        }  
        cnt+=(r-l+1);

        r++;

       }
       return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int x=solve(nums,k);
        int y=solve(nums,k-1);
        return x-y;

    }
};