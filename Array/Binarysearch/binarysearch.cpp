#include<iostream>
using namespace std;
int binarysearch(int arr[],int size, int key){
    int start=0;
    int end=size-1;

    //int mid=(start+end)/2;//yaha ek dikkat hai ke , start aur end ko add karne ke baad agar vo integer ki range se bahar nikal jaye tooh?
    //isliye iski jghe ham niche likha use karenge ,ab start aur end tooh indexes hai tooh vo negative tooh ho ni skta isliye usme bhi problem nahi ayegi 
    int mid=start+((end-start)/2);
    while(start<=end){
        if(arr[mid]==key){
            return mid;

        }
        //go to right wala part
        if(key>arr[mid]){
            start= (mid+1);


        }
        else{//jab key <arr[mid] hai tabh
            end=mid-1;

        }
        mid=start+((end-start)/2);
    }
    return -1;

}

int main(){
    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};
    int evenindex=binarysearch(even,6,18);
    cout<<"index of 18 is "<<evenindex<<endl;

    int oddindex=binarysearch(odd,5,20);

    cout<<"index of 20 is "<<oddindex<<endl;
    return 0;


}