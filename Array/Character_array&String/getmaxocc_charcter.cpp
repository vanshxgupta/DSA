#include<iostream>
#include<string>

using namespace std;
char getMaxOccuringChar(string str)
    
    
    {   int arr[26]={0};//ek array bana diya jisme har character ka count store hoga
    
        //create an array of count of numbers;
        
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            int number=0;
            if(ch>'a' && ch<='z'){
                number=ch-'a';//Har character ke liye pehle ek number define kar diya 0 se 25 tak 
                
                
            }
            
            arr[number]++;
            
        }
        int maxi=-1;int ans=0;
        
        for(int i=0;i<26;i++){
            if(maxi<arr[i]){
                ans=i;//jo bhi number maximum baar ayega vo isme aa jayega 
                maxi=arr[i];
                
            }
        }
        char finalans='a'+ans;//yaha pe vapis number ko charcter mai convert kar diya 
        return finalans;
        
        
    
    }
 int main(){

    string s;
    cin>>s;

    //for input for string with space and tab use cin.getline(str,len);
    cout<<getMaxOccuringChar(s)<<endl;
    return 0;



 }