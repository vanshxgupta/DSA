// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.


class Solution { 
 
private: 
bool isvalid(char  ch){ 
    if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){ 
 
        return 1; 
 
    } 
    else{ 
        return 0; 
    } 
 
} 
 
char tolowercase(char ch){ 
    if((ch>='a' && ch<='z')||(ch >= '0' && ch <= '9')){ 
        return ch; 
 
    } 
    else{ 
        char temp=ch-'A'+'a' ; 
        return temp; 
 
 
    } 
     
} 
bool checkpalindrome(string s){ 
    int st=0; 
    int e=s.length()-1; 
 
    while(st<=e){
        if(tolowercase(s[st])!=tolowercase(s[e])){ 
            return 0; 
        } 
        else{ 
            st++; 
            e--; 
 
        } 
 
    } 
    return 1; 
 
} 
 
 
 
 
public: 
    bool isPalindrome(string s) { 
        string temp="";//declared a empty string  
 
        int st=0; 
        int e=s.size()-1; 
        for(int j=0;j<s.length();j++){ 
            //sabse pehle faltu characters ko hatao 
            if(isvalid(s[j])){ 
                temp.push_back(s[j]); 
 
            } 
        } 
            //iske baad apne pass temp string ban gyi hai jisme sirf valid charcters hai 
            //ab saare characters ko lowercase kardo; 
        for(int j=0;j<temp.length();j++){ 
            temp[j]=tolowercase(temp[j]); 
             
 
        } 
            //now check for palindrome; 
        return checkpalindrome(temp); 
 
 
             
         
              
    } 
 
};
