// You are given two numbers 'A' and 'B' in the form of two
// arrays (A[] and B[]) of lengths 'N' and 'M' respectively,
// where each array element represents a digit. You need to 
//find the sum of these two numbers and return this sum in the
// form of an array.

#include <bits/stdc++.h> 
vector<int> reverse(vector<int> v){
	int s=0;
	int e=v.size()-1;
	while(s<e){
		swap(v[s++],v[e--]);
		
	}
	return v;

}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	//addition tooh piche se start krte hai isliiye , i aur j ko piche se initilaise kar diya

	int i=n-1;

	int j=m-1;
	vector<int> ans;

	int carry=0;

	while(i>=0 && j>=0){
		int val1=a[i];
		int val2=b[j];
		int sum=val1+val2+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
		j--;
		//ye vo wala part khatam ho gya jya dono arrays overlap kar rahe the 
	}
	//ab 
	//first case : arr a bada hai 
	while(i>=0){
		int sum=a[i]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
		

	}
	//now second case: arr b bada hai 
	while(j>=0){
		int sum= b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;

	}
	//third case:jaha carry ho raha hai 
	while(carry!=0){
		int sum= carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);

	}
	//abhi tak apn piche se start krke sum kar
	//rhe the par humne uska sum aage se print karaya hai
	//, tooh jo hamara answer hai vo reversed ayega 


	return reverse(ans);





}