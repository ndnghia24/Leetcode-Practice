// https://leetcode.com/problems/palindromic-substrings/submissions/1085857061/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int> (n, 0));

        int count = 0;

        for (int i = 0; i < n; i++) 
        {
            f[i][i] = 1;
            count++;
        }

        for (int i = 0; i < n-1; i++)
        {
            if (s[i] == s[i+1]) 
            {
                f[i][i+1] = 1;
                count++;
            }
        }

        for (int length = 3; length <= n; length++) 
        {
            for (int i = 0; i + length - 1 < n; i++)
            {
                int j = i + length - 1;

                if (f[i+1][j-1] == 1 && s[i] == s[j]) 
                {
                    f[i][j] = 1;
                    count++;
                }
            }
        }

        return count;
    }
};