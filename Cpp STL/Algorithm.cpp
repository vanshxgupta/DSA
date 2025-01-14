#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6 -  "<<binary_search(v.begin(),v.end(),6)<<endl;//check if element is present or not
    cout<<"lower bound"<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;//lowerbound wala iterator return karega aur hamne usme se v.begin() minus karke lower bound ki value nikaal li 
    cout<<"upper bound"<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;//upar jese hi upper bound bhi nikal liya

     int a=3;
     int b=5;
     cout<<"max "<<max(a,b);
     cout<<"min "<<min(a,b);

     swap(a,b);
     cout<<endl<<"a "<<a<<endl;

     string abcd="abcd";
     reverse(abcd.begin(),abcd.end());
     cout<<"string"<<abcd<<endl;
     cout<<"before rotate"<<endl;
     for(int i:v){
        cout<<i<<" ";

     }
     cout<<endl;

     rotate(v.begin(),v.begin()+1,v.end());
     cout<<"after rotate"<<endl;

     for(int i:v){
        cout<<i<<" ";

     }
     cout<<endl;

    cout<<"after sort"<<endl;
     sort(v.begin(),v.end());
     for(int i:v){
        cout<<i<<" ";

     }

    



}