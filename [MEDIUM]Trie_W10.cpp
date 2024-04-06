// https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1101351040/

class Trie {
private:
    Trie* children[26];
    bool isEndOfWord;

public:
    Trie() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;

        isEndOfWord = false;
    }

    void insert(const string& word) {
        Trie* node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        Trie* node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};