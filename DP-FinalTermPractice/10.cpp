#include <bits/stdc++.h>
using namespace std;

void maximalSquare(vector<vector<char>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    int maxSquareSide = 0;
    vector<vector<int>> dp(numRows + 1, vector<int>(numCols + 1, 0));

    for(int row = numRows-1; row >= 0; row--) {
        for(int col = numCols-1; col >= 0; col--) {
            if(matrix[row][col] == '1') {
                int squareSide = 1 + min({dp[row + 1][col], dp[row][col + 1], dp[row + 1][col + 1]});
                dp[row][col] = squareSide;
                maxSquareSide = max(maxSquareSide, squareSide);
            }
        }
    }
    cout <<  maxSquareSide * maxSquareSide << endl;
}

int main() {
    int numRows, numCols;
    cin >> numRows >> numCols;
    vector<vector<char>> matrix(numRows, vector<char>(numCols));
    for (int row = 0; row < numRows; row++) {
        for(int col = 0; col < numCols; col++) {
            cin >> matrix[row][col];
        }
    }
    maximalSquare(matrix);

    system("pause");
    return 0;
}