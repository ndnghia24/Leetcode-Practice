#include<bits/stdc++.h>
using namespace std;

int s, n;
int w[100001];
int dp[301][10001];

int main()
{
    cin >> s >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int weight = 0; weight <= s; weight++)
        {
            dp[i + 1][weight] = max(dp[i + 1][weight], dp[i][weight]);
            if (weight + w[i + 1] <= s) dp[i + 1][weight + w[i + 1]] = dp[i][weight] + w[i + 1];
            res = max(res, dp[i + 1][weight + w[i]]);
        }
    cout << dp[n][s];

}
