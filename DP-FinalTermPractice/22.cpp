#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int visited[100005];

int dfs(int v) {
    visited[v] = 1;
    int count = 1;
    for(int u : adj[v]) {
        if(!visited[u]) {
            count += dfs(u);
        }
    }
    return count;
}

vector<int> countComponents(int n) {
    vector<int> componentSizes;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            componentSizes.push_back(dfs(i));
        }
    }
    return componentSizes;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    for(auto edge : edges) {
        int u = edge.first, v = edge.second;
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());

        memset(visited, 0, sizeof(visited));
        vector<int> componentsAfterRemoval = countComponents(n);

        if(componentsAfterRemoval.size() > 1) {
            cout << "Bridge found between " << u << " and " << v << "\n";
            for(int size : componentsAfterRemoval) {
                cout << "Component size: " << size << "\n";
            }
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    system("pause");
    return 0;
}