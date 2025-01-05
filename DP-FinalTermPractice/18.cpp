#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> a, vector<int> dest) {
    queue<pair<vector<int>, int>> q;
    map<vector<int>, bool> visited;
    q.push({a, 0});
    visited[a] = true;

    while (!q.empty()) {
        pair<vector<int>, int> cur = q.front(); q.pop();
        vector<int> cur_vect = cur.first;
        int cur_depth = cur.second;

        if (cur_vect == dest) {
            return cur_depth;
        }
        for (int i = 2; i <= cur_vect.size(); i++) {
            reverse(cur_vect.begin(), cur_vect.begin() + i);
            if (!visited[cur_vect]) {
                q.push({cur_vect, cur_depth + 1});
                visited[cur_vect] = true;
            }
            reverse(cur_vect.begin(), cur_vect.begin() + i);
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dest(a);
    sort(dest.begin(), dest.end());

    cout << bfs(a, dest) << endl;
    system("pause");
    return 0;
}