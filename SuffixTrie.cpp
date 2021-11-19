#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public :
    unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
    public:
    char endSymbol;
    TrieNode *root;
    
    SuffixTrie(string str) {
        this->endSymbol = '*';
        this->root = new TrieNode();
        this->populateSuffixTrieFrom(str);
    }
// time:    O(N^2)   Space: O(N^2)
    void populateSuffixTrieFrom(string str) {
        for(int i = 0; i < str.length(); ++i) {
            this->insertSubstringStartingAt(i, str);
        }
    }
    
    void insertSubstringStartingAt(int i, string str) {
        TrieNode *node = this->root;
        for(int j = i; j < str.length(); ++j) {
            char letter = str[j];
            if(node->children.find(letter) == node->children.end()) {
                TrieNode *newNode = new TrieNode();
                node->children.insert({letter, newNode});
            }
            node = node->children[letter];
        }
        node->children.insert({this->endSymbol, nullptr});
    }
// time:    O(M)   Space: O(1)
    bool contains(string str) {
        TrieNode *node = this->root;
        for(char letter : str) {
            if(node->children.find(letter) == node->children.end()) {
                return false;
            }
            node = node->children[letter];
        }
        return node->children.find(this->endSymbol) != node->children.end();
    }
};

int main() {
//    SuffixTrie st = *new SuffixTrie("babc");
//    cout << st.contains("bc") << endl;
    SuffixTrie *st = new SuffixTrie("babc");
    cout << st->contains("bc") << endl;
}
// suffix substrings only
