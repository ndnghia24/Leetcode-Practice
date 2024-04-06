// https://leetcode.com/problems/word-break/submissions/1091893658/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool* check = new bool[n+1] {false};

        check[0] = true;

        for (int i = 1; i <= n ;i++)
        {
            for (string word : wordDict)
            {
                if (i - word.size() <= n && s.substr(i - word.size(), word.size()) == word)
                {
                    check[i] = check[i - word.size()];
                    if (check[i])
                        break;
                }
            }
        }

        return check[n];
    }
};