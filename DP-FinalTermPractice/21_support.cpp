#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> parent;

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }
}

vector<Edge> find_first_MST(vector<Edge> edges) {
    vector<Edge> mst;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            mst.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    return mst;
}

vector<Edge> find_next_MST(vector<Edge>& currentMST) {
    sort(currentMST.begin(), currentMST.end(), [](Edge a, Edge b) {
        return a.weight > b.weight;
    });

    currentMST.pop_back();

    for (int i = 0; i < parent.size(); i++) {
        make_set(i);
    }

    vector<Edge> nextMST = find_first_MST(currentMST);
    return nextMST;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges;
    vector<vector<Edge>> allMSTs;
    edges.resize(m);
    parent.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    for (int j = 0; j < n; j++) make_set(j);

    // first MST
    vector<Edge> currentMST = find_first_MST(edges);
    allMSTs.push_back(currentMST);

    // Find next
    for (int i = 0; i < k-1; i++) {
        currentMST = find_next_MST(currentMST);
        allMSTs.push_back(currentMST);
    }

    // print all MSTs
    for (vector<Edge> mst : allMSTs) {
        int sum = 0;
        for (Edge e : mst) sum += e.weight;
        cout << sum << " " << mst.size() << endl;
        for (Edge e : mst) {
            cout << e.u + 1 << " " << e.v + 1 << " " << e.weight << endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}