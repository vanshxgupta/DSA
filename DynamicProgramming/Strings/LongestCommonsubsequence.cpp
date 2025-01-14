//Memoization

#include<bits/stdc++.h>

// int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
//     if(i<0 || j<0 ) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==t[j]) return dp[i][j]= 1+f(i-1,j-1,s,t,dp);
//     return dp[i][j]= max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
// }


// int lcs(string s, string t)
// {
// 	int n=s.size();
//     int m=t.size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return f(n-1,m-1,s,t,dp);
    
// }




//Tabulation
// int lcs(string s, string t)
// {
// 	int n=s.size();
//     int m=t.size();
//     //shifted by one(because previosly we are handling negative case by doing (<0),
//     // but here , we cannot have negative indexes in a matrix, so shifting it by one
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
//     //base case
//     for(int i=0;i<=n;i++){//we have shifted , so now , if there is index 0 , then we will return 0, (idhr ka index 0 , recursion wale code ka <0 tha )
//         dp[i][0]=0;
//     }
//     for(int j=0;j<=n;j++){
//         dp[0][j]=0;
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
            
//             //shifting kiya hai , so string mai i-1 , aur j-1 lenge , kyunki hamne tooh matrix 
//             //mai shifting ki hai , string mai  nahi isliye string wale ko tooh kam krna padega na 
//             if(s[i-1]==t[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];//agar match ho gye tooh dono ke index kam karo 
//             }
//             else{//nahi tooh ek ek ke index kam kro , aur unme se max answer nikalo
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

//             }

//         }
//     }
//     return dp[n][m];
    
// }



//Space Optimisation
int lcs(string s, string t)
{
	int n=s.size();
    int m=t.size();
    //shifted by one(because previosly we are handling negative case by doing (<0),
    // but here , we cannot have negative indexes in a matrix, so shifting it by one
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    
    //base case
    for(int i=0;i<=n;i++){//we have shifted , so now , if there is index 0 , then we will return 0, (idhr ka index 0 , recursion wale code ka <0 tha )
        curr[0]=0;
    }
    for(int j=0;j<=n;j++){
        curr[j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            //shifting kiya hai , so string mai i-1 , aur j-1 lenge , kyunki hamne tooh matrix 
            //mai shifting ki hai , string mai  nahi isliye string wale ko tooh kam krna padega na 
            if(s[i-1]==t[j-1]){
                curr[j]=1+prev[j-1];//agar match ho gye tooh dono ke index kam karo
            } else { // nahi tooh ek ek ke index kam kro , aur unme se max
                     // answer nikalo
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return prev[m];
    
}



