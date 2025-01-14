#include<iostream>
#include<vector>

using namespace std;

vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);//start aur end wale elements ko swap krta rahega 
        //aur start aur end aur aage aur piche lejata rahega 

        s++;
        e--;

    }
    return v;

}
void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;

}

int main(){
    cout<<"enter the no. of elements in the array"<<endl;
    int n;
    vector<int> v;
    cin>>n;//no. of elements
    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        v.push_back(input);

    }

    vector<int> ans=reverse(v);
    cout<<"printing the reverse array"<<endl;
    print(ans);






}