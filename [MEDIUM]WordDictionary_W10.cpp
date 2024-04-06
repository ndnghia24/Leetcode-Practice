// https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/1101357332/

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }

    bool searchHelper(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchHelper(node->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int chIndex = ch - 'a';
            if (node->children[chIndex]) {
                return searchHelper(node->children[chIndex], word, index + 1);
            } else {
                return false;
            }
        }
    }
};