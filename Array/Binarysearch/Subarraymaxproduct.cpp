//SUBARRAY WITH MAXIMUM PRODUCT
//Given an array ‘Arr’ that has ‘N’ elements. You have to find the subarray of ‘Arr’ that has the largest product. You must return the product of the subarray with the maximum product.


//Brute force
// #include<iostream>
// using namespace std;
// int maxi(int arr[],int n){
//     int maxi=-2000;
//     for(int i=0;i<n;i++){
//         int pro=1;
//         for(int j=i;j<n;j++){
//             pro=pro*arr[j];
//             maxi=max(maxi,pro);
//         }
        
//     }
//     return maxi;
// }
// int main(){
//     int arr[5]={2,-1,4,0,7};
//     cout<<maxi(arr,5);
    

// }



//OPTIMAL APPROACH

#include<vector>

int subarrayWithMaxProduct(vector<int> &arr){
	int pre=1;//prefix
	int sub=1;//suffix
	int maxi=-2000;
	int n=arr.size();

	for(int i=0;i<n;i++){

		if(pre==0) pre=1;//agar array ke bich mai 0 aa jata 
		//hai tooh usko lene ka matlab tooh hai nahi isliye 
		//usko hatake 1 se initiase kar diya fir se jisse second sub array start ho jayegi 
		if(sub==0) sub=1;

		pre=pre*arr[i];
		sub=sub*arr[n-i-1];//isme piche se chlayenge na 
		
		
		maxi=max(maxi,max(pre,sub));

	}
	return maxi;

}