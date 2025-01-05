#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

void DFS(int node, int parent, int depth, int &width) {
    for (int v : adj[node]) {
        if (v != parent) {
            DFS(v, node, depth + 1, width);
            width += depth + 1;
        }
    }
}

// T(n) = O(n^2)
void solution1(int n) {
    int width = 0;
    for (int i = 1; i <= n; i++) {
        DFS(i, 0, 0, width);
    }
    cout << width / 2 << endl;
}


int Count[1001];
int res[1001];

void DFS1(int node, int parent) {
    cout << "DFS1: " << node << " " << parent << endl;
    for (int i = 1; i <= 5; i++) cout << Count[i] << " ";
    cout << endl;
    for (int i = 1; i <= 5; i++) cout << res[i] << " ";
    cout << endl;
    for (int v : adj[node]) {
        if (v != parent) {
            DFS1(v, node);
            Count[node] += Count[v];
            res[node] += res[v] + Count[v];
        }
    }
}

void DFS2(int node, int parent, int n) {
    for (int v : adj[node]) {
        if (v != parent) {
            res[v] = res[node] - Count[v] + n - Count[v];
            DFS2(v, node, n);
        }
    }
}

// T(n) = O(n)
void solution2(int n) {
    for (int i = 0; i <= n; i++) Count[i] = 1;
    for (int i = 0; i <= n; i++) res[i] = 0;
    DFS1(1, 0);
    DFS2(1, 0, n);
    
    int width = 0;
    for (int i = 1; i <= n; i++) width += res[i];

    cout << width / 2 << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution1(n);
    solution2(n);

    system("pause");
    return 0;
}