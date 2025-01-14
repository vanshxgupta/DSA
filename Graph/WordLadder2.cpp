//THIS SOLUTION ONLY WORKS IN GFG(THE BELOW SOLUTION GIVES TLE ON LEETCODE BECAUSE WE ARE FORMING ALL THE TRANFORMATION WHICH TAKES SO MUCH TIME , FOR LEETCODE WE HAVE ANOTHER SOLUTION ON LEETCODE) 


//t.c-->vary from example to example and finding time complexity for this code is next to impossible
//s.c-->o(4n)
class Solution {
public:
    vector<vector<string>> findSequences(string beginword, string endword, vector<string>& wordlist) {
    
    unordered_set<string>st(wordlist.begin(),wordlist.end());
    queue<vector<string>>q;
    
    q.push({beginword});
    
    vector<string> usedonlevel; // A vector defined to store the words being currently used
        // on a level during BFS.(used of level help karega humko ye batane mai ke jin jin words ko level mai use kar liya hai ab unko set se hata do ) 
    usedonlevel.push_back(beginword);
    
    int level=0;//initally the level is 0(matlab koi level nahi thi )
    
    vector<vector<string>>ans;//we have to return the answer in this form
    
    
    st.erase(beginword);
    
    while(!q.empty()){
        vector<string> vec=q.front();
        q.pop();
        
        //erase all words that has been used in the previous levels to transform
        if(vec.size()>level){//agar vector ki size level se jyada ho gyi hai matlab jo level khatam ho chuki hai , level khatam hone par do kaam krne hai 
        //ek tooh humko level++ krna hai aur dusra us level ke elements ko  worlist(set) mai se hatana hai taaki vapis search na kre unme 
            level++;
            for(auto i:usedonlevel){
                st.erase(i);
            }
            usedonlevel.clear();//level khatam ho gyi tooh usko clear krdo 
        }
        
        
        
        string word=vec.back();//ab word ko utha ,jo ki hoga vector ka last element , tooh piche se lelo
        //aur ab us element ke koi koi character ko change krke search kro set mai ke kya vo present hai ?
        //agar present hai tooh daaldo usko vector mai aur us vector ko queue mai daaldo
        
        
        
        //storing the final answers
        if(word==endword){
            //the first sequence where we reached end
            if(ans.size()==0){
                ans.push_back(vec);
            }
            //to store the multiple sequences(agar aur dusre vector sequences ki size bhi jo pehle vector sequence dala hai ans mai uske jitni tooh usko bhi vector mai daala do )
            else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
            
            
        }
        
        
        //doing tranformations 
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;//ith character ko c se replace krdo aur serach kro ke set mai , esa word hai koi ?
                if(st.count(word)>0){//or we can also use st.find(word)!=st.end()
                    vec.push_back(word);
                    q.push(vec);
                    
                    //mark as visited on the level
                    usedonlevel.push_back(word);
                    vec.pop_back();//pop_back statement isliye daali hai kyunki jab humko single level mai jyada words milte hai tooh unko alg alg store krte hai , tooh next element same level kka store krne ke liye jo prev element same level mai dala hai vo niklna padega
                    
                }
                
            }
            
            word[i]=original;
            
        }
        
        
    }
    
    return ans;
    
    



    }
};