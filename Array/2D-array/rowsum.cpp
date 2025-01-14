 #include<iostream>
 #include<limits.h>
 using namespace std;
//to print row wise sum;
void printrowsum(int arr[][3],int row, int col){
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<3;col++){
            sum+=arr[row][col];

        }
        cout<<sum<<" ";

    }
    cout<<endl;
}
int largestrowsum(int arr[][3],int row ,int col){
    int maxi=INT_MIN;
    int rowindex=-1;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col =0;col<3;col++){
            sum+=arr[row][col];

        }
        if(sum>maxi){
            maxi=sum;
            rowindex=row;
        }
        

    }
    cout<<"the maximum sum is "<<maxi<<endl;
    return rowindex;
}

 int main(){
    int arr[3][3];

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[row][col];

        }
    }
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[row][col]<<" ";

        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"printing sum"<<endl;
    printrowsum(arr,3,3);
    cout<<"largest row sum is at index "<<largestrowsum<<endl;
    


 }