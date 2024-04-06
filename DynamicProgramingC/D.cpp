#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <cstdint>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);

    int matrix[8][8];
    bool visited[8][8];
    int dist[8][8];
    queue<pair<int,int>> q;

    for (int i = 0; i < 8; i++) {
        fill(visited[i], visited[i] + 8, false);
        fill(dist[i], dist[i] + 8, INT32_MAX);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cin >> matrix[i][j];
        }
    }

    q.push(make_pair(7, 0));
    dist[7][0] = 0;

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (i == 7 && j == 0) {
                continue;
            }

            int p1 = INT32_MAX;
            int p2 = INT32_MAX;
            int p3 = INT32_MAX;

            if (i + 1 < 8 && j - 1 >= 0) {
                p1 = dist[i + 1][j - 1];
            }
            if (i + 1 < 8) {
                p2 = dist[i + 1][j];
            }
            if (j - 1 >= 0) {
                p3 = dist[i][j-1];
            }

            dist[i][j] = min(p1, min(p2, p3)) + matrix[i][j];
        }
    }

    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dist[0][7] << endl;
}