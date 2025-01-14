//BinarySearch on answer 

class Solution {

    bool ispsbl(vector<int>& nums, int maxops,int mid){

        //traversing in the whole nums, and finding no. of operations it takes to convert all the elements to mid or less
        int ops=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ops+=(nums[i]/mid);
            if(nums[i]%mid==0){
                ops--;
            }
            if(ops>maxops){
                return false;
            }
        }
        return true;

    }

public:
    int minimumSize(vector<int>& nums, int maxops) {
        
        int n=nums.size();
        int l=1;//bestcase
        int r=*max_element(nums.begin(),nums.end());//worstcase

        int mid=l+(r-l)/2;

        int ans=-1;
        while(l<=r){
            if(ispsbl(nums,maxops,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }

        return ans;
        
    }
};