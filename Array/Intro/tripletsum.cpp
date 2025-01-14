// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.



// #include <bits/stdc++.h> 
// vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	
// 	set<vector<int> > st;//ek set bana liya hai

// 	for(int i=0;i<arr.size();i++){
// 		for(int j=i+1;j<arr.size();j++){
// 			for(int k=j+1;j<arr.size();k++){
// 				if(arr[i]+arr[j]+arr[k]==K){
// 					vector<int< temp={num[i],num[j],num[k]};
// 					sort(temp.begin(),temp.end());//
// 					st.insert(temp);//this line ensures that every time unique elements are there 


				

					
// 				}
// 			}
// 		}
// 	}
// 	vector< vector<int> >ans(st.begin(),st.end());
// 	return ans;

	
// }



