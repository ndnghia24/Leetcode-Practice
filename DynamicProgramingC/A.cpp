#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int solve(int n, std::vector<int>& cost) {
    if (n <= 1) {
        return (n == 1) ? cost[0] : 0;
    }

    std::vector<int> maxSum(n + 1);
    maxSum[0] = 0;
    maxSum[1] = cost[0];

    for (int i = 2; i <= n; i++) {
        maxSum[i] = std::max(maxSum[i - 1], maxSum[i - 2]) + cost[i - 1];
    }

    return maxSum[n];
}

int main()
{
    std::ifstream inputFile("ladder.in");

    int n;
    inputFile >> n;

    std::vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> cost[i];
    }

    ofstream outputFile("ladder.out");
    outputFile << solve(n, cost);

    return 0;
}