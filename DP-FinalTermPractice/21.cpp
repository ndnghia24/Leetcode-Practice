#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> parent;
vector<Edge> edges;
vector<vector<Edge>> allMSTs;

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

// Brute force all MSTs
void backtrack(int edgeIndex, vector<Edge>& currentMST, int totalWeight) {
    if (currentMST.size() == parent.size() - 1) {
        allMSTs.push_back(currentMST);
        return;
    }

    if (edgeIndex == edges.size()) {
        return;
    }

    Edge e = edges[edgeIndex];

    if (find_set(e.u) != find_set(e.v)) {
        currentMST.push_back(e);
        union_sets(e.u, e.v);
        backtrack(edgeIndex + 1, currentMST, totalWeight + e.weight);
        currentMST.pop_back();
        make_set(e.u);
        make_set(e.v);
    }

    backtrack(edgeIndex + 1, currentMST, totalWeight);
}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(m);
    parent.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; // subtract 1 here
        edges[i].v--; // subtract 1 here
    }

    sort(edges.begin(), edges.end());

    for (int j = 0; j < n; j++) make_set(j);

    vector<Edge> currentMST;
    backtrack(0, currentMST, 0);

    sort(allMSTs.begin(), allMSTs.end(), [](vector<Edge>& a, vector<Edge>& b) {
        int sumA = 0, sumB = 0;
        for (Edge e : a) sumA += e.weight;
        for (Edge e : b) sumB += e.weight;
        if (sumA != sumB) {
            return sumA < sumB;
        }
        return false;
    });

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