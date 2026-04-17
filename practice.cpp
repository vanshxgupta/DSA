#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isterminal;
};

TrieNode* getnode(){
    TrieNode* node=new TrieNode();
    node->isterminal=false;
    
    for(int i=0;i<26;i++){
        node->children[i]=NULL;
    }
    return node;
}

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root=getnode();
    }

    void insert(const string &word){
        int sizi=word.size();
        TrieNode* crawler=root;

        for(int i=0;i<sizi;i++){
            int ind=word[i]-'a';
            if(crawler->children[ind]==NULL){//if it does not exist then make the new node
                crawler->children[ind]=getnode();
            }
            crawler=crawler->children[ind];
        }
        crawler->isterminal=true;

    }

    bool search(const string &word){
        int sizi=word.size();
        TrieNode* crawler=root;

        for(int i=0;i<sizi;i++){
            int ind=word[i]-'a';
            if(crawler->children[ind]==NULL){
                return false;
            }
            else
            crawler=crawler->children[ind];
        }
        if(crawler!=NULL && crawler->isterminal==true){
            return true;
        }
        else{
            return false;
        }

    }

    bool startswithprefix(const string &word){//prefix
        int sizi=word.size();
        TrieNode* crawler=root;

        for(int i=0;i<sizi;i++){
            int ind=word[i]-'a';
            if(crawler->children[ind]==NULL){
                return false;
            }
            else
            crawler=crawler->children[ind];
        }
        return true;
    }

};


int main(){
    Trie t;
    t.insert("vansh");
    t.insert("gupta");
    t.insert("value");
    bool ans=(t.startswithprefix("vas"));
    cout<<ans<<endl;
}