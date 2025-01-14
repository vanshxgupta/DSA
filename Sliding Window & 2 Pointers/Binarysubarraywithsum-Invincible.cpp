//BRUTE FORCE Shyd nahi chl payega kyunki constraints 10^4 tak hai aur 0(n^2) approach 10^8 tk chle jayega
//BETTER APPORACH-WE CAN USE HASHING WHICH WILL TAKE T.C-->O(N) AND S.C-->O(N)
//SO THINK OF CAN WE OPTIMISE THE S.C FURHTER?THERE WE ARE USING MAP ,CAN WE DO WITHOUT MAP?-->YES SLIDING WINDOW AND 2 POINTER

//OPTIMAL
class Solution {
    int solve(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int n=nums.size();
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal ){ 
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int x=solve(nums,goal);
        int y=solve(nums,goal-1);

        return x-y;
    }
};
