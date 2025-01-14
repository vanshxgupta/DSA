#include<iostream>
using namespace std;

void printarray(int arr[],int size){//iss function mai hane int arr declare kara hua hai tooh 
                                    //sirf vahi array print kar skte hai
    cout<<"printing the array"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl<<"printing done "<<endl;
}

int main(){
    int first[10]={2,7};
    printarray(first,10);

    return 0;
}
//other types of array decalaration
char ch[5];
double firstdouble[5];
float firstfloat[6];
bool firstbool[9];
