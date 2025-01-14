//Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        //logic ye rhne wala hai ki , pure array
        // mai agar sirf ek esa pair hai jisme arr[n-1]>arr[n] hai tooh
        //vo array sorted and rotated array hai, agar ek se jyada hia tooh nahi hai

        //code:
        int count=0;//ek count maintain krte hai pairs ko count krne ke liye
        int n =nums.size();

        for(int i=1;i<n;i++){//idhr i=0 se start nahi kiya kyunki ,i-1 ek negative value de deta 

            if(nums[i]<nums[i-1]){
                count++;

            }
        }
        //ab kyunki i=1 se start kiya tha tooh starting element aur last elemnt ka comparison karna rhe gaya
        //tooh uske liye;
        if(nums[n-1]>nums[0]){
            count++;

        }
            
        
        return count<=1;//jab saare elements same ho jayenge tooh , count 0 hoga ;

    }

        
    
};