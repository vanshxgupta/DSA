#include<iostream>
using namespace std;

void update(int arr[],int n){
    cout<<endl<<"enside the function"<<endl;
    //updating arrays first array
    arr[0]=120;//sirf idhr updation ka statement dala hai par dono values update kyu hui?
    //arrays jo hai vo values jaisa nahi hai , values mai function ko change karne par original 
    //change nahi hota tha kyunki vo ek copy bana leta tha par arrays mai vo apni copy nahi
    // banata vo khudka address de deta hai jiske kaaran value function mai update kare par 
    //main mai bhi update ho jaati hai 
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
    cout<<"going back to main function"<<endl;

}
int main(){
    int arr[3]={1,2,3};
    update(arr,3);
    //printing the array
    cout<<endl<<"printing in main function"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;
}