// Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but 
//instead, be stored in the input character array chars. Note that
// group lengths that are 10 or longer will be split into multiple characters in chars.

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansindex=0;//ye hamne isliye rakhna kyunki humko 
        //extra space ka use na krte hue usi char mai store kar ske
        int n=chars.size();

        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;//jab tak elements same hai tabh tak j ko badhate raho
            }
            //loop ye bahar ham tabh hi aa skte hai jab ;
            //ya tooh string khatam ho gyi ho ya element bada gaya ho 


            chars[ansindex++]=chars[i];//old char store karlo
            int count=j-i;
            if(count>1){
                string cnt=to_string(count);//coverting counting into single digit and saving as ans
                for(char ch:cnt){
                    chars[ansindex++]=ch;

                }

            }
            //moving to different character
            i=j;


            
           
        }
         return ansindex;

        
    }
};