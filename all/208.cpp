#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    vector<Trie*> childs;
    bool isEnd;
    Trie() {
        childs.resize(26);
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (int i = 0; i < word.length(); i++) {
            int n = word[i] - 'a';
            if(node->childs[n] == nullptr) {
                node->childs[n] = new Trie();
            }
            node = node->childs[n];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (int i = 0; i < word.length(); i++) {
            int n = word[i] - 'a';
            if(node->childs[n] == nullptr) return false;
            node = node->childs[n]; 
        }
        if(node->isEnd == true) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (int i = 0; i < prefix.length(); i++) {
            int n = prefix[i] - 'a';
            if(node->childs[n] == nullptr) return false;
            node = node->childs[n]; 
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // 返回 true
    cout << trie->search("app") << endl;     // 返回 false
    cout << trie->startsWith("app") << endl; // 返回 true
    trie->insert("app");
    cout << trie->search("app") << endl;     // 返回 true
}