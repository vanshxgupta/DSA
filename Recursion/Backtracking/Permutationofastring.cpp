// Given an array nums of distinct integers, return all the possible permutations. You can 
//return the answer in any order.

 

class Solution {
    private:

    void solve(mevector<int> &nums,vector<vector<int>> &ans,int index){

        //base case
        if(index>=nums.size()){
            ans.push_back(nums);//is question mai hmne extra space ka use na krte huye ,nums mai hi pushback kar diya
            return ;
        }

        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);

            //backtrack
            swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        int index=0;
        solve(nums,ans,index);
        return ans;


        
    }
};