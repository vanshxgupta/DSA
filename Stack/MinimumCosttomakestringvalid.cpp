#include <bits/stdc++.h> 
#include<stack>

int findMinimumCost(string str) {
    int len=str.length();
    if(len%2!=0){//odd length
      return -1;
    }

    //Removal of valid part in string 
    stack<char> s;
    for(int i=0;i<str.length();i++){
      char ch=str[i];

      if(ch=='{')
      s.push(ch);
      else{
        //ch is closed brace


        if (!s.empty() && s.top()=='{'){
          s.pop();
        } else {
          s.push(ch);
        }
      }
    }
      //stack now contains only invalid expression

      int a=0;
      int b=0;
      while(!s.empty()){
        if(s.top()=='{'){
          b++;
        }

        else {
          a++;
        }
        s.pop(); // uss element ka count record kar liya , fir usko pop kara diya
      }

    int ans=(a+1)/2+(b+1)/2;
    return ans;

}