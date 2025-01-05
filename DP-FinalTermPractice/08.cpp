#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

void solveNQueens(vector<vector<string>> &res, vector<string> &board, int col, int n) {
    if (col == n) {
        res.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 'Q';
            solveNQueens(res, board, col + 1, n);
            board[i][col] = '.';
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> res;
    solveNQueens(res, board, 0, n);
    cout << res.size() << endl;
    for (auto &b : res) {
        for (auto &row : b)
            cout << row << endl;
        cout << endl;
    }

    system("pause");
    return 0;
}