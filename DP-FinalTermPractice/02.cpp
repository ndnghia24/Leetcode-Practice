#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e3 + 5;
bool prime[MAX];
int g[MAX];

void sieve(int n) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void precompute(int n) {
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            if (prime[j] && prime[2*i - j]) {
                g[i]++;
            }
        }
        g[i] += g[i - 1];
    }
}

int main() {
    int n;
    cin >> n;
    sieve(n);

    
    precompute(n);
    cout << g[n];

    system("pause");
    return 0;
}