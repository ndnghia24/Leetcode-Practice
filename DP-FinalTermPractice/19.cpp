#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int N = 1e5 + 1;
int n;
long long T, a[N], sum[N];

long long calc(long long n) {
    return n * (n + 1) / 2;
}

bool check(long long x) {
    long long minCost = INF;
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        r = max(r, i);
        while (l < i && a[l + 1] <= (x + (i - l))) l++;
        while (r < n && a[r + 1] > (x + (r - i + 1))) r++;
        long long curCost = -x * (r - l + 1) + sum[r] - sum[l - 1] - calc(i - l) - calc(r - i);
        minCost = min(minCost, curCost);
    }
    return minCost <= T;
}


// O(nlogn) : Code của a lộc
void solutionVIP() {
    long long low = -INF / n, high = *min_element(a + 1, a + n + 1);
    
    long long ans = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << '\n';
}


int main()
{
    cin >> n >> T;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    solutionVIP();
    
    system("pause");
    return 0;
}