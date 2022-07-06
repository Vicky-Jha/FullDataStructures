class Trie {
    public:
    Trie* childrens[26] = {};
    bool isWord;
    vector<string> words;
    Trie* root = this;

    Trie() {
        this->isWord = false;
    }

    Trie(vector<string>& words) {
        this->words = words;
        this->isWord = false;
        this->populateTrieNodes(words);
    }

    void populateTrieNodes(vector<string>& words) {
        for(string& w : words) {
            Trie* curr = this;
            for(char& c : w) {
                this->insertNode(curr, c);
            }
            curr->isWord = true;
        }
    }

    void insertNode(Trie* &curr, char c) {
        if(curr->childrens[c - 'a'] == nullptr) {
            curr->childrens[c - 'a'] = new Trie();
        }
        curr = curr->childrens[c - 'a'];
    }

    bool contains(string word) {
        Trie* curr = this;
        for(char& c : word) {
            if(curr->childrens[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->childrens[c - 'a'];
        }

        return curr->isWord;
    }

};
    
int main() {
  vector<string> words = {"oath", "oat", "apple", "appie"};
  Trie *t = new Trie(words);
  if(t->contains("oath")) {
    cout << "contains" << endl;
  }
  return 0;
}
