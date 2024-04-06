#include<iostream>
using namespace std;

long long n;
long long dp[100][3];
bool check[100][3];

long long cal(int num, int pre)
{
    if (num > n) return 1;
    if (check[num][pre] == true) return dp[num][pre];
    check[num][pre] = true;

    dp[num][pre] += cal(num + 1, 0) + cal(num + 1, 2);
    if (pre != 0) dp[num][pre] += cal(num + 1, 1);

    return dp[num][pre];
}

int main()

{
    cin >> n;
    cout << cal(1, 1);
}
