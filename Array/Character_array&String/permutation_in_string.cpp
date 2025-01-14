//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m[26]={0};//character array-->jisme hum count store karenge saare characters ka 
        for(char c : s1){
            m[c-'a']++;//jo bhi characters mile unka count badha do map m mai

        }
        int j=0; int i=0;//j aur i dono s2 array ke starting se initialise kara hua hai 

        int totalchar=s1.size();//total characters mai humne s1 ke andr ke le liye

        while(j<s2.size()){//traverse through the full s2 array , seraching for elements of s1
            if(m[s2.at(j++)-'a']-- >0){//agar count >0 aata hai matlab window mai s1 ka koi element present hai
                
                //map mai element mila hai tooh count kam kar do us element ka jo mila hai 

                totalchar--;//ab koi element mila hai tooh total characters mai se usko kam kar dete hai 
                
                

            }

            
            if(totalchar==0) return true;
            //shifting of window ;
            
            if(j-i == s1.size() && m[s2.at(i++)-'a']++ >= 0)//jab j-i s1.size() ke equal ho jaye tooh s2 ke i ko i++ kar do aur count ko bhi badha do 
            
                totalchar++;

        }   
        return false ;
    }
    
};


