// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.





// //Method 1: Using nested loops
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> v;
//         for(int i =0;i<nums.size();i++){
//             for(int j = i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     v.push_back(i);
//                     v.push_back(j);
//                     break;

//                 }
//             }
//         }
//         return v;
        
//     }
// };


//Method 2:Using map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {//numMap.count(complement) is a function call that checks whether the key complement exists in the numMap or not.
                return {numMap[complement], i}; //nummap[compliment](key) will  give the index(value) attached to this complement
            }
            numMap[nums[i]] = i;//If the condition nummap.count(compliment )is false, this line inserts the current number nums[i] and its index i into the numMap. This is done to make the number available for potential matches later in the loop.
        }

        return {}; // if no solution found!!
    }
};