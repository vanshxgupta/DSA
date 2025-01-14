
//With use of extra space
// #include<iostream>
// #include<vector>
// using namespace std;

// void print(int ans[],int n){
//     for(int i=0;i<n;i++){
//         cout<<ans[i]<<" ";


//     }
// }
// void merge(int arr1[],int n,int arr2[],int m, int arr3[])
// {
//     int i=0;//arr1 mai starting index
//     int j=0;//arr2 mai starting index;
//     int k=0;

//     while(i<n && j<m){
//         if(arr1[i]<=arr2[j]){
//             arr3[k]=arr1[i];
//             k++;

//             i++;
//             //if ke niche wle code ko likhne ka second method;
//             //arr3[k++]=arr1[i++];


//         }
//         else{
//             arr3[k]=arr2[j];
//             k++;

//             j++;


//         }
//     }
    
//     while(i<n){
//         arr3[k]=arr1[i];
//         k++;
//         i++;

//     }
//     while(j<m){
//         arr3[k]=arr2[j];
//         k++;
//         j++;


//     }
    

// }


// int main(){
//     int arr1[5]={1,3,5,7,9};
//     int arr2[3]={2,4,6};

//     int arr3[8]={0};//merge array ko abhi intialise karke 0 rkha hai 

//     merge(arr1,5,arr2,3,arr3);
//     print(arr3,8);
//     return 0;


// }



//Without the use of extra spaces

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //logic ye rhne wal hai ke ham nums1 ke piche se start 
        //karenge aur nums1 aur mums2 ke elements mai jo highest
        // hoga usko nums1 ke end mai rkhte chle jayenge

        int i=m-1;//last non-zero element of nums1
        int j=n-1;//last non zero element of nums2

        int k=m+n-1;//nums1 ka ekdum last element 

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;
                i--;
            }

            else{
                nums1[k]=nums2[j];
                k--;
                j--;

            }

        }
        while(i>=0){
            nums1[k--]=nums1[i--];

        }
        while(j>=0){
            nums1[k--]=nums2[j--];

        }
        
    }//time complexity-O(m+n);
    //space  complexity-O(1);
    
};