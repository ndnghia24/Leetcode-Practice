// https://leetcode.com/problems/word-search-ii/submissions/1101347584/

class Solution {
    class TrieNode {
    public:
        TrieNode* children[26];
        string word;
        bool isCheck;

        TrieNode() {
            word = "";
            isCheck = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }

        void addWord(const string& word) {
            TrieNode* pCur = this;

            for (char c : word) {
                if (pCur->children[c - 'a'] == nullptr) {
                    pCur->children[c - 'a'] = new TrieNode();
                }
                pCur = pCur->children[c - 'a'];
            }
            pCur->word = word;
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) 
    {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    TrieNode* buildTrie(vector<string> &words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) 
        {
            root->addWord(word);
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode* pCur, vector<string> &result) 
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }

        char c = board[i][j];
        if (c == '*' || pCur->children[c - 'a'] == nullptr)
            return;

        pCur = pCur->children[c - 'a'];

        if (!pCur->isCheck && pCur->word != "")
        {
            result.push_back(pCur->word);
            pCur->isCheck = true;
        }

        board[i][j] = '*';
        dfs(board, i - 1, j, pCur, result);
        dfs(board, i, j - 1, pCur, result);
        dfs(board, i + 1, j, pCur, result);
        dfs(board, i, j + 1, pCur, result);
        board[i][j] = c;
    }
};