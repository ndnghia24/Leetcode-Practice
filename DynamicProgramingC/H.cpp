#include<bits/stdc++.h>
using namespace std;

long long n, dp[2001][2001];
bool check[2001][2001];

long long cal(int num, int sum)
{
    if (num + sum > n) return 0;
    if (num + sum == n) return 1;
    if (check[num][sum] == true) return dp[num][sum];
    check[num][sum] = true;

    dp[num][sum] = cal(num + 1, sum) + cal(num * 2, sum + num);
    return dp[num][sum];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::freopen("peacefulsets.in", "r", stdin);
    std::freopen("peacefulsets.out", "w", stdout);

    cin >> n;
    cout << cal(1, 0);
}
