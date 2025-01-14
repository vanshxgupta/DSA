//{1,1,2,2,3,3,4,5,5,6,6}
//(1,1)(2,2)(3,3)(single element)(5,5)(6,6)
//indexes-
//(e,o)(e,o)(e,o) (single element)(o,e)(o,e)

//(even,odd)->that means we are on left half and our single element is on right half 
//(odd,even)->that means we are on right half and our single element is on left half 

//single element ki pehchan -> uske aas pass wala , uske barabar nahi hoga

    class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];

        int s=1;
        int e=n-2;//inko 1 se start aur n-2 pe end isliye kiya hai kyunki , vo end cases ham upar le chuke hai pehle hi 
        int mid=s+(e-s)/2;


        while(s<=e){
        //if numms[mid] is the single element:
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid];

        }

        
        //left ya right part elimination ke liye
        

        //if we are of left half
        if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            //eliminate left half
            s=mid+1;
        }  
        else{
            //eliminate right half
            e=mid-1;

        }  
        mid=s+(e-s)/2;

        
    }
    return -1;
    }

};
