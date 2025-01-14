#include<iostream>
using namespace std;

void printcounting(int n){//void kuch return nahi karega '

    for(int i=1;i<=n;i++){
        cout<<i<<endl;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    printcounting(n);
    return 0;

}