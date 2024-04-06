#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> dp(1000001, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= 180; ++i) {
        int x = i * (i + 1) * (i + 2) / 6;
        for (int j = x; j <= 1000000; ++j) {
            dp[j] = min(dp[j], dp[j - x] + 1);
        }
    }

    while (t--) {
        int m;
        cin >> m;
        cout << dp[m] << "\n";
    }

    return 0;
}