// https://leetcode.com/problems/longest-palindromic-substring/submissions/1085854140/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int> (n, 0));

        int i_res = 0;
        int j_res = 0;

        for (int i = 0; i < n; i++)
            f[i][i] = 1;

        for (int i = 0; i < n-1; i++)
            if (s[i] == s[i+1]) 
            {
                f[i][i+1] = 1;
                i_res = i;
                j_res = i+1;
            }

        for (int length = 3; length <= n; length++) 
        {
            for (int i = 0; i + length - 1 < n; i++)
            {
                int j = i + length - 1;

                if (f[i+1][j-1] == 1 && s[i] == s[j]) 
                {
                    f[i][j] = 1;
                    i_res = i;
                    j_res = j;
                }
            }
        }

        return s.substr(i_res, j_res - i_res + 1);
    }
};