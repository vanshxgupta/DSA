//least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.-->(minimizing the maximum )

class Solution {
    bool ispsbl(vector<int>& weights, int days,int mid){
        int n=weights.size();
        int nowday=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(weights[i]>mid){
                return false;
            }
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }
            else{
                //start newday
                sum=weights[i];
                nowday++;     
            }   
        }
        if(nowday>days){
            return false;
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        //best psbl scenario se ke , humko least weight mai kaam ho jaaye i.e
        int l=*min(weights.begin(),weights.end());
        //worst psbl scenario hoga ke , sum of saare weight ho, tooh r=sum of all
        int r=accumulate(weights.begin(),weights.end(),0);

        int mid=l+(r-l)/2;
        int ans=r;
        while(l<=r){
            if(ispsbl(weights,days,mid)){
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