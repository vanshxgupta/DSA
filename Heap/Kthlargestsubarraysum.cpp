#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>>mini;

	int n=arr.size();

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];

			if(mini.size()<k){//first k subarrays ka sum tooh daaldo array mai 
				mini.push(sum);
			}

			else{
				if(sum>mini.top()){//fir ek ek krke aage ke subarrays ka sum check karo ke kya vo mini ke top element se bada hai ? agar hai tooh mini ke us element ko pop krdo aur push karo us sum ko
					mini.pop();
					mini.push(sum);
				}
			}
		}

	}

	return mini.top();


}