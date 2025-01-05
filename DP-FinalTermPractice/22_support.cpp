#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int visited[100005], low[100005], num[100005];
int cnt = 0;
vector<pair<int, int>> bridges;

void dfs(int cur, int parent) {
    visited[cur] = 1;
    num[cur] = low[cur] = cnt++;
    for(int child : adj[cur]) {
        if(child == parent) continue;
        if(visited[child]) {
            low[cur] = min(low[cur], num[child]);
        } else {
            dfs(child, cur);
            low[cur] = min(low[cur], low[child]);
            if(low[child] > num[cur]) {
                bridges.push_back({cur, child});
            }
        }
    }
}

int dfs_count(int v) {
    visited[v] = 1;
    int count = 1;
    for(int u : adj[v]) {
        if(!visited[u]) {
            count += dfs_count(u);
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    for(auto bridge : bridges) {
        int u = bridge.first, v = bridge.second;
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());

        memset(visited, 0, sizeof(visited));
        int componentSize1 = dfs_count(u);
        int componentSize2 = dfs_count(v);
        cout << "Bridge found between " << u << " and " << v << "\n";
        cout << "Component size: " << componentSize1 << "\n";
        cout << "Component size: " << componentSize2 << "\n";

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    system("pause");
    return 0;
}