// Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



// There are ‘m’ number of students, and the task is to allocate all the books to the students.



// Allocate books in such a way that:

// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.


// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



// If the allocation of books is not possible, return -1.



bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];//agar sum of pages mid se 
            //kam hai tooh pagesum update karo loop chalao aur ,
            // nahi tooh dusra student le lo
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int findPages(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    if(m>n){
        return -1;//this is an edge case which is missed,
        //the number of students cannot be greater than number of books


    }
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;//agar vo possible hoga tooh uska ans
            // mai daal do abhi ke liye aur aage continue karo

            e = mid - 1;//ab agar mid possible hai tooh uske baad
             //wale bhi possible hnge hi isliyeend ko pche le aao taaki 
             //mid ke pehle wale bhi check kar ske kyunki hamko minimum chahiye 
        }
        else
        {
            s = mid + 1;//agar possible nahi hai toooh start ko mid ke aage lelo
        }
        mid = s + (e-s)/2;
    }
    return ans;
}