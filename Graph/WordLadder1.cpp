//t.c-->o(n*wordlength*26*logn)
//s.c-->o(2n)
class Solution {
public:
    int wordLadderLength(string startword, string targetword, vector<string>& wordList) {
        
    
    queue<pair<string,int>>q;
    q.push({startword,1});
    set<string>st(wordList.begin(),wordList.end());
    st.erase(startword);//removed the startword from the set becuase we have pushed the startword in the queue
    
    
    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        
        //check kya hum target word pe puch gye hai?
        if(word==targetword)  return steps;
        
        
        
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a' ; ch<='z';ch++){
                word[i]=ch;//replacing the values one by one 
                
                if(st.find(word)!=st.end()){//if the word exists in the set
                q.push({word,steps+1});
                st.erase(word);
                }
                
            }
            
            word[i]=original;
        }
        
    }
        
        
        
    }
};
