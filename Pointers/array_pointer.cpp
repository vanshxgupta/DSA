#include<iostream>
using namespace std;

int main(){
    int arr[10]={2,3,5,78,57};

    cout<<"address of first memory block is "<<arr<<endl;//array ka pehle block ka address array ka naam hota hai
    cout<<"address of first memory block is "<<&arr[0]<<endl;

    //upar dono statment same address print karegi;

    cout<<*arr<<endl;//will print value at first dabba 
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;

    int i=3;
    cout<<i[arr]<<endl;

    int temp[10]={1,2};
    cout<<sizeof(temp)<<endl;//isme puri array ki size aa jayegi
    cout<<"first element ki size "<<sizeof(*temp)<<endl;


    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;//isme sirf ek memory block  ka adress stores hai
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;



    //Note-Symbol table ka content cannot be changed!
    cout<<ptr<<endl;
    cout<<&ptr<<endl;


    int brr[10]={1,2,3,4,5};
   // brr=brr+1;//this will generate an array

    int *ptr2=&brr[0];
    cout<<ptr2<<endl;
    ptr2=ptr2 +1;//ye error nahi dega, ye ek block se aage badha dega 

    cout<<ptr2<<endl;




    return 0;






}

