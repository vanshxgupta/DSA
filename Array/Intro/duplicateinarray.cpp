// // You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

// // For example:

// // Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.


int findDuplicate(vector<int> &arr) 
{
    //is wale question mai bhi ham xor operator
    // ka hi use karne wale hai , xor duplicate elements 
    //ko zero kar deta hai tooh ham [1 se n-1] saare 
    //elements ka xor array mai kkara denge , jo chiz 
    //duplicate hogi uska xor 0 nahi hoga baaki sab 0.
    int ans=0;
    for(int i=0;i<arr.size();i++){//arr.size() array ki size nikalne ke liye hota hai
        ans=ans^arr[i];


    }
    //upar vale code se ye smja ja skta hai ke pura array copy ho chuka hai
    //as xor of any value with zero is that value itself
	for(int i=1;i<arr.size();i++){
        ans=ans^i;
    }
    return ans;
}
