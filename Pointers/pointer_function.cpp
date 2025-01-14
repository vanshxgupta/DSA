#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;

}
void update(int *p){
    p=p+1;
    cout<<"inside the function "<<p<<endl;//inside the function value update karne par badal rahi hai address ki

}
void update2(int *p){
    *p=*p+1;
    cout<<"inside the func2 "<<*p<<endl;
}

int getsum(int arr[],int n){
    cout<<endl<<"size of:"<<sizeof(arr)<<endl;//ye jo sizeof hai ye arr ka size retur nahi kar rha hai ye pointer ka size return kar raha hai 
    //kyunki jab ham function call krte hai main mai tooh vo array ko nahi bhejta function mai blki uske pointer ko bhejta hai 
    
    //int getsum(int *arr,int n)-->ye bhi same chiz hai 


    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

    }
    return sum;

}


int main(){
    int value=5;
    int *p=&value;

    print(p);

    cout<<"before "<<p<<endl;
    update(p);
    cout<<"after "<<p<<endl;//in dono ke address same hai even after the update statmentt 
    
    cout<<"before2 "<<*p<<endl;
    update2(p);
    cout<<"after2 "<<*p<<endl;//value updation wala function tooh sahi se chl rha hai i.e value update ho rahi hai 

    int arr[5]={2,4,6,8,10};
    cout<<"sum is "<<getsum(arr,5)<<endl;

    //agar pure entire array ka sum na print kara ke sirf uske last 3 ka sum print karana hai tooh
    cout <<"sum of last 3 is "<<getsum(arr+2,3)<<endl;

    //pointer helps in managing a particular part of array

    

    return 0;

}
