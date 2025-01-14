#include<iostream>

#include<map>
using namespace std;


map<int,int> mapinsert(int arr[],int n){
      map<int,int> mp;
      //insert arr[i] as key and i as value
      for(int i=0;i<n;i++){
        //mp[key]= value
        mp[arr[i]]=i;
      }
      return mp;
}

      void mapdisplay(map<int,int> mp){
        //print every key and value pair in a new line 

       // map<int,int>::iterator it;//ye use karna hai agar baar baar tooh ham auto it bhi use kar skte hai 


        for(auto it=mp.begin();it!=mp.end();it++){//Pure map ko traverse karne mai humko nlogn time lag raha hota hai 
          cout<<it->first<<" "<<it->second<<endl;        
          }
        
      }

      void maperase(map<int,int>&mp,int x){
        //write the if and else condition to erase x from map

        auto it =mp.find(x);
        if(it!=mp.end()){
          mp.erase(it);

        }
        else{
          cout<<"not found";
        }
      }

int main(){
      map<int,string>m;
      m[1]="tarun ";
      m[3]="bkl";
      m[2]="is";
      //in above 1,2,3 shows key and tarun is bkl are values;

      m.insert({0,"mrcd"});


      for(auto i:m){//auto mai auto
        cout<<i.first<<" "<<i.second<<endl;//first se key print hogi sirf , second mai value print hogi 


      }
      cout<<endl<<endl;
    
      auto it =m.find(2);
      cout<<(*it).first<<endl;//isse vo 2 ko find krke de dega 

      for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;//isse vo 2 ko find krke uske aage walo ko bhi de dega jab tak end nahi hota
      }

      int arr[5]={1,2,3,4,5};
      map<int,int> result = mapinsert(arr,5); // Store the returned value from function

      mapdisplay(result); // Call the function to display the result

 
}