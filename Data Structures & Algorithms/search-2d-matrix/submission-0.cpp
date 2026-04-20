class Solution {
public:
    pair<int, int> getIndices(int i, int& n) {
        int row = i / n;
        int col = i % n;
        

        return {row, col};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        int lo = 0, hi = m * n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            auto [r, c] = getIndices(mid, n);
            int val = matrix[r][c];
            if (val == target) {
                return true;
            }
            if (val > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return false;
    }
};
