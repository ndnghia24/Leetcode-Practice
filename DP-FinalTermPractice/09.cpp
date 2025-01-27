#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                if (i > 0 && s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 2];
            } else {
                if (i > 0 && s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p) << endl;

    system("pause");
    return 0;
}
