//minimizing the maximum-->bs on answer type ques
class Solution {
    bool ispsbl(int n,vector<int>&quantities,int mid){
        int stores=0;
        int m=quantities.size();

        for(int i=0;i<m;i++){
            if(quantities[i]%mid==0){
                stores+=(quantities[i]/mid);
            }
            else{
                stores+=(quantities[i]/mid)+1;
            }
        }
        if(stores>n){
            return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();

        //minimise the maximum number of products,
        //best case ->minimum ek-ek product mai stores ka kaam ho jaaye
        //worst case->ek store ko max_element chale jaaye (matlab jis type mai )
        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());
        
        int ans=r;
//minimizing the x implies minimizing the mid
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ispsbl(n,quantities,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};