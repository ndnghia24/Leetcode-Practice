// https://leetcode.com/problems/search-a-2d-matrix/submissions/1073327282/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m*n - 1;
        int i, j;

        while (start <= end) {
            int mid = (start + end) / 2;
            i = mid / n;
            j = mid % n;

            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target) 
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};