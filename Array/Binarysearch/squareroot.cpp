//Sqrt of a number using binary search(time complexity O(logn))
 #include<iostream>
 using namespace std;
 
 
 long long int floorSqrt(int n)
{
    int s=0;
    int e=n-1;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;

    while(s<=e){

        long long int square = mid*mid;
        if(square==n){
            return ans=mid;

        }
        else if(square<n){
            ans=mid;
            s=mid+1;

        }
        else{
            e=mid-1;


        }
        mid=s+(e-s)/2;


    }
    return ans;

    
}
int main(){
    int n;
    cin>>n;
    int final=floorSqrt(n);
    cout<<final;

}
