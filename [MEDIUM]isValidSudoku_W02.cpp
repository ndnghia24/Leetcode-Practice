// https://leetcode.com/problems/valid-sudoku/submissions/1057991145/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][10];
        int cols[9][10];
        int blocks[9][10];

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(blocks, 0, sizeof(blocks));

        int intVal;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                    
                intVal = board[i][j] - '0';

                if (++rows[i][intVal] > 1 || ++cols[j][intVal] > 1 || ++blocks[j/3 + (i/3)*3][intVal] > 1)
                    return false;
            }
        }
        return true;
    }
};