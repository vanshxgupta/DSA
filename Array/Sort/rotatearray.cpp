// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //logic hai ki , jis point se hamko array ko rotate karna hai
        //uske phele wale saare elements ko use point ke number se aage badha do aur 
        //bache hue point  wale baad ke number ko starting mai laane ke liye 
        //un numbers ka n se modulus le lo ;

        //kisi bhi number ka n se mod lene par answer ( 0 se n-1) ke bich hi aata hai;
        //ab ham kya karenge jis point se array ko rotate karna hai , utne se saare elements 
        //ki index badha denge but jin elements ki indexing array ke bahar ja rahi hai
        // unka n se mod kar lenge tooh apne pass vo index aa jayega jaha humko vo rkhna hai 
        //(n+k)%n=k;


        vector<int> temp(nums.size());//alg array bana liya so overwriting ki problem na aye nums mai 
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];

        }
        //copy temp to nums vector
        nums=temp;
    }
};