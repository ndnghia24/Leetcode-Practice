#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int solve(int n, int m, std::vector<std::vector<int>>& f) {
    if (n <= 0 || m <= 0) {
        return 0;
    }

    if (n == 1 && m == 1) {
        return 1;
    }

    if (f[n][m] != -1) {
        return f[n][m];
    }

    f[n][m] = solve(n - 2, m - 1, f) + solve(n - 1, m - 2, f);

    return f[n][m];
}

int main()
{
    std::ifstream inputFile("knight.in");

    int n, m;
    inputFile >> n >> m;
    vector<vector<int>> f(n+1, vector<int>(m+1, -1));

    ofstream outputFile("knight.out");
    outputFile << solve(n, m, f);

    return 0;
}