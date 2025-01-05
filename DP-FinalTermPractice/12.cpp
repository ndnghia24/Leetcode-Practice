#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    for (int i = 0; i < n/2; i++) {
        if (sqrt(i)*sqrt(i) == i && sqrt(n-i)*sqrt(n-i) == n-i) {
            int x = 1, y = 2;
            int deltaX = sqrt(i), deltaY = sqrt(n-i);

            cout << x << " " << y << endl;
            x += deltaX;
            y += deltaY;
            cout << x << " " << y << endl;
            x += deltaY;
            y -= deltaX;
            cout << x << " " << y << endl;
            x -= deltaX;
            y -= deltaY;
            cout << x << " " << y << endl;

            return;
        }
    }
    cout << "Impossible" << endl;
}

int main()
{
    int n;
    cin >> n;
    solve(n);

    system("pause");
    return 0;
}