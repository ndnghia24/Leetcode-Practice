#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

struct Node {
    int id;
    int count = 1;
    int res = 0;
};

Node nodes[1001];

void printTree(int node, int parent, string indent = "") {
    cout << indent << "(" << node <<"-" <<nodes[node].count << "-" << nodes[node].res << ")" << "\n";
    for (int v : adj[node]) {
        if (v != parent) {
            printTree(v, node, indent + "  ");
        }
    }
    if (indent == "") cout << "--------------------\n";
}

void DFS1(int node, int parent) {
    for (int v : adj[node]) {
        if (v != parent) {
            DFS1(v, node);
            nodes[node].count += nodes[v].count;
            nodes[node].res += nodes[v].res + nodes[v].count;
        }
    }
    //printTree(node, parent);
}

void DFS2(int node, int parent, int n) {
    for (int v : adj[node]) {
        if (v != parent) {
            nodes[v].res = nodes[node].res - (nodes[v].count) + (n - nodes[v].count);
            DFS2(v, node, n);
            printTree(node, parent);
        }
    }
}

// T(n) = O(n)
void solution2(int n) {
    for (int i = 0; i <= n; i++) nodes[i].count = 1;
    for (int i = 0; i <= n; i++) nodes[i].res = 0;
    DFS1(1, 0);
    //cout << "\nNEXT\n";
    DFS2(1, 0, n);
    
    int width = 0;
    for (int i = 1; i <= n; i++) width += nodes[i].res;

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
    solution2(n);

    system("pause");
    return 0;
}