class Solution {
  public:
    long long solve(vector<int>& bt) {
       
       sort(bt.begin(),bt.end());
       int t=0;
       int wttime=0;
       
       for(int i=0;i<bt.size();i++){
           wttime+=t;
            t+=bt[i];
           
       }
       return(wttime/bt.size());
       
    }
};
