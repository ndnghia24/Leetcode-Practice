#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int longestPath(int node, vector<vector<int>>& graph, vector<int>& dp) {
    if (dp[node] != -1) {
        return dp[node];
    }

    int maxLength = 0;
    for (int neighbor : graph[node]) {
        maxLength = max(maxLength, 1 + longestPath(neighbor, graph, dp));
    }

    dp[node] = maxLength;
    return maxLength;
}

int solve(int n, vector<vector<int>>& graph) {
    vector<int> dp(n, -1);
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        if (dp[i] == -1) {
            maxLength = max(maxLength, longestPath(i, graph, dp));
        }
    }

    return maxLength;
}

int main() {
    std::ifstream inputFile("longpath.in");

    int n, m;
    inputFile >> n >> m;
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int start, end;
        inputFile >> start >> end;
        graph[start - 1].push_back(end - 1);
    };

    ofstream outputFile("longpath.out");
    outputFile << solve(n, graph);

    return 0;
}
