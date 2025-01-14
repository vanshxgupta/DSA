// Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(string digits,string output,int index,vector<string> &ans,string mapping[]){

    //base case
    if(index>=digits.length()){
        ans.push_back(output);
        return ;
    }

    int number=digits[index]-'0';//string ko typecaste krke integer bana rahe hai 
    //tooh jo digit[index] dega vo ek string hogi aur usko typecaste kiya tooh ascii value return karga 
    //us number ki , isliye hamne '0' se minus kiya ,ab uski vajhe se dono value kaatpit ke number de degi jo chahiye
   
    string value=mapping[number];//jo number aya usko mapping se match karenge tooh value aa jayegi ek kon kon se 

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        

        //backtrack
        output.pop_back();//ye kyu krna hai ? --> example"36"-->isme 3 ki mapping mai def hai tooh d ayega fir index 6 pe ayega aur fir dj,dk,dl ayega , 
        //ab jab ham e ke saath nikalne jayenge tooh vaha d pehle se padha hoga aur fir chalenge tooh dej,dek,del ayega par humo ye nahi chahye isliye d ko opo krna padega 


    }
}

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){//agar empty string hogi 
            return ans;
        }
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;  
    }


int main(){
    string str="23";
    vector<string> ans= letterCombinations(str);
    for(auto i:ans){
        for(auto str:i){
            cout<<str;
        }
        cout<<endl;
    }

   
}