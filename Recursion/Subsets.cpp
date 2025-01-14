//print all the subsets of a given array

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


//Using include exclude method

void solve(vector<int>nums,vector<int> output,int index,vector<vector<int>> &ans){

    //base case
    if(index>=nums.size()){
        ans.push_back(output);
        return;

    }
    
    //exclude
    solve(nums,output,index+1,ans);//index ko aage badha do aur  kuch mat karo exclude ho jayega

    //include

    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);

}


vector<vector<int>> subsets(vector<int>&nums){
    vector<vector<int>>ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;

}

int main(){
    vector<int> nums={2,4,5};
    vector<vector<int>> result=subsets(nums);

    for (auto subset : result) {//result kke saare subset mai iterate karega
        cout << "{";
        for (int num : subset) {//subset mai haar num ko iterate karega 
            cout << num << " ";
        }
        cout << "}" << endl; 
    }
}



//Using bits

// void solv(vector<int> a, vector<vector<int>> &ans){
//         int n = a.size();
//         int max = pow(2,n);
//         for(int i=0; i<max; i++){
//             int k = i;
//             int c = 0;
//             vector<int> x;//output wala array 
//             while(k>0){
//                 if(k&1){
//                     x.push_back(a[c]);
//                 }
//                 k = k/2;
//                 c++;
//             }
//             ans.push_back(x);
//         }
//     }
//     vector<vector<int> > subsets(vector<int>& A)
//     {
//         //code here
//         vector<vector<int> > ans;
//         solv(A,ans);
//         sort(ans.begin(), ans.end());
//         return ans;
//     }

// int main(){
//     vector<int> nums={2,4,5};
//     vector<vector<int>> result=subsets(nums);

//     for (auto subset : result) {//result kke saare subset mai iterate karega
//         cout << "{";
//         for (int num : subset) {//subset mai haar num ko iterate karega 
//             cout << num << " ";
//         }
//         cout << "}" << endl; 
//     }
// }