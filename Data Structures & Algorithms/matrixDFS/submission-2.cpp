class Solution 
{
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int& m, int& n)
    {
        if (r == m - 1 && c == n - 1)
        {
            return 1;
        }

        if (r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == 1)
        {
            return 0;
        }

        grid[r][c] = 1;
        int res = 0;
        res += dfs(grid, r + 1, c, m, n);
        res += dfs(grid, r - 1, c, m, n);
        res += dfs(grid, r, c + 1, m, n);
        res += dfs(grid, r, c - 1, m, n);
        grid[r][c] = 0;

        return res;
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid.front().size();
        if (grid[m - 1][n - 1] == 1) return 0;

        return dfs(grid, 0, 0, m, n);
    }
};
