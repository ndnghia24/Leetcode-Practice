// https://leetcode.com/problems/longest-common-subsequence/submissions/1090602260/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int** f = new int*[m+1];

        for (int i = 0; i < m+1; i++)
            f[i] = new int[n+1] {0};

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text2[i-1] == text1[j-1])
                    f[i][j] = f[i-1][j-1] + 1;
                else
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }

        return f[m][n];
    }
};