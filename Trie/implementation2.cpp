#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isterminal;
    int prefixCount; // how many words pass through this node
    int endCount;    // how many words end at this node

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
        isterminal = false;
        prefixCount = 0;
        endCount = 0;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) {
                crawler->children[ind] = new TrieNode();
            }
            crawler = crawler->children[ind];
            crawler->prefixCount++;   // prefix count increases
        }
        crawler->isterminal = true;
        crawler->endCount++; // mark ending
    }

    bool search(string word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) return false;
            crawler = crawler->children[ind];
        }
        return (crawler != nullptr && crawler->endCount > 0);
    }

    bool startswithword(string word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) return false;
            crawler = crawler->children[ind];
        }
        return true;
    }

    int countWordsEqualTo(string word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) return 0;
            crawler = crawler->children[ind];
        }
        return crawler->endCount;  // return number of times word ends here
    }

    int countWordsStartingWith(string word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) return 0;
            crawler = crawler->children[ind];
        }
        return crawler->prefixCount; // how many words pass this prefix
    }

    void erase(string word) {
        if (!search(word)) return; // word not present

        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            TrieNode* next = crawler->children[ind];
            next->prefixCount--; // decrease prefix count
            crawler = next;
        }
        crawler->endCount--; // decrease end count
        if (crawler->endCount == 0) crawler->isterminal = false;
    }
};

int main() {
    Trie* t = new Trie();

    t->insert("abc");
    t->insert("bcd");
    t->insert("bcd");
    t->insert("d");

    cout << t->startswithword("bc") << endl;   // 1
    cout << t->startswithword("c") << endl;    // 0
    cout << t->search("b") << endl;            // 0
    cout << t->search("bcd") << endl;          // 1
    cout << t->countWordsEqualTo("bcd") << endl; // 2
    cout << t->countWordsStartingWith("b") << endl; // 2 (bcd, bcd)

    string word = "bcd";
    t->erase(word);
    cout << t->countWordsEqualTo("bcd") << endl; // 1 after erase
}
