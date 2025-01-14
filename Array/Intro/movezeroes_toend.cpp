//Given an integer array nums, move all 0's to the
// end of it while maintaining the relative order 
//of the non-zero elements.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        //shift kar raha hai all non zero value to left , tooh apne zero vali value right mai aa jaati hai
        int nonzero=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){//nums ko ek ek karke traverse karega ,agar 0 ayega tooh ignore marrke aage ,
            //agar dusra koi element aya tooh swap kardo previous 0 ke saath 
                swap(nums[nonzero],nums[j]);
                nonzero++;

            }


        }
        
    }
};