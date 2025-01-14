
class TrieNode{
    public:
        TrieNode*children[26];
        bool isterminal;
};

TrieNode*getnode(){
        TrieNode*newnode=new TrieNode();
        newnode->isterminal=false;
        newnode->count=0;
        for(int i=0;i<26;i++){
            newnode->children[i]=NULL;
        }
        return newnode;
    }

class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=getnode();
    }

    void insert(string word){
        TrieNode*crawler=root;

        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int ind=ch-'a';
            
            if(crawler->children[ind]==NULL){
                crawler->children[ind]=getnode();
            }
            crawler=crawler->children[ind];
        }
        crawler->isterminal=true;
    }

    bool search(string word){
        TrieNode*crawler=root;

        for(int i=0;i<word.length();i++){
             char ch=word[i];
            int ind=ch-'a';
            
            if(crawler->children[ind]==NULL){
                return false;
            }
            crawler=crawler->children[ind];
        }
        if(crawler!=NULL && crawler->isterminal==true){
            return true;
        }
        return false;
    }

    bool startsWith(string prefix){
        TrieNode*crawler=root;
        int i=0;
        for(i=0;i<prefix.length();i++){
             char ch=prefix[i];
            int ind=ch-'a';
            
            if(crawler->children[ind]==NULL){
                return false;
            }
            crawler=crawler->children[ind];
        }
        if(i==prefix.length()){
            return true;
        }
        return false;
    }

        //remove word
        
};