class TrieNode {
        public:
        unordered_map<char, TrieNode*> children;
    };
    
class Trie {
    public: 
    char endSymbol;
    TrieNode* root;
    vector<string> words;

    Trie(vector<string>& words) {
        this->endSymbol = '*';
        this->root = new TrieNode();
        this->words = words;
        this->populateTrieFrom(words);
    } 

    void populateTrieFrom(vector<string>& words) {
        for(string& w : words) { // O(words.length)
            TrieNode* node = this->root;
            for(char& c : w) { // O(max(w1,w2,w3...wn).length) ~ O(10) ~ O(1)
                this->insertIntoTrie(c, node); // O(1)
            }
            node->children.insert({this->endSymbol, nullptr});
        }
    }

    void insertIntoTrie(char& c, TrieNode* &node) { // O(1)
        if(node->children.find(c) == node->children.end()) {
            node->children.insert({c, new TrieNode()});
        } 
        node = node->children[c];
    }

    bool contains(string str) { // made this just to check if trie works properly
        TrieNode* node = this->root;
        for(char& s : str) {
            if(node->children.find(s) != node->children.end()) {
                node = node->children[s];
            } else {
                return false;
            }
        }
        return node->children.find(this->endSymbol) != node->children.end();
    }

};
    
int main() {
  vector<string> words = {"oath", "oat", "apple", "appie"};
  Trie *t = new Trie(words);
 return 0; 
}
