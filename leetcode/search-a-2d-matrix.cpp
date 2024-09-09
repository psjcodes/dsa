/*
here i treat the matrix as a long list
but could also do 2 binary searches if m and n are large
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int maxRow = matrix.size();
        int maxCol = matrix[0].size();
        int lo = 0;
        int hi = (maxRow * maxCol) - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int r = mid / maxCol;
            int c = mid % maxCol;
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};