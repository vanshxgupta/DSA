class TrieNode{
    public:
    TrieNode*children[26];
    bool isterminal;
};

TrieNode* getnode(){
    TrieNode*root=new TrieNode();
    for(int i=0;i<26;i++){
        root->children[i]=NULL;
    }
    root->isterminal=false;
    return root;
}

class Trie{
    public:
    TrieNode*root=getnode();
    
    void insert(string s){
        int n=s.size();
        TrieNode*crawler=root;
        for(int i=0;i<n;i++){
            int idx = s[i]-'a'; 
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getnode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isterminal=true;
    }
    

    bool startswith(string s){
        TrieNode*crawler=root;
        
        for(int i=0;i<s.size();i++){
            int idx = s[i]-'a';
            if(crawler->children[idx]==NULL) return false;
            crawler=crawler->children[idx];
            if(!crawler->isterminal && i != s.size()-1) return false; //checking if every prefix is present or not , if the a string is prefix, and its every characters isterminal should be true 
        }
        return true;   
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        int n=words.size();
        Trie*t=new Trie();
        
        for(int i=0;i<n;i++){
            t->insert(words[i]);
        }
        
        string maxi="";
        for(int i=0;i<n;i++){
            int m=words[i].size();
            if(m>=maxi.size()){
                if(t->startswith(words[i])){  
                    if(m>maxi.size()){
                        maxi=words[i];
                    }
                    else if(m==maxi.size() && words[i]<maxi){
                        maxi=words[i];
                    }
                }
            }
        }
        
        return maxi;
        
    }
};