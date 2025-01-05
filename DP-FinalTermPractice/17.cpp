#include<bits/stdc++.h>
using namespace std;

int findSmallestMultiple(int n) {
    queue<int> q;

    int cur_num = 1;
    q.push(cur_num);

    while (!q.empty()) {
        cur_num = q.front(); q.pop();

        if (cur_num % n == 0)
            return cur_num;

        q.push(cur_num*10);
        q.push(cur_num*10 + 1);
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << findSmallestMultiple(n) << endl;

    system("pause");
    return 0;
}