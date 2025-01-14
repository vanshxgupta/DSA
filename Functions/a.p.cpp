#include<iostream>
using namespace std;

int apn(int n){
    int ans=(3*n+7);
    return ans;


}
int main(){
    int n;
    cin>>n;
    int nth=apn(n);
    cout<<"nth term of ap is "<<nth<<endl;
    return 0;
}