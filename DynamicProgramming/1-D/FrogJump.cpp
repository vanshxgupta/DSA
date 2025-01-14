//using memoization
//t.c-->o(n)
//s.c-->o(2n)



// int f(int ind,vector<int> &heights,vector<int>&dp){

//     if(ind==0) return 0;

//     if(dp[ind]!=-1){//step 3
//         return dp[ind];
//     }
//     int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
//     int right=INT_MAX;//isko int_max isliye rakh rahe hai kyunki right wala case tabh hi chalega jab ind>1 hoga , tooh jab right wala case nahi chalega tabh min(rigt,left) ka answer left hona chahiye , jo ki tabh hi hoga jab right bahut bada ho , tooh int_max rakh diya usko 
//     if(ind>1){
//         right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
//     }

//     return dp[ind]=min(left,right);//step 2
// }

// int frogJump(int n, vector<int> &heights)
// {
//     vector<int>dp(n,-1);//step 1
//     return f(n-1,heights,dp);

// }




//USING TABULATION
//t.c-->o(n)
//s.c-->o(n)
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int>dp(n,0);
//     dp[0]=0;
//     for(int i=1;i<n;i++){
//         int fs=dp[i-1]+abs(heights[i]-heights[i-1]);//first step(fs)
        
//         int ss=INT_MAX;//isko int_max isliye rakh rahe hai kyunki ss wala case tabh hi chalega jab i>1 hoga , tooh jab ss wala case nahi chalega tabh min(ss,fs) ka answer fs hona chahiye , jo ki tabh hi hoga jab ss bahut bada ho , tooh int_max rakh diya usko 
//         if(i>1){
//         ss=dp[i-2]+abs(heights[i]-heights[i-2]);//second step(ss)
//         }

//         dp[i]=min(fs,ss);
//     }


//     return dp[n-1];

// }





//USING TABULATION(SPACE OPTIMISED)
//t.c-->o(n)
//s.c-->o(1)
int frogJump(int n, vector<int> &heights)
{
    
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);//first step(fs)
        
        int ss=INT_MAX;//isko int_max isliye rakh rahe hai kyunki ss wala case tabh hi chalega jab i>1 hoga , tooh jab ss wala case nahi chalega tabh min(ss,fs) ka answer fs hona chahiye , jo ki tabh hi hoga jab ss bahut bada ho , tooh int_max rakh diya usko 
        if(i>1){
        ss=prev2+abs(heights[i]-heights[i-2]);//second step(ss)
        }

        int curri=min(fs,ss);
        prev2=prev;
        prev=curri;
    }


    return prev;

}